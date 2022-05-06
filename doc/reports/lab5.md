#### Lab5 **扩展 Nachos 的文件系统**

---

#### 1. 结果演示

- **nachos [-d f] –ap Unix_filename Nachos_filename**

  > 该命令的功能是将一个 UNIX 文件（unix_filename）附加到一个 Nachos 文件（nachos_filename）的后面，目的是用来测试当我们在一个 Nachos 的文件尾部追加数据后，文件大小是否会增加；

  	`rm -rf DISK && make clean && make && nachos -f && nachos -cp test/small small && hexdump -C DISK` ：

![image-20220408152517147](https://s2.loli.net/2022/04/08/RSUH7zl5siCYVKf.png)

​	  `nachos -ap test/small small && hexdump -C DISK` ：

![](https://s2.loli.net/2022/04/08/O25bvT4xtFues8z.png)

​		可以发现，small 文件在原有文件的基础上进行了扩展，文件大小由 `0x54` 变成了 `0xa8`，是原来的 2 倍。

 	  `rm -rf DISK && make clean && make && nachos -f && nachos -cp test/empty empty && hexdump -C DISK` :

![image-20220408160332337](https://s2.loli.net/2022/04/08/K1SIfPoD7dOCzHs.png)

​		可以发现，挂载空文件的操作也得到了实现。



- **nachos [-d f] –hap Unix_filename Nachos_filename**

  > 该命令的功能是从一个 Nachos 文件（nachos_filename）的中间（文件大小的 1/2）位置开始，将一个 UNIX 文件（unix_filename）写入到该 Nachos 文件中。如果这个UNIX 文件大于 Nachos 文件的一半，则该目录执行后，新的 Nachos 文件的大小将增加。 

​	  `rm -rf DISK && make clean && make && nachos -f && nachos -cp test/medium medium && hexdump -C DISK` ：

![image-20220408155929700](https://s2.loli.net/2022/04/08/XDEugTqpzo2FB4J.png)

​	  `nachos -hap test/big medium && hexdump -C DISK` :

![image-20220408155955494](https://s2.loli.net/2022/04/08/lb1SLTfv9WRgh5P.png)

​		可以发现，该操作将 big 文件从 medium 文件的中间往后覆盖写入，并且文件长度实现了扩展。

- **nachos [-d f] –nap Nachos_filename1 Nachos_filename1**

  > 该命令的功能是将一个 Nachos 文件（unix_filename1）附加到一个 Nachos 文件(nachos_filename2)的后面，目的是用来测试当我们在一个 Nachos 的文件尾部写入数据时，文件大小是否会增加；

​	 `rm -rf DISK && make clean && make && nachos -f && nachos -cp test/small small && nachos -cp test/medium medium && hexdump -C DISK` ：

![image-20220408161135754](https://s2.loli.net/2022/04/08/tcLp8q3WoGYV2Af.png)

​	  `nachos -nap small medium && hexdump -C DISK ` :

![image-20220408161154244](https://s2.loli.net/2022/04/08/JUj1cHGLaSKMPWk.png)

可以发现，small 文件已经挂载到了 medium 文件的尾部，文件大小得到了扩充。



#### 2. 实现过程

1. 当传入参数为 `-ap` 时，主程序中实际调用了函数 `Append` ，理解该函数的实现逻辑，需要扩充以下点：

   ~~~
   (1) Append() 函数调用了OpenFile::Write()，OpenFile::Write()又调用了OpenFile::WriteAt()，因此考虑如何修改OpenFile::WriteAt()成员函数以实现；
   (2) 在 Append() 函数中实现 while 读写逻辑，每次从读文件中获取特定大小的数据，循环写入写文件中。
   ~~~


   （1）Append() 函数中 whlie 循环的实现：

   ~~~
   buffer = new char[TransferSize];
       while ((amountRead = fread(buffer, sizeof(char), TransferSize, fp)) > 0) 
       {
           int result;
           result = openFile->Write(buffer, amountRead);  //**********//
           // 文件过大，或空闲磁盘块不足
           if (result < 0)
           {
               printf("---ERROR---\n");
               printf("Insufficient Disk Space, or File is Too Big\n");
               printf("Writing Terminated\n");
               printf("----------\n");
               break;
           }
           ASSERT(result == amountRead);
           // 每次写操作都从上次写入的数据之后开始进行
           start += amountRead;
       }
       delete [] buffer;
   ~~~

   （2）openFile->Write(buffer, amountRead) 函数的实现：

   ~~~
   int OpenFile::Write(char *into, int numBytes)
   {
      int result = WriteAt(into, numBytes, seekPosition);  //**********//
      seekPosition += result;
      return result;
   }
   ~~~

   （3）WriteAt(into, numBytes, seekPosition) 函数的实现：

   ~~~
   int OpenFile::WriteAt(char *from, int numBytes, int position)
   {
       int fileLength = hdr->FileLength();
       int i, firstSector, lastSector, numSectors;
       bool firstAligned, lastAligned;
       char *buf;
   
       if ((numBytes <= 0) || (position > fileLength))
       	return -1;
       // 如果条件 (position + numBytes) > fileLength 成立，说明文件需要扩展
       if ((position + numBytes) > fileLength) 
       {
       	// 计算文件需要扩展的大小
           int incrementBytes = (position + numBytes) - fileLength;
           // 取出位示图文件（自己实现）
           BitMap *freeBitMap = fileSystem-> getBitMap();//**********//
           bool hdrRet;
           // 扩充文件，修改位示图（自己实现）
           hdrRet = hdr->Allocate(freeBitMap, fileLength, incrementBytes);//**********//
           if ( !hdrRet ) // Insuficient Disk Space, or File is Too Big
               return -1;
           // 修改位示图，写入磁盘（自己实现）
           fileSystem-> setBitMap(freeBitMap);//**********//
       }
       
   	// ......
   }
   ~~~

   （4）getBitMap 和 setBitMap 函数的实现：

   - 当文件需要扩展时，获取空闲块位示图文件（BitMap *freeBitMap = fileSystem-> getBitMap()），然后判断是否需要为写入数据新分配扇区，如果需要为扩展数据新分配扇区，就修改新分配扇区在位示图对应位的状态（hdr->Allocate(freeBitMap, fileLength, incrementBytes)），然后写回硬盘原来的扇区（fileSystem-> setBitMap(freeBitMap)）；其中，getBitMap()与setBitMap()完成从硬盘读取位示图文件与将位示图文件写回硬盘操作；

   - getBitMap()调用了../userprog/bitmap.cc中BitMap类的FetchFrom(OpenFile *)，setBitMap()调用了BitMap类的WriteBack(OpenFile *)完成。

   - fileSystem中的FileSystem类没有定义实现getBitMap()与setBitMap()，需要你自己实现；

   - 直观上，类FileSystem在其构造函数中，维护了两个一直处于打开状态的文件句柄OpenFile* freeMapFile与OpenFile* directoryFile;directoryFile，freeMapFile = new OpenFile(FreeMapSector)，File* directoryFile;directoryFile = new OpenFile(DirectorySector)，一个是硬盘DISK上的位示图文件，一个DISK上的目录文件（参见./filesys/filesys.h与./filesys/filesys.cc），我们可以直接使用它们实现对DISK上位示图文件与目录文件的读与写操作（BitMap类中位示图的读写函数FetchFrom(OpenFile *)与WriteBack(OpenFile *)就是使用freeMapFile实现的），由于这两个OpenFile对象是FileSystem类的私有变量，因此需要在FileSystem类中定义实现getBitMap()与setBitMap()；

   ~~~
   // 返回位示图
   BitMap* FileSystem::getBitMap()
   {
       BitMap* freeBitMap = new BitMap(NumSectors);
       freeBitMap->FetchFrom(freeMapFile);
       return freeBitMap;
   }
   
   // 把修改后的位示图写回磁盘
   void FileSystem::setBitMap(BitMap* freeMap)
   {
       freeMap->WriteBack(freeMapFile);
   }
   ~~~

   （5）Allocate(freeBitMap, fileLength, incrementBytes) 函数的实现：

   > 该函数需要在文件 `filehdr.cc` 中重载函数，而不是在原有函数的基础上修改
   >
   > 如果原来文件最后一个扇区的剩余空间足以容纳要写入的numBytes个字节，就不需要为写入操作分配新的扇区，在原文件的最后一个扇区中写入数据即可；但要修改文件头中文件大小属性；文件写操作结束后将文件头写回硬盘原来的扇区中；
   >
   > 如果原来文件最后一个扇区的剩余空间太小，无法容纳要写入的numBytes个字节，就需要为写入操作分配新的扇区，在原文件的最后一个扇区写满后，将剩余数据写入新分配的扇区中;
   >
   > 这里要修改文件头中文件大小属性，同时要将新分配的扇区在空闲块管理位示图中对应的位置1（已分配），然后将位示图写回硬盘原来的扇区中；文件写操作结束后将文件头写回硬盘原来的扇区中；

   ~~~
   bool FileHeader::Allocate(BitMap *freeMap, int fileSize, int incrementBytes)
   {
       if (numSectors > 30)
           return false;
   
       // 在一个空文件后追加数据
       if (fileSize == 0 && incrementBytes > 0)
       {
           // 空闲扇区不够
           if (freeMap->NumClear() < 1)
               return false;
           // 为添加数据先分配一个空闲磁盘块，并更新文件头信息
           dataSectors[0] = freeMap->Find();
           numSectors = 1;
           numBytes = 0;
       }
   
       numBytes = fileSize;
   
       // 原文件最后一个扇区数据块偏移量
       int offset = numBytes % SectorSize;
       // 最后一个扇区空闲数据块, 例如1个扇区100块, offset=39, freeSize=61
       int freeSize = SectorSize - offset;
       int newSectorBytes = incrementBytes - freeSize;
   
       // 最后一个扇区块剩余空间足以容纳追加数据，不需要分配新的扇区块
       if (newSectorBytes <= 0)
       {
           numBytes += incrementBytes;
           return true;
       }
   
       // 最后一个扇区的剩余空间不足以容纳追加数据，需要重新分配块
       // 新增的扇区块数
       int moreSectors = divRoundUp(newSectorBytes, SectorSize);
       // 文件超出30个磁盘块或磁盘无足够的空闲块
       if (numSectors + moreSectors > 30 || freeMap->NumClear() < moreSectors)
           return false;
   
       // 没有超出文件大小限制，且磁盘有足够的空闲块
       for (int i = numSectors; i < numSectors + moreSectors; i++)
           dataSectors[i] = freeMap->Find();
       // 更新后的文件大小
       numBytes += incrementBytes;
       // 更新后的文件扇区数
       numSectors += moreSectors;
   
       return TRUE;
   }
   ~~~

   - FileHeader::Allocate(BitMap *freeMap, int fileSize)函数根据文件大小为文件分配所需的所有扇区块，并在位示图中标记所分配的扇区块，设置头文件三元组< numBytes, numSectors, dataSectors[30] >，我们可以重载FileHeader::Allocate(BitMap *freeMap, int fileSize, int incrementBytes)，以根据要扩展的数据大小incrementBytes判断是否需要分配新的扇区块，并更新文件头三元组。

   

2. 当传入参数为 `-nap` 时，主程序中实际调用了函数 `NAppend` ，理解该函数的实现逻辑，分析fstest.cc中的NAppend()函数可以看出，NAppend()函数也是调用OpenFile::Write()实现文件的写操作，我们也知道，OpenFile::Write()通过调用OpenFile::WriteAt()实现，我们已经修改了OpenFile::WriteAt()，实现了从文件的任何位置开始写入数据；因此，只需在fstest.cc中的NAppend()函数中与Append()做同样的修改即可。

   ~~~
   void NAppend(char *from, char *to)
   {
       // ......
       
       buffer = new char[TransferSize];
       openFileFrom->Seek(0);
       while ( (amountRead = openFileFrom->Read(buffer, TransferSize)) > 0) 
       {
           int result;
   		result = openFileTo->Write(buffer, amountRead);
   
   		ASSERT(result == amountRead);
   		start += amountRead;
       }
       delete [] buffer;
   	
   	// ......
   }
   ~~~

   

// exception.cc 
//	Entry point into the Nachos kernel from user programs.
//	There are two kinds of things that can cause control to
//	transfer back to here from user code:
//
//	syscall -- The user code explicitly requests to call a procedure
//	in the Nachos kernel.  Right now, the only function we support is
//	"Halt".
//
//	exceptions -- The user code does something that the CPU can't handle.
//	For instance, accessing memory that doesn't exist, arithmetic errors,
//	etc.  
//
//	Interrupts (which can also cause control to transfer from user
//	code into the Nachos kernel) are handled elsewhere.
//
// For now, this only handles the Halt() system call.
// Everything else core dumps.
//
// Copyright (c) 1992-1993 The Regents of the University of California.
// All rights reserved.  See copyright.h for copyright notice and limitation 
// of liability and disclaimer of warranty provisions.

#include "copyright.h"
#include "system.h"
#include "syscall.h"

//----------------------------------------------------------------------
// ExceptionHandler
// 	Entry point into the Nachos kernel.  Called when a user program
//	is executing, and either does a syscall, or generates an addressing
//	or arithmetic exception.
//
// 	For system calls, the following is the calling convention:
//
// 	system call code -- r2
//		arg1 -- r4
//		arg2 -- r5
//		arg3 -- r6
//		arg4 -- r7
//
//	The result of the system call, if any, must be put back into r2. 
//
// And don't forget to increment the pc before returning. (Or else you'll
// loop making the same system call forever!
//
//	"which" is the kind of exception.  The list of possible exceptions 
//	are in machine.h.
//----------------------------------------------------------------------

void  AdvancePC() {
    machine->WriteRegister(PCReg, machine->ReadRegister(PCReg) + 4);
    machine->WriteRegister(NextPCReg, machine->ReadRegister(NextPCReg) + 4);
}


void
ExceptionHandler(ExceptionType which)
{
    int type = machine->ReadRegister(2);

    if (which == SyscallException) {
        switch (type) {
            case SC_Halt: {
                DEBUG('a', "Shutdown, initiated by user program.\n");
   	            interrupt->Halt();
   	            break;
            }
            case SC_Exit: {

                break;
            }
            case SC_Exec: {
                char filename[128];
                // 通过读取$4寄存器获得filename在内存中的地址
                int addr = machine->ReadRegister(4);
                int i = 0;
                // 从该地址中读出参数filename
                do {
                    machine->ReadMem(addr + i, 1, (int *)&filename[i]);
                } while(filename[i++] != '\0');
                // 打开应用程序filename
                OpenFile *executable = fileSystem->Open(filename);
                if (executable == NULL) {
                    printf("Unable to open file %s\n", filename);
                    return;
                }
                // 为应用程序及栈分配内存空间并为其建立页表，读入应用程序代码及数据
                space = new AddrSpace(executable);
                delete executable;   // close file

                // 创建一个核心线程，将该应用程序映射到该核心线程
                char *forkedThreadName = filename;
                thread = new Thread(forkedThreadName);
                thread->Fork(StartProcess, space->getSpaceID());
                // 用户线程映射到核心线程
                thread->space = space;

                // 将所有设计寄存器请0
                machine->WriteRegister(2, space->getSpaceID());
                AdvancePC();
                break;

            }
            case SC_Join: {
                int SpaceId = machine->ReadRegister(4);  //ie. ThreadId or SpaceId
                currentThread->Join(spaceId);
                //返回Joinee的退出码waitProcessExitCode
                machine->WriteRegister(2, currentThread->waitProcessExitCode);
                AdvancePC();
                break;
            }

            default: {
                printf("Unexpected syscall %d %d\n", which, type);
                ASSERT(FALSE);
            }
        }
    } else {
	    printf("Unexpected user mode exception %d %d\n", which, type);
	    ASSERT(FALSE);
    }
}

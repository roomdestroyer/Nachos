# make clean
make
/usr/local/mips/bin/decstation-ultrix-gcc -I ../userprog -I ../threads -S halt.c
/usr/local/mips/bin/decstation-ultrix-gcc -I ../userprog -I ../threads -S exit.c

#include "syscall.h"

int main() 
{ 
    SpaceId pid;
    
    // pid=Exec("../test/halt.noff"); //利用你所实现的 Exec()执行../test/halt.noff 
    Exit(0);
    Halt();
    /* not reached */ 
}

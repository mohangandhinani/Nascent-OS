#include <stdio.h>
#include <syscalls.h>

int waitpid(int pid, int *status, int options){
return wait4(pid, status, options, NULL);
}
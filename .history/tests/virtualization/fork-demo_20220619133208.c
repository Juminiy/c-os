#include <unistd.h>
#include <stdio.h>

pid_t pid1 = 0xfffff, pid2 = 0xfffff, pid3 = 0xfffff; 

int main() {

    printf("Currnt pid : pidc=%d\n",getpid());
    pid1 = fork();
    printf("Currnt pid : pidc=%d\n",getpid());
    pid2 = fork();
    // printf("Currnt pid : pidc=%d\n",getpid());
    pid3 = fork();

    printf("Forked pid : pid1=%5d, pid2=%5d, pid3=%5d\n",pid1,pid2,pid3);
    return 0 ;
}
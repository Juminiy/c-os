#include <unistd.h>
#include <stdio.h>

pid_t pid1 = 0xfffff, pid2 = 0xfffff, pid3 = 0xfffff; 

int main() {

    printf("Current pid : pid0=%d\n",getpid());

    pid1 = fork();
    pid2 = fork();
    pid3 = fork();

    printf("Forked pid : pid1=%d, pid2=%d, pid3=%d\n",pid1,pid2,pid3);
    return 0 ;
}
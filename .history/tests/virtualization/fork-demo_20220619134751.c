#include <unistd.h>
#include <stdio.h>

pid_t pid_1 = 0xfffff , pid_2 = 0xfffff , pid_3 = 0xfffff ; 
pid_t pid_n[] = { 0 };


int main() {

    // printf("Currnt pid : pidc=%d\n",getpid());
    // pid1 = fork();
    // printf("Currnt pid : pidc=%d\n",getpid());
    // pid2 = fork();
    // printf("Currnt pid : pidc=%d\n",getpid());
    // pid3 = fork();

    for ( int i = 1 ;i <= 5 ; i ++ ) {
        pid_n[i] = fork(); 
    }

    //printf("Forked pid : pid_1=%5d, pid_2=%5d, pid_3=%5d\n",pid_1,pid_2,pid_3);

    for ( int i = 1 ;i <= 5 ; i ++ ) {
        pid_n[i] = fork(); 
    }
    printf("%d",pid_n[])
    return 0 ;
}
#include <unistd.h>
#include <stdio.h>

pid_t pid_1 = 0xfffff , pid_2 = 0xfffff , pid_3 = 0xfffff ; 
pid_t pid_n[20] = { 0 };

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

    printf("Forked pid : pid1=%5d, pid2=%5d, pid3=%5d\n",pid_1,pid_2,pid3);
    return 0 ;
}
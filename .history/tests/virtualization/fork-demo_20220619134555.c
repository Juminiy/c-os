#include <unistd.h>
#include <stdio.h>

pid_t pid1 = 0xfffff , pid2
pid_t pidn[20] = { 0 };

int main() {

    // printf("Currnt pid : pidc=%d\n",getpid());
    // pid1 = fork();
    // printf("Currnt pid : pidc=%d\n",getpid());
    // pid2 = fork();
    // printf("Currnt pid : pidc=%d\n",getpid());
    // pid3 = fork();

    for ( int i = 1 ;i <= 5 ; i ++ ) {
        pid[i] = fork(); 
    }

    printf("Forked pid : pid1=%5d, pid2=%5d, pid3=%5d\n",pid1,pid2,pid3);
    return 0 ;
}
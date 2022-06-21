#include <unistd.h>
#include <stdio.h>

pid_

int main() {

    printf("Currnt pid : pidc=%d\n",getpid());
    pid1 = fork();
    printf("Currnt pid : pidc=%d\n",getpid());
    pid2 = fork();
    printf("Currnt pid : pidc=%d\n",getpid());
    pid3 = fork();

    for ( int i = 1 ;i <= 5 ; i ++ ) {
        pid
    }

    printf("Forked pid : pid1=%5d, pid2=%5d, pid3=%5d\n",pid1,pid2,pid3);
    return 0 ;
}
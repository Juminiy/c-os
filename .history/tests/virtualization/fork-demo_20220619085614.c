#include <unistd.h>
#include <stdio.h>

int main() {

    pid_t pid1 , pid2 = 0xff, pid3 =0xff ; 
    pid_t pid1 = fork();
    // pid_t pid2 = fork();
    // pid_t pid3 = fork();

    printf("Fork pid : pid1=%d, pid2=%d, pid3=%d\n",pid1,pid2,pid3);
    return 0 ;
}
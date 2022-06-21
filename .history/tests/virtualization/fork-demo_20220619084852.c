#include <unistd.h>
#include <stdio.h>

int main() {

    pid_t pid1 = fork();
    pid_t pid2 = fork();
    pid_t pid3 = fork();

    printf("Fork pid : pid1=%d, pid2=%d,%d")
    return 0 ;
}
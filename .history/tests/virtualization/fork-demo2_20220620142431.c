#include <stdio.h>
#include <unistd.h>

int main(int argc , char* argv[]) {

    for (int i=0;i<2;i++) {
        fork();
        printf("Hello\n")
    }

    return 0 ; 
}
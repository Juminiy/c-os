#include <stdio.h>
#include <unistd.h>

int main(int argc , char* argv[]) {

    setvuf( stdout , NULL );
    for ( int i = 0 ; i < 2 ; i++ ) {
        fork();
        printf("Hello\n");
    }

    // for( int i = 0 ; i < 2 ; i++ ) {
    //     wait(NULL);
    // }

    return 0 ; 
}
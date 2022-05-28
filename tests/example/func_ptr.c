#include <stdlib.h>
#include <stdio.h> 

int sum(int a, int b ){
    return a + b ; 
} 

typedef int (*sumptr) (int,int); 

int main(void) {
    
    printf("%d\n" , '\0' == 0 ) ; 
    return 0 ; 
}
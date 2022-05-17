
#include <stdlib.h>
#include <stdio.h> 

int sum(int a, int b ){
    return a + b ; 
} 

typedef int (*sumptr) (int,int); 

int main(void) {
    
    sumptr p1 = sum ; 
    sumptr p2 = &sum ; 
    
    printf("%p\n%p\n",p1,p2) ;  

    printf("%d\n",p1(1,2));
    printf("%d\n",(*p2)(3,4));
    return 0 ; 
}
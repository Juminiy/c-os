#include <stdio.h>
#include <stdlib.h> 

int sq( int x ) {
    return x * x ; 
} 

int adsq( int a, int b) { 
    return sq (a) + sq(b) ;
}
void fc() ; 
void fb() ;
void fa() ; 

void fa() { fb() ; }
void fb() { fc() ; }
void fc() { fa() ; }

void test_calloc( ) {
    
    // int *parr = (int *) malloc ( 100 * sizeof(int) ) ; 
    // int * parr = (int *) calloc( 100 , sizeof( int ) ) ; 
    // // int * parr = (int *) calloc ( 100 , sizeof(int) ) ; 
    // *( parr + 102) = 100 ; 
    // // parr = (int *) realloc( parr , 1000 ) ; 
    // printf( "parr[102] = %d\n", * (parr + 102) ) ;

}

int *test_return_args_in_function( int *a ,int *b) { 
    int * c = (int *) malloc ( sizeof ( int ) ) ; 
    *c = (*a) + (*b)  ;  
    printf("c = %p , in func addr[c] = %p\n" , c , &c) ; 
    return c;  
}

void test_lk () {
    int * arr = (int *) calloc ( 4 , sizeof( int ) ) ; 
}
int main( ) { 
    int flag = 1 ;  
    while ( flag ) { 
        scanf("%d",&flag) ; 
        if ( flag ) {
            test_lk () ;
        }
    }  
    return 0 ;
}
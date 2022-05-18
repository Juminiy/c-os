#ifndef _BASE_DEBUG_C
#define _BASE_DEBUG_C
#include <stdio.h> 

void _debug_integer ( int x ) { 

    printf( "integer = %d\n" , x ) ; 
    
}

void _debug_println( char * line ) {

    puts( line ) ; 
    
}

void _debug_void_to_int_arr( void *arr , int n ) {

    printf("arr { ") ; 
    for ( int i = 0;i < n ; i ++ ) {
        printf ( "%d " , * ((int*) arr) ) ;  
    }
    puts("}");

}

#endif
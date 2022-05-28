#ifndef _VOID_MEM_H
#define _VOID_MEM_H


#ifndef _BOUND_NUMBER
#define _BOUND_NUMBER

#define _MID_ARR_N 4294967295 

#define _MAX_ARR_N 281473976710655

#define _SIZE(n) n 

#endif 

#include <stdlib.h>
#include <string.h>
#include <assert.h>


// generic must realize the function pointer type

// element compare function pointer 
typedef int ( *_cmp ) ( const void * a , const void * b ) ; 
// memory swap function pointer 
typedef void ( *_swp ) ( void * a, void * b , size_t sz ) ;  


// generic swap : memory copy and memory free , swap two mem addr  
void _void_swp( void *a , void *b, size_t sz ) {
    void * tmp = malloc( sz ) ; 
    assert( a && b && tmp ) ;
    memcpy( tmp , a , sz ) ;
    memcpy( a , b , sz ) ;
    memcpy( b , tmp , sz ) ; 
    free( tmp ) ; 
}

// generic copy : memory copy and memory free , mv one from another 
void _void_mv( void *dst , void *src , size_t sz ) { 
    
    assert ( dst && src ) ;
     
    memcpy( dst , src , sz ) ; 

}

#endif 
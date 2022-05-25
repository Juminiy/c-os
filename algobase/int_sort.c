#ifndef _INT_SORT_C
#define _INT_SORT_C

#include <stdio.h>
#include "base_def.h"
#include "void_qsort.c"
#include "void_msort.c"
#include "void_bsort.c" 
#include "void_hsort.c"

// compare function int realization
int _int_cmp(const void *a,const void *b) { 
    int *val_a = (int*) a ; 
    int *val_b = (int*) b ; 
    // print addr & value 
    // printf("\nptr_a = \naddr = %p , value = %d\n",val_a,*val_a) ;
    return *val_a < *val_b ;  
}

void _format_int_output(int *arr,int n) {
    
    for(int i=0;i<n;i++) {
        printf( "%d " , arr[i] ) ; 
    }

    puts("");
    
}

void _int_output(int *arr , int n) { 
    printf("arr { ") ; 
    _loop(i,0,n-1) {
        printf("%d ",arr[i]);
    }
    printf(" }\n") ;
} 

void _int_qsort( int * arr , int n ) {
    _void_qsort( ( void * ) arr , n , sizeof(int) , _int_cmp ) ; 
}

void _int_msort( int * arr , int n ) {
    _void_msort( ( void * ) arr , n , sizeof(int) , _int_cmp ) ; 
}

void _int_bsort( int * arr , int n) {
    _void_bsort( ( void * ) arr , n , sizeof(int) , _int_cmp ) ;
}

void _int_hsort( int * arr , int n ) {
    _void_hsort( ( void * ) arr , n , sizeof(int) , _int_cmp ) ; 
}

#endif 
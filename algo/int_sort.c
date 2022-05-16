#include <stdlib.h> 
#include <stdio.h>
#include "def.h"
#include "void_qsort.c"


// compare function int realization
int _cmp_int(const void *a,const void *b) { 
    int *val_a = (int*) a ; 
    int *val_b = (int*) b ; 
    // print addr & value 
    // printf("\nptr_a = \naddr = %p , value = %d\n",val_a,*val_a) ;
    return *val_a < *val_b ;  
}

void _format_int_output(int *arr,int n) {
    for(int i=0;i<n;i++) {
        printf("%d ",arr[i]) ; 
    }
}

void _int_output(int *arr , int n) { 
    printf("arr { ") ; 
    _loop(i,0,n-1) {
        printf("%d ",arr[i]);
    }
    printf(" }\n") ;
} 

void _int_qsort(int * arr , int n ) {
    _void_qsort( (void*)arr , n , sizeof(int) , _cmp_int ) ; 
}

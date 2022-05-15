#include <stdlib.h>
#include <string.h>
#include <assert.h>

// generic sort 

// compare function pointer
typedef int (*_cmp) (const void * a,const void * b) ; 
typedef void (*_swp) (void *a, void *b,size_t sz) ;  

// generic swap memory copy and memory free 
void _swp_void(void *a , void *b,size_t sz) {
    void * tmp = malloc(sz) ; 
    assert(tmp != NULL ) ;
    memcpy(tmp,a,sz) ;
    memcpy(a,b,sz) ;
    memcpy(b,tmp,sz) ; 
    free(tmp) ;
}


// quick sort realize 
// the algo is assigned in luogu 
void _q_sort(void *arr , int l ,int r ,_cmp cmp ) { 
    if (l >= r) return ; 
    void *pivot = & (arr[ (r-l) / 2 + l ]) ; 
    int j = r , i = l ; 
    while (i <= j) { 
        while( cmp( pivot , &(arr[j]) ) ) { j -- ; } 
        while( cmp( &(arr[i]) , pivot ) ) { i ++ ; } 
        if (i <= j) { 
            _swp_void( & (arr[i]) , & (arr[j]) , sizeof(arr[i])) ; 
            i ++ , j -- ; 
        }
    } 
    if (i <= r) { _q_sort( arr, i, r, cmp ) ; }
    if (l <= j) { _q_sort( arr, l, j, cmp ) ; }
}

void _qsort(void *arr_base, int n, _cmp cmp) { 
    _q_sort( arr_base , 0 , n-1 , cmp ) ;  
} 



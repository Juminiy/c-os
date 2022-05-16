#include <stdlib.h>
#include <string.h>
#include <assert.h>

// generic sort 

// compare function pointer
typedef int (*_cmp) (const void * a,const void * b) ; 
typedef void (*_swp) (void * a, void * b, size_t sz) ;  

// generic swap memory copy and memory free 
void _swp_void(void *a , void *b,size_t sz) {
    void * tmp = malloc(sz) ; 
    assert(tmp != NULL ) ;
    memcpy(tmp,a,sz) ;
    memcpy(a,b,sz) ;
    memcpy(b,tmp,sz) ; 
    free(tmp) ;
}

// 2022.5.15 makefile 
// quick sort realize 
// the algo is assigned by 1e10 amount int and struct data.
void _q_sort(void *arr , int l ,int r ,size_t sz , _cmp cmp ) { 
    if (l >= r) return ; 
    void *pivot = & (arr[ ( (r-l) / 2 + l) * sz ]) ; 
    // prinf addr 
    // printf("pivot addr = %p \n ",pivot) ; 
    int j = r , i = l ; 
    while (i <= j) { 
        while( cmp( pivot , &(arr[j * sz]) ) ) { 
            j -- ; 
        } 
        while( cmp( &(arr[i * sz]) , pivot ) ) { 
            i ++ ; 
        } 
        if (i <= j) { 
            // the type problem is someth tricky 
            // case int print pre val 
            // int *pai = (int *) (&(arr[i])) , *paj = (int *) (&(arr[j])) ;  
            // printf("\n pre : arr[%d] = %d , arr[%d] = %d \n",i,*pai,j,*paj) ; 
            _swp_void( & (arr[i * sz]) , & (arr[j * sz]) , sz ) ; 
            // case int print post val
            // *pai = (int *) (&(arr[i])) , *paj = (int *) (&(arr[j])) ; 
            // printf("post : arr[%d] = %d , arr[%d] = %d \n",i,*pai,j,*paj) ; 
            i ++ , j -- ; 
        }
    } 
    if (i <= r) { _q_sort( arr, i, r, sz, cmp ) ; }
    if (l <= j) { _q_sort( arr, l, j, sz, cmp ) ; }
}

void _qsort(void *arr_base, int n, size_t sz , _cmp cmp) { 
    _q_sort( arr_base , 0 , n-1 , sz , cmp ) ;  
} 



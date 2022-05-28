
#ifndef _VOID_QSORT_C
#define _VOID_QSORT_C

#include "void_mem.h"


// 2022.5.15 start code 
// quick sort realization 
// the algo is assigned by 1e10 amount in [type:int] and [type:struct] data.
void _void_q_sort(void *arr , int l ,int r ,size_t sz , _cmp cmp ) { 
    
    if (l >= r) return ; 

    // case1 : array condition
    // void *pivot = & (arr[ ( (r-l) / 2 + l) * sz ]) ; 
    // case2 : base address + offest * size 
    void *pivot = arr + ( (r-l) / 2 + l) * sz ;  

    // prinf addr 
    // printf("pivot addr = %p \n ",pivot) ; 
    int j = r , i = l ; 
    while (i <= j) { 
        while( cmp( pivot , arr + j * sz ) ) { 
            j -- ; 
        } 
        while( cmp( arr + i * sz , pivot ) ) { 
            i ++ ; 
        } 
        if (i <= j) { 

            // the type problem is someth tricky 
            // case int print pre val 
            // int *pai = (int *) (arr + i* sz) , *paj = (int *) ( arr + j * sz ) ;   
            // printf("\n pre : arr[%d] = %d , arr[%d] = %d \n",i,*pai,j,*paj) ; 

            _void_swp( arr + i * sz , arr + j * sz , sz ) ; 

            // case int print post val
            // pai = (int *) (arr + i* sz) , paj = (int *) ( arr + j * sz ) ;   
            // printf("post : arr[%d] = %d , arr[%d] = %d \n",i,*pai,j,*paj) ; 

            i ++ , j -- ; 
        }
    } 

    if (i <= r) { _void_q_sort( arr, i, r, sz, cmp ) ; }

    if (l <= j) { _void_q_sort( arr, l, j, sz, cmp ) ; }

}
// 2021.5.16 success void_sort.


void _void_qsort(void *arr_base, int n, size_t sz , _cmp cmp) { 
    
    if ( n >= _MID_ARR_N ) {
        printf ( " #warning The array size is a little big, you can try outside sort within the inside sort " ) ; 
    }

    if ( n >= _MAX_ARR_N ) {  
        printf ( " #warning The array size is out of bounds, that the mem can not hold, you must try outside sort " ) ;
        return ; 
    }

    _void_q_sort( arr_base , 0 , n-1 , sz , cmp ) ; 
} 




#endif 
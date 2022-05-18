#ifndef _VOID_BSORT_C
#define _VOID_BSORT_C

#include "void_mem.h"

// 2022.5.18 created 
// O(n^2) sort
void _void_bsort(void *arr_base , int n , size_t sz , _cmp cmp ) {

    for ( int bck_ptr = n - 1 ; bck_ptr > 0 ; bck_ptr -- ) {
        for ( int cur_ptr = n - 1 ; cur_ptr >= n - bck_ptr ; cur_ptr -- ) { 
            void *pst_ele = arr_base + cur_ptr * sz ; 
            void *pre_ele = arr_base + ( cur_ptr - 1 ) * sz ; 
            if ( cmp( pst_ele , pre_ele ) ) { 
                _void_swp ( pst_ele , pre_ele , sz ) ;
            } 
        }
    }

}


#endif 
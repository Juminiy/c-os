#ifndef _VOID_HSORT_C
#define _VOID_HSORT_C

#include "void_mem.h" 
#include "base_debug.h"
// the heap operaton :
/*
 * complete binary tree 
 * max or min decides by the function pointer: cmp
 * 
 * opt_base_1:
 *  opt1 : input arr [0...n-1] ( arr_base ) automated adjust to max_heap or min_heap 
 *  opt2 : arr [] self adjust from index: l / 2
 * opt_base_2:
 *  opt3 : move top element to last last_ptr -- , by the way , if max_heap then Ascending , elif min_heap then Descending.
 * 
 */

void * _void_cmp_v3(void * v1 , void * v2 , void * v3 , _cmp cmp ) { 
    
    int cmp_1 = cmp( v2, v1 ) ;  

    if ( v3 == NULL ) {

        return cmp_1 ? v1 : v2 ; 

    }

    int cmp_2 = cmp( v3 , v1 ) ,cmp_3 = cmp( v3 , v2 ) ; 
    
    return cmp_1 ? ( cmp_2 ? v1 : v3 ) : ( cmp_3 ? v2 : v3 ) ; 

}

// O ( logN )
void _void_top_adjust( void *arr , int n , int i , size_t sz , _cmp cmp ) { 

    while ( ( ( i << 1) + 1 ) < n ) {

        int il = i << 1 + 1 ;
        int ir = il + 1 ; 

        void * iptr = arr + i * sz ;  
        void * ilptr = arr + il * sz ; 
        void * irptr = NULL ; 

        if ( ir < n ) {
            irptr = ilptr + sz ; 
        }

        // to avoid irptr = NULL 
        void * cmp_v = _void_cmp_v3( iptr , ilptr , irptr , cmp ) ; 

        if ( cmp_v == iptr ) {

            return ; 

        } else if ( cmp_v == ilptr ) { 

            _void_swp( iptr , ilptr , sz ) ; 

            i = il ; 

        } else {

            _void_swp( iptr , irptr , sz ) ; 

            i = ir ; 

        }
        
    }
}

// O( N * ( logN - 1 ) ) 
void _void_heap_adjust( void *arr , int n , size_t sz , _cmp cmp ) {

    int top_ptr = n / 2 ; 

    while ( top_ptr >= 0 ) { 

        _void_top_adjust( arr , n , top_ptr , sz , cmp ) ; 
        
        top_ptr -- ; 

    }

}



void _void_hsort(void *arr_base , int n , size_t sz , _cmp cmp ) {

    _void_heap_adjust( arr_base , n , sz , cmp ) ; 

    // wrong in 2022.5.18 
    // debug
    _debug_println( "afster adjust is : " ) ;
    _debug_void_to_int_arr( arr_base , n ) ; 

    int last_ptr = n - 1 ;

    while ( last_ptr > 0 ) {

        _void_swp( arr_base , arr_base + last_ptr * sz , sz ) ; 

        _void_top_adjust( arr_base , last_ptr , 0 , sz, cmp ) ; 

        last_ptr -- ; 

    }

}
// TODO tobe correct it ...

void _void_hpush(void *arr_base , size_t sz , _cmp cmp ) {

}

void * _void_hpop(void *arr_base , size_t sz , _cmp cmp ) {

}

#endif 
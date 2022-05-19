
#ifndef _VOID_MSORT_C
#define _VOID_MSORT_C

#include "void_mem.h" 


// 2022.5.16 start code 
// merge sort realization 
void _void_m_merge( void *arr_base , void *arr_tmp ,
        int st , int md , int ed , size_t sz , _cmp cmp ) {

    // two path merge bound.
    int lst = st , led = md , rst = md + 1 , red = ed ; 

    int tmp_1 = st , tmp_2 = st ; 

    while ( lst <= led && rst <= red ) {

        if ( cmp ( arr_base + lst * sz , arr_base + rst * sz ) ) { 

            _void_mv( arr_tmp + tmp_1 * sz , arr_base + lst * sz , sz ) ; 

            lst ++ , tmp_1 ++ ; 

        } else {

            _void_mv( arr_tmp + tmp_1 * sz , arr_base + rst * sz , sz ) ; 

            rst ++ , tmp_1 ++ ; 

        }

    } 

    while ( lst <= led ) {

        _void_mv( arr_tmp + tmp_1 * sz , arr_base + lst * sz , sz ) ;

        lst ++ , tmp_1 ++ ; 

    }

    while ( rst <= red ) {

        _void_mv( arr_tmp + tmp_1 * sz , arr_base + rst * sz , sz ) ; 

        rst ++ , tmp_1 ++ ; 

    }

    while ( st <= ed ) {

        _void_mv( arr_base + st * sz , arr_tmp + tmp_2 * sz , sz ) ; 

        st ++ , tmp_2 ++ ; 

    }

}

void _void_m_div( void *arr_base , void *arr_tmp , 
        int l , int r , size_t sz , _cmp cmp ) {

    if (l >= r) return ; 

    // avoid memory out of bounds.
    int mid = (r - l) / 2 + l ;

    _void_m_div( arr_base , arr_tmp , l , mid , sz , cmp ) ;

    _void_m_div( arr_base , arr_tmp , mid + 1 , r , sz , cmp ) ; 

    _void_m_merge( arr_base , arr_tmp , l , mid , r , sz , cmp ) ; 

}

void _void_msort(void *arr_base ,int n ,size_t sz , _cmp cmp) { 
    
    // allocate same size n called arr_tmp 
    void *arr_tmp = (void *) calloc( n , sz ) ; 

    _void_m_div( arr_base , arr_tmp , 0 , n-1 , sz , cmp ) ; 

    free( arr_tmp ) ; 
}

// finish in 2022.5.17

#endif 
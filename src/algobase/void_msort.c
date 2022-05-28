
#ifndef _VOID_MSORT_C
#define _VOID_MSORT_C

#include "void_mem.h" 


// 2022.5.16 start code 
// merge sort realization 
// O( N ) Space 
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
    
    // allocate same size n called arr_tmp 😂
    void *arr_tmp = (void *) calloc( n , sz ) ; 

    _void_m_div( arr_base , arr_tmp , 0 , n-1 , sz , cmp ) ; 

    free( arr_tmp ) ; 
}
// finish in 2022.5.17


// start in 2022.5.26 
void _void_exchange_1( void *arr_base , int st , int ed , size_t sz ) {

    for ( int i = st ; i <= (ed-st)/2 + st ; i ++ ) {

        _void_swp( arr_base + i * sz , arr_base + (ed+st-i) * sz , sz ) ; 

    }

}

// three times exchange to rotate in a space .   
void _void_exchange_3( void *arr_base , int _n , int _offset, size_t sz ) {

    _void_exchange_1( arr_base , 0 , _offset - 1 , sz ) ; 

    _void_exchange_1( arr_base , _offset ,  _n - _offset - 1 , sz ) ; 

    // assert ( led + 1 == rst ) ;

    _void_exchange_1( arr_base , 0 , _n - 1 , sz ) ;  
}

// 2022.5.26 
// log(N) * O( 1 ) = O( log(N) ) Space 
void _void_m_merge_2( void *arr_base , int st , int md , int ed , size_t sz , _cmp cmp) {
     
    int i = st , j = md + 1 ;  
    

    // util exit 
    while ( i < j && j <= ed ) {

        int step = 0 ;
        // from [st,md] find the first i > index
        while ( i < j && cmp( arr_base + i * sz , arr_base + j * sz ) ) i ++ ; 

        // from [index,ed] find the first j > i 
        while ( i < j && cmp( arr_base + j * sz , arr_base + i * sz ) ) j ++ , step ++ ; 

        // exchange_3 
        _void_exchange_3( arr_base + i * sz , j - i , j-i-step , sz ) ; 
        i += step ; 

        // debug_1 
        // _debug_void_to_int_arr( (int*)arr_base , 10);

    }

}

void _void_m_div_2( void *arr_base , int l , int r , size_t sz , _cmp cmp ) {

    if (l >= r) return ; 

    // avoid memory out of bounds.
    int mid = (r - l) / 2 + l ;

    _void_m_div_2( arr_base , l , mid , sz , cmp ) ; 

    _void_m_div_2( arr_base , mid+1 , r , sz , cmp ) ;     

    _void_m_merge_2( arr_base , l , mid , r , sz , cmp ) ;  

}

void _void_msort_2 ( void *arr_base , int n , size_t sz , _cmp cmp) {

    // don't need to allocate the space n 😁
    _void_m_div_2( arr_base , 0 , n-1 , sz , cmp ) ; 

}
// some problems

#endif 
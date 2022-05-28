#include <stdlib.h> 
#include <string.h> 
#include <assert.h> 
#include <stdio.h> 

#define _loop(i,a,b) for(int i=a;i<=b;i++) 
#define MAXN 100001 

typedef int ( *_cmp ) ( const void * a , const void * b ) ; 

typedef void ( *_swp ) ( void * a, void * b , size_t sz ) ;  

int _qread(){
    int x = 0 , sgn = 1 ; 
    char ch = getchar();
    while(ch < '0' || ch > '9') {
        if (ch == '-') sgn = -1 ;
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9') {
        x = (x << 1) + (x << 3) + ch - '0' ; 
        ch = getchar(); 
    }
    return x * sgn ;  
}

void _void_mv( void *dst , void *src , size_t sz ) { 
    assert ( dst && src ) ;
    memcpy( dst , src , sz ) ; 
}

int _int_cmp(const void *a,const void *b) { 
    int *val_a = (int*) a ; 
    int *val_b = (int*) b ; 
    return *val_a < *val_b ;  
}

void _format_int_output(int *arr,int n) {
    for(int i=0;i<n;i++) {
        printf( "%d " , arr[i] ) ; 
    }
    puts("");
}

void _void_m_merge( void *arr_base , void *arr_tmp , int st , int md , int ed , size_t sz , _cmp cmp ) {
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

void _void_m_div( void *arr_base , void *arr_tmp , int l , int r , size_t sz , _cmp cmp ) {
    if (l >= r) return ; 
    int mid = (r - l) / 2 + l ;
    _void_m_div( arr_base , arr_tmp , l , mid , sz , cmp ) ;
    _void_m_div( arr_base , arr_tmp , mid + 1 , r , sz , cmp ) ; 
    _void_m_merge( arr_base , arr_tmp , l , mid , r , sz , cmp ) ; 
}

void _void_msort(void *arr_base ,int n ,size_t sz , _cmp cmp) { 
    void *arr_tmp = (void *) calloc( n , sz ) ; 
    _void_m_div( arr_base , arr_tmp , 0 , n-1 , sz , cmp ) ; 
    free( arr_tmp ) ; 
}

void _int_msort( int *arr , int n ) {
    _void_msort( (void*)arr , n , sizeof(int) , _int_cmp ) ; 
}


int main() {
    int n = _qread() ; 
    int arr[MAXN] ={ 0 } ; 
    _loop( i , 0 , n-1 ) { 
        arr[i] = _qread() ; 
    }
    _int_msort( arr , n ) ;
    _format_int_output( arr , n ) ; 
    return 0 ; 
}
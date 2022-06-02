#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef unsigned int bool ; 

// but to failed .!
void _debug_void_to_int_arr( int *arr , int n ) {

    printf("arr { ") ; 
    for ( int i = 0;i < n ; i ++ ) { 
        printf ("%d ",arr[i]) ;   
    }
    puts("}");

}

// find mixed one 
int dfs( int *m, int *u , int mx ,int cur ,int len) {
    if ( !len ) return cur ;
    if ( cur >= mx ) return 0 ;
    for ( int i=cur;i<mx;i++) {
        if ( !u[cur] && len >= m[cur] ) {
            u[cur] = 1 ;
            dfs(m,u,mx,i+1,len-m[cur]) ; 
            // u[cur] = 0 ; 
        }
    }
}

static int _cmp(const void *pa, const void *pb) {
    return *(int *)pb - *(int *)pa;
}

bool makesquare(int* matchsticks, int matchsticksSize){
    int tot = 0 ; 
    for ( int i=0;i<matchsticksSize;i++) 
        tot += matchsticks[i] ;  
    int per = tot / 4 , mod = tot%4 ; 
    if ( mod ) return 0 ; 
    int used[matchsticksSize] ;
    memset(used,0,matchsticksSize*4); 
    qsort(matchsticks,matchsticksSize,sizeof(int),_cmp);

    //_debug_void_to_int_arr(used,matchsticksSize) ; 
    int cur = 0 ;
    cur = dfs(matchsticks,used,matchsticksSize,cur,per) ; 
    _debug_void_to_int_arr(used,matchsticksSize) ; 
    cur = dfs(matchsticks,used,matchsticksSize,cur,per) ; 
    _debug_void_to_int_arr(used,matchsticksSize) ; 
    cur = dfs(matchsticks,used,matchsticksSize,cur,per) ; 
    _debug_void_to_int_arr(used,matchsticksSize) ; 
    cur = dfs(matchsticks,used,matchsticksSize,cur,per) ; 
    _debug_void_to_int_arr(used,matchsticksSize) ; 
}

// [0] ./a.out
// [1...] m 
int main(int argc,  char *argv[] ) { 
    
    int n = argc - 1 ;
    int arr[n] ; 
    for (int i=0;i<n;i++){
        arr[i] = atoi(argv[i+1]);
    }
    makesquare(arr,n);
    
    return 0 ;

}
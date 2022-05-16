#include <stdio.h>
#include <stdlib.h>
#define MAXN 100001
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

void _swp(int *a, int *b) {
    int tmp = *a ; 
    *a = *b ;
    *b = tmp ; 
}

void _output_format(int *arr,int n) {
    for(int i=0;i<n;i++) {
        printf("%d ",arr[i]) ; 
    }
}

void _q_sort(int *arr , int l ,int r) { 
    if (l >= r) return ; 
    int pivot = arr[ (r-l) / 2 + l ] ; 
    int j = r , i = l ; 
    while (i <= j) {
        while(arr[j] > pivot) { j -- ; } 
        while(arr[i] < pivot) { i ++ ; } 
        if (i <= j) {
            _swp(arr+i,arr+j) ; 
            i ++ , j -- ; 
        }
    } 
    if (i <= r) { _q_sort(arr,i,r) ; }
    if (l <= j) { _q_sort(arr,l,j) ; }
}
void _void_qsort(int *arr, int n) { 
    _q_sort( arr , 0 , n-1 ) ; 
} 

int main() {
    int n = _qread() ; 
    int arr[MAXN] = { 0 } ; 
    for (int i=0;i<n;i++) { 
        arr[i] = _qread() ; 
    } 
    _void_qsort(arr,n) ; 
    _output_format(arr,n) ; 
    return 0 ; 
}


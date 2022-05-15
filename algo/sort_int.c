#include <stdlib.h> 
#include <stdio.h>
#include "def.h"


void _swp_int(void *a,void *b) { 
    int tmp = a ;
    a = b ;
    b = tmp ; 
}
int _cmp_int(const void *a,const void *b) { 
    int val_a = (int) a ; 
    int val_b = (int) b ; 
    return a < b ;  
}


// void _swp(int *a, int *b) {
//     int tmp = *a ; 
//     *a = *b ;
//     *b = tmp ; 
// }

void _output_format(int *arr,int n) {
    for(int i=0;i<n;i++) {
        printf("%d ",arr[i]) ; 
    }
}

void _output_arr(int *arr , int n) { 
    printf("arr [ ") ; 
    _loop(i,0,n-1) {
        printf("%d,",arr[i]);
    }
    printf(" ]\n") ;
}




// // quick sort realize 
// // the algo is assigned in luogu 
// void _q_sort_int(int *arr , int l ,int r) { 
//     if (l >= r) return ; 
//     int pivot = arr[ (r-l) / 2 + l ] ; 
//     int j = r , i = l ; 
//     while (i <= j) {
//         while(arr[j] > pivot) { j -- ; } 
//         while(arr[i] < pivot) { i ++ ; } 
//         if (i <= j) {
//             _swp(arr+i,arr+j) ; 
//             i ++ , j -- ; 
//         }
//     } 
//     if (i <= r) { _q_sort(arr,i,r) ; }
//     if (l <= j) { _q_sort(arr,l,j) ; }
// }
// void _qsort_int(int *arr, int n) { 
//     _q_sort( arr , 0 , n-1 ) ; 
// } 

void _msort(int *arr, int n) {
    
}



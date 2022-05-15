#include "sort_void.c" 

void swp_test_int(int *arr_ptr, int index, int asgn) {
    arr_ptr[index] = asgn ; 
}

// void sort_test_int_case1() {
//     int arr[10] ={8,7,6,9,12,13,77,1,-1,0} ; 
//     _output_arr(arr,10) ; 
//     _qsort(arr,10);
//     _output_arr(arr,10) ; 
//     while(1) {
//         break ;
//     }
// }

void sort_test_void_case1() {
    int arr[10] ={8,7,6,9,12,13,77,1,-1,0} ; 
    _output_arr(arr,10) ; 
    _qsort(arr,10,_cmp_int);
    _output_arr(arr,10) ; 
}
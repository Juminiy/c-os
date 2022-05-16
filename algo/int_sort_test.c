#include "int_sort.c"

void int_swp_test(int *arr_ptr, int index, int asgn) {
    arr_ptr[index] = asgn ; 
}

void void_sort_test_int_case1() { 
    printf("sort_test_void_case1 : \n") ; 
    int arr[10] ={8,7,6,9,12,13,77,1,-1,0} ; 
    _int_output( arr , 10 ) ; 
    _int_qsort( arr , 10 ) ; 
    _int_output( arr , 10 ) ;  
}

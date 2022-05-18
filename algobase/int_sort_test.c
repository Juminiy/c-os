#include "int_sort.c" 


void int_swp_test(int *arr_ptr, int index, int asgn) {
    arr_ptr[index] = asgn ; 
}

void void_qsort_test_int_case1() { 
    printf(" qsort_test_void_case1 : \n" ) ; 
    int arr[10] ={8,7,6,9,12,13,77,1,-1,0} ; 
    _int_output( arr , 10 ) ; 
    _int_qsort( arr , 10 ) ; 
    _int_output( arr , 10 ) ;  
}

void void_msort_test_int_case1() { 
    printf(" void_msort_test_int_case1 : \n" ) ; 
    int arr[10] ={8,7,6,9,12,13,77,1,-1,0} ; 
    _int_output( arr , 10 ) ; 
    _int_msort( arr , 10 ) ; 
    _int_output( arr , 10 ) ;  
}

void void_bsort_test_int_case1() {
    printf(" void_bsort_test_int_case1 : \n" ) ; 
    int arr[10] ={8,7,6,9,12,13,77,1,-1,0} ; 
    _int_output( arr , 10 ) ; 
    _int_bsort( arr , 10 ) ; 
    _int_output( arr , 10 ) ; 
}

void void_hsort_test_int_case1() {
    printf(" void_hsort_test_int_case1 : \n" ) ; 
    int arr[10] ={8,7,6,9,12,13,77,1,-1,0} ; 
    _int_output( arr , 10 ) ; 
    _int_hsort( arr , 10 ) ; 
    _int_output( arr , 10 ) ; 
}
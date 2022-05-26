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


void void_exchange_1_3_test_int_case1() { 
    
    printf("void_exchange_1_3_test_int_case1 : \n" ) ; 
    
    int arr[10] ={1,2,3,4,5,6,7,8,9,10} ; 
    
    printf( "exchange_1 : \n" ) ;
    _int_output( arr , 10 ) ; 
    _void_exchange_1( (void*) arr , 0 , 4 , 4 ) ;
    _int_output( arr , 10 ) ;  
    _void_exchange_1( (void*) arr , 0 , 4 , 4 ) ; 

    printf( "exchange_3 : \n" ) ;
    _int_output( arr , 10 ) ; 
    // _void_exchange_3( (void*) arr , 0 , 4 , 5 , 9 , 4 ) ;
    _int_output( arr , 10 ) ; 

}
/* 2022.5.26 
 * success 
void_exchange_1_3_test_int_case1 : 
exchange_1 : 
arr { 1 2 3 4 5 6 7 8 9 10  }
arr { 5 4 3 2 1 6 7 8 9 10  }
exchange_3 : 
arr { 1 2 3 4 5 6 7 8 9 10  }
arr { 6 7 8 9 10 1 2 3 4 5  }
 *
 * 
 */

void void_m_merge_2_test_int_case1() { 
    printf( "void_m_merge_2_test_int_case1 : \n" ) ; 
    int arr[10] ={1,2,4,6,7,3,5,8,9,10} ;
    _int_output( arr , 10 ) ; 
    _void_m_merge_2( (void*)arr , 0,4,9,4, _int_cmp ) ;
    _int_output( arr , 10 ) ; 
}
// form the output maze is correct but it don't stop loop 
// ok well down !



void void_msort_2_test_int_case1() { 
    printf(" void_msort_test_int_case1 : \n" ) ; 
    int arr[10] ={8,7,6,9,12,13,77,1,-1,0} ; 
    _int_output( arr , 10 ) ; 
    _int_msort_2( arr , 10 ) ; 
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
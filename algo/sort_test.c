#include "sort_void.c" 
#include "sort_int.c"

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


void swp_void_test_case1() { 
    printf("swp_void_test_case1\n");
    int a =1 , b = 2 ;  
    int *pa = &a ,*pb = &b;
    _swp_void(pa,pb,sizeof(int)) ;
    printf("%d\n%d\n",a,b); 
}


void cmp_int_test_case1() {
    printf("cmp_int_test_case1\n");
    int arr[10] ={8,7,6,9,12,13,77,1,-1,0} ; 
    printf("%d\n",_cmp_int(&(arr[1]),&(arr[2]))); // expected at 0
    printf("%d\n",_cmp_int(&(arr[2]),&(arr[1]))); // expected at 1 
}


void swp_int_test_case1() { 
    printf("swp_int_test_case1\n");
    int arr[10] ={8,7,6,9,12,13,77,1,-1,0} ; 
    
    // expected at 7 6 
    printf("value 1 = %d , value 2 = %d\n",arr[1],arr[2]); 
    
    // diff addrs are not changed !
    printf("addr : arr[1] %p arr[2] = %p\n",&(arr[1]),&(arr[2])) ;
    _swp_void(&(arr[1]),&(arr[2]),sizeof(int)) ;
    printf("addr : arr[1] %p arr[2] = %p\n",&(arr[1]),&(arr[2])) ;
    
    // expected at 6 7 
    printf("value 1 = %d , value 2 = %d\n",arr[1],arr[2]); 
}


void swp_int_test_case2() {
    printf("swp_int_test_case2\n");
    int arr[10] ={8,7,6,9,12,13,77,1,-1,0} ; 
    // expected at 
    printf("value 1 = %d , value 2 = %d\n",arr[3],arr[5]); 
    _swp_void(&(arr[3]),&(arr[5]),sizeof(int)) ;
    // expected at 
    printf("value 1 = %d , value 2 = %d\n",arr[3],arr[5]); 

}

void void_sort_test_int_case1() { 
    printf("sort_test_void_case1\n");
    int arr[10] ={8,7,6,9,12,13,77,1,-1,0} ; 
    _output_arr(arr,10) ; 
    _qsort((void*)arr,10,sizeof(int),_cmp_int) ; 
    _output_arr(arr,10) ; 
}


void void_sort_test_struct_case1() { 
    
}
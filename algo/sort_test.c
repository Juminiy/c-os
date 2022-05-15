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
    printf("%d\n",_cmp_int(&(arr[1]),&(arr[2])));
    printf("%d\n",_cmp_int(&(arr[2]),&(arr[1])));
}

void swp_int_test_case1() { 
    printf("swp_int_test_case1\n");
    int arr[10] ={8,7,6,9,12,13,77,1,-1,0} ; 
    printf("arr[1] %p arr[2] = %p\n",arr[1],arr[2]) ;
    _swp_void(&(arr[1]),&(arr[2]),sizeof(int)) ;
    printf("arr[1] %p arr[2] = %p\n",arr[1],arr[2]) ;

    printf("%d\n%d\n",arr[1],arr[2]); 
}

void void_sort_test_int_case1() { 
    printf("sort_test_void_case1\n");
    int arr[10] ={8,7,6,9,12,13,77,1,-1,0} ; 
    _output_arr(arr,10) ; 
    _qsort(arr,10,_cmp_int) ; 
    _output_arr(arr,10) ; 
}

void void_sort_test_struct_case1() { 
    printf("sort_test_struct_case1\n");
    int arr[10] ={8,7,6,9,12,13,77,1,-1,0} ; 
    _output_arr(arr,10) ; 
    _qsort(arr,10,_cmp_int) ; 
    _output_arr(arr,10) ; 
}
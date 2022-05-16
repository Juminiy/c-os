#include "void_qsort.c" 


void swp_void_test_case1() { 
    printf("swp_void_test_case1\n");
    int a =1 , b = 2 ;  
    int *pa = &a ,*pb = &b;
    _swp_void(pa,pb,sizeof(int)) ;
    printf("%d\n%d\n",a,b); 
}


void cmp_int_test_case1() {
    printf("cmp_int_test_case1 : \n");
    int arr[10] ={8,7,6,9,12,13,77,1,-1,0} ; 
    printf("%d\n",_cmp_int(&(arr[1]),&(arr[2]))); // expected at 0
    printf("%d\n",_cmp_int(&(arr[2]),&(arr[1]))); // expected at 1 
}


void swp_int_test_case1() { 
    printf("swp_int_test_case1 : \n");
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
    printf("swp_int_test_case2 : \n");
    int arr[10] ={8,7,6,9,12,13,77,1,-1,0} ; 
    // expected at 
    printf("value 1 = %d , value 2 = %d\n",arr[3],arr[5]); 
    _swp_void(&(arr[3]),&(arr[5]),sizeof(int)) ;
    // expected at 
    printf("value 1 = %d , value 2 = %d\n",arr[3],arr[5]); 

}




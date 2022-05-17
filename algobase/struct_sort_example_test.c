#include "struct_sort_example.c"
#include <stdio.h>
#include "base_def.h"
void void_sort_test_struct_case1() { 
    
    stu * stu_exa =  (stu *) malloc( sizeof(stu) * 100 ) ; 

    int n ; 
    scanf("%d" , &n) ;
    _loop(i , 0, n-1) {
        scanf("%d %d",& (stu_exa[i].age), & (stu_exa[i].score )) ; 
    } 

    _stu_output( stu_exa , n ) ; 
    _stu_qsort( stu_exa , n ) ;
    _stu_output( stu_exa , n ) ; 

    free( stu_exa ) ;   
}
#include "struct_sort_example.c"
#include <stdio.h>
#include "base_def.h"

void void_qsort_test_struct_case1() { 
    
    stu * stu_exa =  (stu *) calloc( 100 , sizeof(stu) ) ; 

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
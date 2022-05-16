#include "void_qsort.c" 
#include "def.h"

typedef struct stu { 
    int age ;
    int score ;
} stu ; 


// compare function struct example realization
int _cmp_stu(const void *a,const void *b) { 

    stu *val_a = ( stu* ) a ; 

    stu *val_b = ( stu* ) b ; 

    if (val_a -> score == val_b -> score) { 
        return val_a -> age < val_b -> age ;
    } 

    return val_a -> score < val_b -> score ;  

}

void _stu_output(stu *arr , int n) { 

    printf("arr{ ") ; 
    _loop( i , 0 , n-1 ) {
        printf("[%d,%d] ", arr[i].age , arr[i].score);
    }
    printf(" }\n") ;
} 


void _stu_qsort(stu *arr , int n) {
    _void_qsort( (void *)arr , n ,sizeof(stu) , _cmp_stu ) ; 
}
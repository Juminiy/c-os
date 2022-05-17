#include "ll.c"
#include "../algo/base_def.h"
void ll_test_case1(){
    ll * list = NULL ;
    tranll(list) ; 
    _lp(i,10) {
        list = addll(list,i);
    }
    tranll(list) ; 
    delll(list,2);
    tranll(list) ;
    delll(list,2);
    tranll(list); 
}
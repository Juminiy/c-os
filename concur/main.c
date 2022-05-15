#include "./algo/sort.c"
#include "stdio.h"

int main(){ 
    int arr[100]={0,2,3,4,5,6,0};
    printf("pre = %d\n",arr[2]);
    swp_test(arr,2,-90);
    printf("now = %d\n",arr[2]);
    return 0 ;
}

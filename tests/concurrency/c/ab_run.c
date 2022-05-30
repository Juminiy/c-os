#include "thread.h"
#include <stdio.h>

int a_cnt = 0 , b_cnt = 0 ; 
void ARun( int i ) {
    
    // while (1) {
         
    // } 

    printf("thread %d ,a run\n",i) ; 

        // if (a_cnt == 20) {
        //     break ; 
        // } 
    a_cnt ++ ;   
}

void BRun( int i ) {
    
    // while (1) {
           
    // }

    printf("thread %d , b run\n",i) ;
        
    // if (b_cnt == 20) {
    //     break ; 
    // }

    b_cnt ++ ; 
}

int main( void ) {

    for (int i=0;i<5;i++) { 
        printf("thread %d\n",i) ; 
        create(ARun) ; 
        create(BRun) ; 
    }
     
    join() ; 

    return 0 ;
}
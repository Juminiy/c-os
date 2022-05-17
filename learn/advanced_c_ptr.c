#include <stdio.h>
#include <stdlib.h>
void base_test() {
     // printf("char = %ld,short int = %ld,int = %ld,long int = %ld,double = %ld,float = %ld",sizeof(char),sizeof(short int), sizeof(int),sizeof(long),sizeof(double),sizeof(float)); 
    
    printf(
        "char = %ld,short int = %ld,int = %ld, long int = %ld,double = %ld,float = %ld", \
        sizeof(char),sizeof(short int), sizeof(int), \
        sizeof(long),sizeof(double),sizeof(float)    \
    ); 
    puts("") ;    

    int a = 1 ,b = 2 ;
    
    double c = 3.67 , d = -99.999 ; 

    printf("addr[a] = %p \naddr[b] = %p \naddr[c] = %p \naddr[d] = %p \n",&a,&b,&c,&d) ;  

    int *pa = &a , *pb = &b ; 
    double *pc = &c , *pd = &d ; 
    
    printf("addr[pa] = %p \naddr[pb] = %p \naddr[pc] = %p \naddr[pd] = %p \n",&pa,&pb,&pc,&pd) ; 

    char ch = '1' ; 
    short int sia = 1;
    int ia = 199 ; 
    long la = 100;
    float fa = 00.90;
    double dq = 90.12122333;
    char ch2 = '2' ;

    char *chp = &ch ;
    short int *siap = &sia ; 
    int * iap = &ia ;
    long *lap = &la ;
    float *fap = &fa ;
    double * dqp = &dq ;

    
    printf(
        "char ptr = %ld , short ptr = %ld , int ptr = %ld ,long ptr = %ld , float ptr = %ld , double ptr = %ld\n",
        sizeof(chp) , sizeof(siap) , sizeof(iap) ,sizeof(lap) , sizeof(fap) , sizeof(dqp) 
    ) ;

    void * vdp = NULL; 
    printf("void * ptr = %ld\n",sizeof(vdp)) ; 
}

void ptr_calculate_test() {  
    int *pa = ( int * ) malloc( sizeof (int) * 1  ) ; 
    *( pa + 1 ) = 1 ;
    *( pa + 2 ) = 9 ;
    *( pa + 3 ) = 11 ;
    *( pa + 4 ) = -8 ;
    printf("pa[0] = %d \n",pa[0]) ; 
    printf("pa[100] = %d \n",pa[100]) ; 
    *( pa + 100 ) = 18232 ; 
    printf("pa[100] = %d \n",pa[100]) ; 
    printf("pa[3] = %d , pa[4] = %d \n" , pa[3] , pa[4]) ; 
    int cur = 100 ;
    printf("pa = %p , addr[pa] = %p , addr[cur] = %p ,cur = %d \n" , pa , &pa , &cur , cur) ;
    printf("pa = %p , addr[pa] = %p , addr[cur] = %p ,cur = %d \n" , pa , &pa , &cur , cur) ;
}

int main() { 
    
    return 0 ;
}
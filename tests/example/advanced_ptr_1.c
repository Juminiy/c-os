#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
    int *pa = ( int * ) calloc( 1 , sizeof (int)  ) ; 
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

void ptr_to_ptrs() { 
    int a = 10001 ;
    int *pa = &a ;
    int **ppa = &pa ; 
    printf("addr[a] = %p , a = %d \naddr[pa] = %p , pa = %p\naddr[ppa] = %p ppa = %p\n" , &a,a,&pa,pa,&ppa,ppa) ; 
    printf("a = %d\n",**ppa) ; 
}


void change_a( int a ) {
    printf("addr[a] = %p\n",&a);
    a = 666 ;
}
void ptr_arg_func_test( int * ptr ) {
    printf("addr[ptr] = %p\n",ptr) ; 
    * ptr = 888 ; 
}
void arr_arg_func_test( int arr[]) { 
    printf("base addr[arr] = %p\n",arr) ;
    arr[0] = 999 ; 
}

void ptr_arg_test_1() {
    int a = 100 ;
    int arra [100] = {-9,3,4,0};

    printf("addr[arra[0]] = %p\n",arra) ; 

    printf("arra[0] = %d\n" , arra[0]) ; 

    change_a(arra[0]) ; 
    printf("arra[0] = %d\n" , arra[0]) ; 
    ptr_arg_func_test(arra) ; 
    printf("arra[0] = %d\n" , arra[0]) ; 
    arr_arg_func_test(arra) ; 
    printf("arra[0] = %d\n" , arra[0]) ; 
}

void ppppa_ptr() {
    int a = 2022 ;
    int *pa= &a;
    int **ppa = &pa;
    int ***pppa = &ppa;
    printf("%d, ***pppa size = %ld\n",***pppa,sizeof(pppa)) ; 

    double ****************************** test_ptr_len = NULL ;
    printf( "%ld , %ld\n" , sizeof(test_ptr_len) ,sizeof(test_ptr_len) );
}

void two_d_arrs() { 
    // ss 
    int arr[3][4] = {{-1,202,3,132},{433,553,623,721},{-81,92,0x10,211}} ; 
    /*
    *   1 2 3 12 
    *   4 5 6 7 
    *   8 9 10 11  
    */
   printf("arr_base = %p\n",arr) ; 
   printf("arr[0] = %p\n",arr[0]) ; 
   printf("arr[1] = %p\n",arr[1]) ;
   printf("arr[2] = %p\n",arr[2]) ;  
   printf("[1][1] addr = %p , [1][1] val = %d\n",arr[1]+1 , *(arr[1] + 1) ) ;  

   int * p = & ( arr[0][0] ) ; 
   p = p + 5 ; 
   printf("p = %p , pval = %d\n",p,*p) ; 

     *p = -99999;
     printf("arr[1][1] = %d\n",arr[1][1]) ; 


}

void test_char_ptr_as_func_args( char * s) {
    s[3] = 'P' ; 
}
void test_char_ptr() { 

    char str[8] = "abcde" ; 
    printf("%s\n" , str );
    int sl = strlen( str ) ; 
    str[2] = 'x' ; 
    char *strptr = str ; 
    * ( strptr + 3 ) = 'G' ; 
    printf("len = %d , %s\n", sl , str ) ; 
    test_char_ptr_as_func_args(str) ; 
    puts(str) ; 

    char s2[] = { '1' , '2' , '3' } ; 
    s2[0] = '2' ; 
    printf("s2= %s\n" , s2) ; 
} 

void test_char_arr_pt(char *c) {
    for ( ; *c ; c++ ) { 
        putchar( *c ) ; 
    }
    puts("") ; 
}

void test_void_ptr (void * arr_base , size_t sz) {

    

}

void test_tr_ptr_arr() {
    char cx[20] = { 'a' , 'b', 'c' , 'd', 'e' } ; 
    cx[3] = 'G' ;  
    char C[20] = "abc" ; 
    C[0] = 'M' ; 
    test_char_arr_pt( C ) ; 
    puts( cx ) ; 
}
int main() {  
    int a[100] = {0};
    int *pa = a;
    printf("array 'a' size = %ld,addr 'a' = %ls\n",sizeof(a),a) ; 
    int pap = a ;
    printf("%d\n",pap) ;
    return 0 ;
}
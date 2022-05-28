#include "int_qio.c" 

void qread_test() {
    int x = _qread() ;
    while(x != 99999999 ) {
        printf("%d\n",x) ;
        x = _qread() ; 
    }
}
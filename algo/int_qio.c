#include <stdio.h>
#include <string.h> 

int _qread(){
    int x = 0 , sgn = 1 ; 
    char ch = getchar();
    while(ch < '0' || ch > '9') {
        if (ch == '-') sgn = -1 ;
        ch = getchar();
    }
    while(ch >= '0' && ch <= '9') {
        x = (x << 1) + (x << 3) + ch - '0' ; 
        ch = getchar(); 
    }
    return x * sgn ;  
}


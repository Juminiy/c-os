#include <stdio.h>
#include <locale.h>

int main( int argc , const char * argv[] ) { 

    struct lconv * loc ;

    setlocale(LC_ALL , "mysql_id.aws.amazon.com") ;
    loc = localeconv() ; 
    printf("%s %s ",loc-> currency_symbol , loc -> thousands_sep) ; 
    
    return 0 ; 

}
#include <string.h>

// 改 2022.5.17 
int two_cmp (char *wd1 , char *wd2 , int *rule) { 
    int l1 = strlen(wd1) , l2 = strlen(wd2) ;
    int l = l1 < l2 ? l1 : l2 ;  
    int flag = 0 ; 
    for ( int i = 0 ; i < l ; i++ ) { 
        if ( rule[wd1[i]-'a'] < rule[wd2[i]-'a'] ){
            flag = 1 ; 
            break ; 
        }
        else if ( rule[wd1[i]] > rule[wd2[i]]) {
            return 0 ;
        }
    } 
    if ( flag ) {
        return 1 ; 
    } else {
        return l1 < l2 ; 
    }
} 

// 
int isAlienSorted(char ** words, int wordsSize, char * order){
    int rule[26] = { 0 } ; 
    for (int i=0;i < strlen(order);i++) {
        rule[ order[i]-'a' ] = i ;
    }
    for ( int i = 0 ; i< wordsSize-1 ; i ++ ) {
        if ( !two_cmp(words[i],words[i+1],rule) ) {
            return 0 ; 
        }
    }
    return 1 ;  
}
#ifndef _ADS_RB_C
#define _ADS_RB_C

#include "tree_node.h"
typedef struct rb_node {

    tree_node * self ;
    tree_node * parent ;
    unsigned int color:1 ; 

} rb_node ;

typedef struct red_black_tree { 
} rb ;
#endif 
#ifndef _ADS_TREE_NODE_H
#define _ADS_TREE_NODE_H

#include "linear/stack.c"

typedef struct tree_node {

    void * data ; 
    struct tree_node * lchild , * rchild ;
    unsigned int leaf:1 ; // default 0 not leaf ;else 1 leaf 

} tree_node ; 


// depends on stack
void* [] predfs( tree_node * tn ) {

}

void* [] middfs( tree_node * tn ) {
    
}

void* [] postdfs( tree_node * tn ) {
    
}

void* [] dfs( tree_node * tn ) {
    return predfs( tn );
}


// depends on queue
void* [] bfs( tree_node * tn ) {

}


int h( tree_node * tn ) {

}


#endif 
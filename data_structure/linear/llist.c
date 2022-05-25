
#ifndef _ADS_LLIST_C
#define _ADS_LLIST_C

#include <stdio.h> 
#include <stdlib.h>

typedef struct linked_node{
    int data;
    struct linked_node *next;
} ln ;

typedef struct linked_list{
    ln * head;
    ln * tail;
    int len;
} ll ;


ll* add_ll(ll * list,int data) { 
    ln * new_node = (ln*) malloc(sizeof(ln));
    new_node -> data = data ;
    new_node -> next = NULL ;
    if (list == NULL) {
        list = (ll *)malloc(sizeof(ll));
        list -> len = 0 ;
        list -> head = list -> tail = new_node;
    } else { 
        list -> tail -> next = new_node ;
        list -> tail = new_node ;   
    }
 
    list->len ++ ;
    return list ; 
}

ll* del_ll(ll * list,int key) {
    if (list == NULL ) {
        printf("Linkedlist is NULL,never can find key : %d\n",key);
    } else {
        ln * hd = (ln *) malloc(sizeof(ln));
        hd -> next =  list -> head ; 
        while(hd != NULL) { 
            if (hd -> next != NULL && hd -> next -> data == key) {
                ln * hnn = hd -> next -> next ; 
                free( hd -> next ) ;  
                hd -> next = hnn ;   
                break ; 
            }
            hd = hd -> next ; 
        }
    }
    return list ;
}

void tran_ll(ll *list) { 
    if (list != NULL) {
        ln * hd = list -> head ;
        printf("LinkedList [%p] :",list);
        while ( hd != NULL ) {
            printf(" %d -> ",hd->data);
            hd = hd -> next ; 
        }
    }
    printf("NULL\n");
}

#endif 
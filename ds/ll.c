#include <stdio.h> 
#include <stdlib.h>
typedef struct linkednode{
    int data;
    struct linkednode *next;
}ln;
typedef struct linkedlist{
    ln * head;
    ln * tail;
    int len;
} ll ;


ll* addll(ll * list,int data) { 
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

ll* delll(ll * list,int key) {
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

void tranll(ll *list) { 
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


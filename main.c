#include "linkedlist.h" 
#include "thread.h" 
ll * list =  NULL ;

void ll_opt(){
 for (int i=1;i<=10;i++) {
  list = addll(list,i);
 }
 tranll(list);
 delll(list,5);
 tranll(list);
}

int main(){ 
 create(ll_opt);
 create(ll_opt);
 return 0 ;
}

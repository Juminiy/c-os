#include "thread.h" 

int sgn = 1 ;
int up() {
 while(1) {
  sgn = 1 ;
  printf("up   finished sgn = %d\n",sgn);
 }
}
int down(){
 while(1) {
  sgn = 0 ;
  printf("down finished sgn = %d\n",sgn);
 }
}
int main(){ 
 create(up);
 create(down);
 return 0 ;
}

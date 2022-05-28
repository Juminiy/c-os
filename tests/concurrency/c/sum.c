#include "thread.h"
#define UNLOCK 0
#define LOCKED 1 
#define N 10000

long sum = 0;

int locked = UNLOCK ;
void Tsum() {
  retry :
  if (locked != UNLOCK) {
    goto retry ; 
  } 
  locked = LOCKED ; 
  sum ++ ; 
  locked = UNLOCK ; 
}

int main() {
  create(Tsum);
  create(Tsum);
  join();
  printf("sum = %ld\n", sum);
}

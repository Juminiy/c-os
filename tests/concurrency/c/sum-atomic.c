#include "thread.h"

#define N 100000000

atomic_llong sum = 0;

void Tsum() {
  for (int i = 0; i < N; i++) {
    asm volatile("lock addq $1, %0": "+m"(sum));
  }
}

void mySum() {
  for ( int i = 0; i < N ;i++)  {
    sum += 1;
  }
}
int main() {
  create(mySum);
  create(mySum);
  join();
  printf("sum = %lld\n", sum);
}

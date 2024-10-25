#include "thread.h"

int x = 0, y = 0;

void T1() {
  x = 1;
  asm volatile("" : : : "memory"); // compiler barrier
  printf("y = %d\n", y);
}

void T2() {
  y = 1;
  asm volatile("" ::: "memory"); // compiler barrier
  printf("x = %d\n", x);
}

void exe1(int id){
    T1();
}

void exe2(int id){
    T2();
}

int main(){
    create(exe1);
    create(exe2);
    join();
}

// y = 0, x = 1
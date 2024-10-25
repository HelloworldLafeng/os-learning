#include "thread.h"

int x = 0;

void Hello(int id)
{
    printf("Thread id: %d\n", id);
    usleep(100000 * id);
    printf("Hello world from thread: %c\n", "123456789ABCDEF"[x++]);
}

int main()
{
    for (int i=0; i<10; i++){
        create(Hello);
    }
}
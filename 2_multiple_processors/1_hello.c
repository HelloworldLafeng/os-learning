#include <stdio.h>
#include <pthread.h>

void *print_message_function( void *arg )
{
    char* message = (char*)arg;
    printf("%s\n", message);
    return NULL;
}

int main()
{
    pthread_t thread1, thread2;
    char *message1 = "Hello";
    char *message2 = "World";
    
    pthread_create(&thread1, NULL, print_message_function, (void*)message1);
    pthread_create(&thread2, NULL, print_message_function, (void*)message2);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    return 0;
}
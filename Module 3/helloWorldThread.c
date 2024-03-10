#include <stdio.h>
#include <pthread.h>

void* printHello(void* arg) {
    printf("Hello\n");
    pthread_exit(NULL);
}

void* printWorld(void* arg) {
    printf("World\n");
    pthread_exit(NULL);
}

int main() {
    pthread_t helloThread, worldThread;

    pthread_create(&helloThread, NULL, printHello, NULL);
    pthread_create(&worldThread, NULL, printWorld, NULL);

    pthread_join(helloThread, NULL);
    pthread_join(worldThread, NULL);

    return 0;
}

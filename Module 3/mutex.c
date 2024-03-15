#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int shared_counter = 0;

pthread_mutex_t mutex;

void* th(void* arg) {
    int thread_id = *(int*)arg;
    pthread_mutex_lock(&mutex);
    shared_counter++;
    printf("Thread %d: Shared counter = %d\n", thread_id, shared_counter);
    pthread_mutex_unlock(&mutex);
    pthread_exit(NULL);
}

int main() {
    pthread_mutex_init(&mutex, NULL);
    pthread_t thread1, thread2;
    int id1 = 1, id2 = 2;
    pthread_create(&thread1, NULL, th, &id1);
    pthread_create(&thread2, NULL, th, &id2);
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    pthread_mutex_destroy(&mutex);
    return 0;
}

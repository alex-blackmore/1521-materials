#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#include <stdatomic.h>

atomic_int global;

void *add_one(void *data) {
    atomic_fetch_add(&global, 1);
    return NULL;
}

int main(void) {
    global = 0;
    pthread_t *threads = malloc(sizeof(pthread_t) * 10000);
    for (int i = 0; i < 10000; i++) {
        pthread_create(&threads[i], NULL, add_one, NULL);
    }
    for (int i = 0; i < 10000; i++) {
        pthread_join(threads[i], NULL);
    }
    free(threads);
    printf("global=%d\n", global);
}




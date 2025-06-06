#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void *thread_run(void *data) {
    printf("I LOVE MIPS!\n");
    int *ret = malloc(sizeof(int));
    *ret = 17;
    return ret;
}

int main(void) {
    pthread_t thread;
    pthread_create(
        &thread,    // the pthread_t handle that will represent this thread
        NULL,       // thread-attributes -- we usually just leave this NULL
        thread_run, // the function that the thread should start executing
        NULL        // data we want to pass to the thread -- this will be
                    // given in the `void *data` argument above
    );
    void *result;
    pthread_join(thread, &result);
    printf("thread returned this number: %d\n", *((int*) result));
    return 0;
} 
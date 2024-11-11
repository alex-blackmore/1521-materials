#include <stdio.h>
#include <pthread.h>

void *thread_run(void *data) {
    printf("I LOVE MIPS!\n");

    return "MIPS";
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
    char *str;
    pthread_join(thread, (void**) &str);
    printf("%s\n", str);
    return 0;
}
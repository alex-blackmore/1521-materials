#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <pthread.h>

void *thread_run(void *data) {
    while (1) {
        sleep(1);
        printf("feed me input\n");
    }
    return NULL;
}

int main(void) {
    pthread_t p;
    pthread_create(&p, NULL, thread_run, NULL);

    while (1) {
        char buffer[1024];
        scanf("%s", buffer);
        printf("you entered %s\n", buffer);
    }

    // unreachable
    void *result;
    pthread_join(p, &result);
    return 0;
}
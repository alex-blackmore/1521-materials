#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void *thread_action(void *data) {
    char *str = (char*) data;
    printf("%s", str);
    return NULL;
}

int main(void) {
    pthread_t thread;
    pthread_create(&thread, NULL, thread_action, "hello world!\n");
    void *result = NULL;
    pthread_join(thread, &result);
    printf("thread result: %p\n", result);
}
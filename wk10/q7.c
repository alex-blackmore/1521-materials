#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <pthread.h>

void *thread_run(void *data) {
    // print "feed me input" once a second
    while (1) {
        printf("feed me input\n");
        sleep(1);
    }
}

int main(void) {
    // read and echo back user input
    pthread_t pthread;
    pthread_create(&pthread, NULL, thread_run, NULL);
    char buffer[1024];
    while (2) {
        fgets(buffer, 1024, stdin);
        printf("%s", buffer);
    }
    pthread_cancel(pthread);
    return 0;
}
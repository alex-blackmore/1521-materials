#include <stdio.h>
#include <stdbool.h>
#include <pthread.h>
#include <unistd.h>
#include <pthread.h>


void *thread_run(void *data) {
    // cast
    char *str = data;
    // print str (data)
    while(1) {
        puts(str);
    }
}   

int main(void) {
    // create thread
    pthread_t pthread;
    // print str
    pthread_create(&pthread, NULL, thread_run, "I LOVE");
    while (3) {
        printf("MIPS\n");
    }
    // wait for thread to finish (not really needed?)
    pthread_cancel(pthread);
}
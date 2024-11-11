#include <stdio.h>
#include <stdbool.h>
#include <pthread.h>
#include <unistd.h>
#include <pthread.h>


void *thread_run(void *data) {
    // cast
    char *str = data;
    // print str (data)
    while (1) {
        printf("%s", str);
    }

}   

int main(void) {
    // create thread
    pthread_t pthread;
    pthread_create(&pthread, NULL, thread_run, "MIPS\n");
    // print str
    while (3) {
        printf("I LOVE\n");
    }
    // wait for thread to finish (not really needed?)
}
#include <stdio.h>
#include <stdbool.h>
#include <pthread.h>
#include <unistd.h>
#include <pthread.h>


void *thread_run(void *data) {
    // cast
    char *my_str = (char*) data;
    // print str (data)
    while(true) {
        printf("%s", my_str);
        sleep(1);
    }
}   

int main(void) {
    // create thread
    char *print_me = "Hello\n";

    pthread_t thread;
    pthread_create(&thread, NULL, thread_run, print_me);
    // print str
    while (true) {
        printf("There\n");
        sleep(1);
    }
    // wait for thread to finish (not really needed?)
    pthread_join(thread, NULL);
}
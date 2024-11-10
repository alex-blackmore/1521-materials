#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main(void) {
    pid_t child_pid = fork();
    
    if (child_pid == 0) {
        // this is the child
        char * const argv[] = {"/bin/echo", "hello", "world", NULL};
        execve("/bin/echo", argv, NULL);
    } else {
        // this is the parent
        waitpid(child_pid, NULL, 0);
        printf("child process finished executing\n");
    }
}


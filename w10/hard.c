#include <stdlib.h>
#include <spawn.h>

int main(void) {
    pid_t pid;
    char * const argv[] = {"/bin/echo", "hello", "world", NULL};
    posix_spawn(&pid, "/bin/echo", NULL, NULL, argv, NULL);
    waitpid(pid, NULL, 0);
}


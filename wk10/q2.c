#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <spawn.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

extern char **environ;

void spawn_and_wait(char *args[]) {
    pid_t pid;
    posix_spawn(&pid, args[0], NULL, NULL, args, environ);
    waitpid(pid, NULL, 0);
}

// should we spawn all then wait all?

int main(int argc, char *argv[]) {
    // "date", "+%d-%m-%Y"

    // "date", "+%T"

    // "whoami"

    // "hostname"

    // "realpath ."

}

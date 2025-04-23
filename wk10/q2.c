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
    char *argv1[] = {"/bin/date", "+%d-%m-%Y", NULL};
    spawn_and_wait(argv1);
    // "date", "+%T"
    char *argv2[] = {"/bin/date", "+%T", NULL};
    spawn_and_wait(argv2);
    // "whoami"
    char *argv3[] = {"/usr/bin/whoami", NULL};
    spawn_and_wait(argv3);
    // "hostname"
    char *argv4[] = {"/bin/hostname", NULL};
    spawn_and_wait(argv4);
    // "realpath ."
    char *argv5[] = {"/bin/realpath", ".", NULL};
    spawn_and_wait(argv5);
}

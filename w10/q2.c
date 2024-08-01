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

void spawn_and_wait(char **args) {
    pid_t pid;
    posix_spawn(&pid, args[0], NULL, NULL, args, environ);
    waitpid(pid, NULL, 0);
}

int main(int argc, char *argv[]) {
    char *date_argv[] = {"/bin/date", "+%d-%m-%Y", NULL};
    spawn_and_wait(date_argv);

    char *time_argv[] = {"/bin/date", "+%T", NULL};
    spawn_and_wait(time_argv);

    char *user_argv[] = {"/usr/bin/whoami", NULL};
    spawn_and_wait(user_argv);

    char *hostname_argv[] = {"/bin/hostname", "-f", NULL};
    spawn_and_wait(hostname_argv);

    char *working_dir_argv[] = {"/usr/bin/realpath", ".", NULL};
    spawn_and_wait(working_dir_argv);
}
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <spawn.h>
#include <string.h>
#include <sys/wait.h>

extern char **environ;

struct posix_io_proc spawn_io_proc(char *command);

struct posix_io_proc {
    int input_fd;
    int output_fd;
    pid_t proc_id;
};

int main(int argc, char **argv) {

    if (argc < 2) {
        puts("require one argument");
        exit(1);
    }
    struct posix_io_proc io  = spawn_io_proc("cat");

    write(io.input_fd, argv[1], strlen(argv[1]));
    write(io.input_fd, argv[1], strlen(argv[1]));
    
    char buf2[1024] = {0};
    read(io.output_fd, buf2, strlen(argv[1]) * 2);

    // expect to see argv1 twice (cat will just send back to stdout what it recieves on stdin)
    puts(buf2);
    // close input pipe to signal EOF
    close(io.input_fd);
    // close output pipe for good measure (i dont like leaky code)
    close(io.output_fd);
    // wait for process to terminate
    waitpid(io.proc_id, NULL, 0);

    // success!
    return 0;

    return 0;
}

struct posix_io_proc spawn_io_proc(char *command) {
    pid_t proc_id;
    char *argv[] = {command, NULL};
    posix_spawn_file_actions_t file_actions;
    posix_spawn_file_actions_init(&file_actions);
    
    // pipe [fd0, fd1] ==> write into fd1 and then read from fd0
    #define READ 0
    #define WRITE 1
    #define STDIN 0
    #define STDOUT 1
    #define STDERR 2
    
    int input_pipe[2];
    pipe(input_pipe);
    int output_pipe[2];
    pipe(output_pipe);

    posix_spawn_file_actions_addclose(&file_actions, input_pipe[WRITE]);
    posix_spawn_file_actions_addclose(&file_actions, output_pipe[READ]);
    posix_spawn_file_actions_adddup2(&file_actions, input_pipe[READ], STDIN);
    posix_spawn_file_actions_adddup2(&file_actions, output_pipe[WRITE], STDOUT);
    posix_spawn_file_actions_adddup2(&file_actions, output_pipe[WRITE], STDERR);

    // posix_spawnp will use environ to find `cat` inside the passed in `$PATH`
    // if I use posix_spawn, I have to specify an absolute path to `/bin/cat`
    posix_spawnp(&proc_id, command, &file_actions, NULL, argv, environ);

    close(input_pipe[READ]);
    close(output_pipe[WRITE]);

    return (struct posix_io_proc) {
        .input_fd = input_pipe[WRITE],
        .output_fd = output_pipe[READ],
        .proc_id = proc_id
    };

}


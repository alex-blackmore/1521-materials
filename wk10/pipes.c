#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

extern char **environ;

struct piped_io {
    int input_pipe;
    int output_pipe;
    pid_t pid;
};

struct piped_io spawn_proc_with_io(char *path);

int main(int argc, char **argv) {
    if (argc < 2) {
        puts("require one argument");
        exit(1);
    }
    struct piped_io io_proc = spawn_proc_with_io("/bin/cat");

    write(io_proc.input_pipe, argv[1], strlen(argv[1]));
    write(io_proc.input_pipe, argv[1], strlen(argv[1]));
    char buf2[1024] = {0};
    read(io_proc.output_pipe, buf2, strlen(argv[1]) * 2);
    // expect to see argv1 twice
    puts(buf2);
    // close input pipe to signal EOF
    close(io_proc.input_pipe);
    // close output pipe for good measure
    close(io_proc.output_pipe);
    // wait for process to terminate
    waitpid(io_proc.pid, NULL, 0);
    // success!
    puts("success!!");
    return 0;
}

struct piped_io spawn_proc_with_io(char *path) {
    int output_pipe[2];
    int input_pipe[2];

    // pipe [fd0, fd1] ==> write into fd1 and then read from fd0

    if (pipe(output_pipe) != EXIT_SUCCESS) {
        perror("failed to create output pipe");
        exit(1);
    }

    if (pipe(input_pipe) != EXIT_SUCCESS) {
        perror("failed to create input pipe");
        exit(1);
    }

    pid_t child_pid = fork();

    if (child_pid == -1) {
        perror("fork failed");
        exit(1);
    }

    if (child_pid == 0) {
        // Child process
        close(input_pipe[1]); // close the writing end of the input pipe (for this process)
        close(output_pipe[0]); // close the reading end of the output pipe (for this process)

        dup2(input_pipe[0], 0); // make stdin file descriptor the same as the read end of the input pipe
        dup2(output_pipe[1], 1); // make stdout file descriptor the same as write end of the output pipe
        dup2(output_pipe[1], 2); // make stderr file descriptor the same as write end of the output pipe

        char *argv[] = {path, NULL};

        execve(path, argv, environ); 
        
        // process is now overwritten to be something else. we should never get here
        perror("execve: something went wrong");
        exit(1);
    } else {
        // Parent process
        close(input_pipe[0]); // close the reading end of the input pipe (for this process)
        close(output_pipe[1]); // close the writing end of the output pipe (for this process)

        return (struct piped_io) {
            .input_pipe = input_pipe[1],
            .output_pipe = output_pipe[0],
            .pid = child_pid
        };
    }
}
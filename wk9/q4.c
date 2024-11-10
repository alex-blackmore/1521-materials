// remove public write from specified as command line arguments if needed

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

void chmod_if_needed(char *pathname);

int main(int argc, char *argv[]) {
    for (int arg = 1; arg < argc; arg++) {
        chmod_if_needed(argv[arg]);
    }
    return 0;
}

// chmod a file if publically-writeable

void chmod_if_needed(char *pathname) {
    // stat the file
    struct stat s;
    int return_code = stat(pathname, &s);
    if (return_code != 0) {
        perror("stat");
        exit(1);
    }
    // chmod
    if (s.st_mode & S_IWOTH) {
        // bit is set
        printf("removing public write from %s\n", pathname);
        mode_t new_mode = s.st_mode & ~S_IWOTH; // write 0 to pwrite bit
        return_code = chmod(pathname, new_mode);
        if (return_code != 0) {
            perror("chmod");
            exit(1);
        }
    } else {
        // bit is not set
        printf("%s is not publically writable\n", pathname);
    }
    return;
}
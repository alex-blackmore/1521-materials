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
    struct stat s;
    int code = stat(pathname, &s);
    if (code != 0) {
        perror("stat");
    }
    if (s.st_mode & S_IWOTH) { // 0000 000 000 010
        // Remove write permissions
        uint32_t new_mode = s.st_mode & ~S_IWOTH;
        // Change the permissions
        printf("Removing write permission from file %s\n", pathname);
        printf("Old mode: %x\n", s.st_mode);
        printf("New mode: %x\n", new_mode);
        code = chmod(pathname, new_mode);
        if (code != 0) {
            perror("chmod");
        }
    }
    return;
}
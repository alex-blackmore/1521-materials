#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

void recursively_print(char *dir) {
    // Open directory
    DIR *dirp = opendir(dir);
    if (dirp == NULL) {
        perror("opendir");
        exit(1);
    }
    struct dirent *dirent;
    // Loop over all entries
    while ((dirent = readdir(dirp)) != NULL) {
        // Don't consider . or ..
        if (strcmp(dirent->d_name, ".") == 0/* || strcmp(dirent->d_name, "..") == 0*/) {
            continue;
        }
        // Construct full pathname
        char full_pathname[1024];
        snprintf(full_pathname, 1024, "%s/%s", dir, dirent->d_name);
        struct stat s;
        stat(full_pathname, &s);
        // Check file type
        if (S_ISDIR(s.st_mode)) {
            printf("%s\n", full_pathname);
            // Recurse
            recursively_print(full_pathname);
        } else {
            printf("%s\n", full_pathname);
        }
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        exit(1);
    }
    char *dir = argv[1];
    recursively_print(dir);
}
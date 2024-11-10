#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <string.h>

#define MAX_PATHNAME_LEN 256

void traverse_and_list(char *path);

int main(int argc, char **argv) {
    traverse_and_list(argv[1]);
}

void traverse_and_list(char *path) {
    // Open the directory
    DIR *dir = opendir(path);
    if (!dir) {
        perror("opendir");
        exit(1);
    }
    
    // Loop through entries
    struct dirent *entry;
    while ((entry = readdir(dir))) {
        char this_pathname[MAX_PATHNAME_LEN];
        snprintf(this_pathname, MAX_PATHNAME_LEN, "%s/%s", path, entry->d_name);

        struct stat s;
        stat(this_pathname, &s);

        printf("%s\n", this_pathname);

        if (S_ISDIR(s.st_mode)) {
            // Do not recurse into the current directory or the parent directory
            if (
                strncmp(entry->d_name, ".", MAX_PATHNAME_LEN) == 0
                || strncmp(entry->d_name, "..", MAX_PATHNAME_LEN) == 0) {
                
                continue;
            }

            // Recurse into directory and print those paths too
            traverse_and_list(this_pathname);
        }
    }

    // Close directory
    closedir(dir);
}


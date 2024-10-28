#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <sys/stat.h>

int main(void) {
    FILE *file_pointer = fopen("./test.txt", "r");
    if (file_pointer == NULL) {
        // perror will print out the system error message
        perror("fopen");
        exit(1);
    }

    uint8_t buffer[4];
    int bytes_read = fread(buffer, 1, 4, file_pointer);
    if (bytes_read != 4) {
        // Since no "error" actually occured, we can't use perror
        fprintf(stderr, "expected 4 bytes but only found %d\n", bytes_read);
        exit(1);
    }

    struct stat s;
    if (stat("./test.txt", &s) != 0) {
        // perror will print out system error message
        perror("stat");
        exit(1);
    }



    FILE *file_pointer = fopen("test.txt", "w");
    uint32_t number = 123456;
    // write one 4 byte number to file in ? endian order
    fwrite(&number, 4, 1, file_pointer);
    // ^^ DO NOT DO THIS!!!!
    fclose(file_pointer);
}





/*

    // Read from file
    FILE *file_pointer = fopen("./test.txt", "r");
    fclose(file_pointer);
    // Write to file (delete all existing data)
    file_pointer = fopen("./test.txt", "w");
    fclose(file_pointer);
    // Append to end of file
    file_pointer = fopen("./test.txt", "a");
    fclose(file_pointer);
    // Read and write to file (don't delete any existing data)
    file_pointer = fopen("./test.txt", "r+");
    fclose(file_pointer);
    // Read and write to file (delete any existing data)
    file_pointer = fopen("./test.txt", "w+");
    fclose(file_pointer);

    // Open file in write mode
    FILE *file_pointer = fopen("./test.txt", "w");
    // Write a single byte to the file (and move the file pointer forward 1 byte)
    fputc('A', file_pointer);
    // Write multiple bytes to the file (and move the file pointer forward 4 bytes)
    fwrite("ABCD", 1, 4, file_pointer);
    // Write a formatted string to the file (and move the file pointer forward 3 bytes)
    fprintf(file_pointer, "%d\n", 42);
    // Close the file
    fclose(file_pointer);

    // Open file in read mode
    FILE *file_pointer = fopen("./test.txt", "r");
    // Read one byte from the file (and move the file pointer 1 byte forwards)
    int byte = fgetc(file_pointer);
    // Check if we reached EOF (-1)?
    if (byte == EOF) {
        fprintf(stderr, "error: couldn't read one byte");
        return 1;
    }
    // Close the file
    fclose(file_pointer);


    // Open file in read mode
    FILE *file_pointer = fopen("test.txt", "r");
    // Read four bytes from the file (and move the file pointer 4 bytes forwards)
    uint8_t buffer[4];
    int bytes_read = fread(buffer, 1, 4, file_pointer);
    // Check if we read all four bytes (or if we hit EOF)
    if (bytes_read != 4) {
        fprintf(stderr, "error: couldn't read four bytes");
        return 1;
    }
    // Close the file
    fclose(file_pointer);

    // Open file in read mode
    FILE *file_pointer = fopen("./test.txt", "r");
    
    // Read one line from the file (at most 1024 bytes)
    // (and move the file pointer forward by the number of bytes read)
    char buffer[1024];
    fgets(buffer, 1024, file_pointer);

    // Close the file
    fclose(file_pointer);

    // Open the file in read mode
    FILE *file_pointer = fopen("./test.txt", "r");
    // file_pointer points to the first byte in the file (offset 0)

    // Move file_pointer to point at the last byte in the file (0 would be EOF)
    fseek(file_pointer, -1, SEEK_END);

    // Move file pointer to point at the third last byte in the file
    fseek(file_pointer, -3, SEEK_END);

    // Move the file pointer to point at the first byte in the file again
    fseek(file_pointer, 0, SEEK_SET);

    // Move the file pointer to point at the third byte in the file
    fseek(file_pointer, 3, SEEK_SET);

    // Move the file pointer forwards by 64 bytes
    fseek(file_pointer, 64, SEEK_CUR);

    // Move the file pointer backwards by 32 bytes
    fseek(file_pointer, -32, SEEK_CUR);

    // Close the file
    fclose(file_pointer);

    // Open file in read mode
    FILE *file_pointer = fopen("./test.txt", "r");
    // Read one line from the file
    char buffer[1024];
    fgets(buffer, 1024, file_pointer);
    // Check position of file pointer
    long offset = ftell(file_pointer);
    printf("file pointer now at %ld\n", offset);
    // Close file
    fclose(file_pointer);

    char *pathname = "./test.txt";
    struct stat s;
    stat(pathname, &s);
    int mode = s.st_mode;
    // Check if others have read permission
    if (mode & S_IROTH) {
        printf("others have read permission\n");
    }
    // Check if owner has execute permission
    if (mode * S_IXUSR) {
        printf("owner has execute permission\n");
    }
    // Check if file is a directory
    if (S_ISDIR(mode)) {
        printf("file is directory\n");
    }
    // Check if file is a regular file
    // (easier to use S_ISREG(mode))
    if ((mode & S_IFMT) == S_IFREG) {
        printf("file is a regular file\n");
    }

    char *pathname = "./test.txt";
    // Set read permission for all users, and write and execute only for file owner
    int mode = S_IROTH | S_IRGRP | S_IRUSR | S_IWUSR | S_IXUSR;
    chmod(pathname, mode);
    
    // Set the commonly used 0770 permission (read write and execute for user and group)
    chmod(pathname, 0770);

    // Add permission for all users to execute to the existing permission
    struct stat s;
    stat(pathname, &s);
    int new_mode = s.st_mode | S_IXOTH;
    chmod(pathname, new_mode);

*/

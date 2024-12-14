#include <fcntl.h>  // For open
#include <stdio.h>  // For printf, perror
#include <stdlib.h> // For free
#include "get_next_line.h"

int main() {
    // Open a test file for reading
    char *line;
    char *line2;
    // char *line3;
    // char *test;
    // char *test2;
    int fd = open("test.txt", O_RDONLY);
    // int fd2 = open("test2.txt", O_RDONLY);
    while ((line = get_next_line(fd)))
    {
        printf("%s\n", line);
        free(line);
    }

    // int fd = open("test_file2.txt", O_RDONLY);
    // int fd2 = open("test_file3.txt", O_RDONLY);
    // int fd3 = open("test_file3.txt", O_RDONLY);
    // line = get_next_line(fd);
    // line2 = get_next_line(fd2);
    // // line3 = get_next_line(fd3);
    // // test = get_next_line(fd);
    // // test2 = get_next_line(fd2);
    // printf("%s", line);
    // printf("%s", line2);
    // // printf("%s\n", line3);
    // // printf("%s\n", test);
    // // if (test2)
    // //     printf("%s\n", test2);
    // free(line);
    // free(line2);
    // // free(line3);
    // // free(test);
    // // free(test2);
    close(fd);
    // close(fd2);
    // close(fd3);
    // if (fd == -1) {  // If file can't be opened
    //     perror("Error opening file");  // Print error message
    //     return 1;  // Exit with failure
    // }

    // Read and print lines using get_next_line
    // char *line = (char *)1;
    // while (line) {  // Call get_next_line in a loop
    //     line = get_next_line(fd);
    //     printf("Read: %s", line);  // Print the line
    //     free(line);  // Free the memory allocated by get_next_line
    // }
    // line = get_next_line(fd);
    // printf("Read: %s", line);  // Print the line
    // free(line);

    // Close the file descriptor after reading
    // close(fd);

    return 0;  // Exit successfully
}


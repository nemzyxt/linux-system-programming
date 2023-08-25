#include <stdio.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>

void print_usage(FILE *stream, char progname[]);

int main(int argc, char *argv[]) {
    long int access_mode;

    if(argc != 3) {
        print_usage(stderr, argv[0]);
        return 1;
    }

    if(strspn(argv[1], "01234567") != strlen(argv[1]) || (strlen(argv[1]) != 3 && strlen(argv[1]) != 4)) {
        print_usage(stderr, argv[0]);
        return 1;
    }

    access_mode = strtol(argv[1], NULL, 8);

    if(chmod(argv[2], access_mode) == -1) {
        perror("Can't change permissions");
    }

    return 0;
}

void print_usage(FILE *stream, char progname[]) {
    fprintf(stream, "Usage: %s <numerical permissions> <path>\n", progname);
}

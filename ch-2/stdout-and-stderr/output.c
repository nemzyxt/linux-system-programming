#define _POSIX_C_SOURCE 200809L
#include <stdio.h>

int main(void) {
    printf("A regular message to stdout\n");

    // using streams with fprintf()
    fprintf(stdout, "Another regular message to stdout\n");
    fprintf(stderr, "An error message to stderr\n");

    // using file descriptors with dprintf()
    dprintf(1, "A regular message to fd 1\n");
    dprintf(2, "An error message to fd 2\n");

    return 0;
}

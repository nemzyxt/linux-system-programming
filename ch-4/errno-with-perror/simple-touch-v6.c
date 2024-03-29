#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <linux/limits.h>

int main(int argc, char *argv[]) {
    char filename[PATH_MAX] = {0};

    if(argc != 2) {
        fprintf(stderr, "You need to provide a filename as an argument\n");
        return 1;
    }

    strncpy(filename, argv[1], sizeof(filename)-1);
    if(creat(filename, 00644) == -1) {
        perror("Can't create file");
        return 1;
    }

    return 0;
}

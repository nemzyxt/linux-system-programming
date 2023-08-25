#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#define MAXSIZE 4096

int main(int argc, char *argv[]) {
    int fd;
    int maxread;
    off_t filesize;
    struct stat fileinfo; // struct for fstat
    char rbuf[MAXSIZE] = {0}; // the read buffer

    if(argc != 2) {
        fprintf(stderr, "Usage: %s [path]\n", argv[0]);
        return 1;
    }

    if((fd = open(argv[1], O_RDONLY)) == -1) {
        perror("Can't open file for reading");
        return 1;
    }

    fstat(fd, &fileinfo);
    filesize = fileinfo.st_size;

    if(filesize >= MAXSIZE) 
        maxread = MAXSIZE - 1;
    else 
        maxread = MAXSIZE;

    if((read(fd, rbuf, maxread)) == -1) {
        perror("Can't read file");
        return 1;
    }
    printf("%s\n", rbuf);

    return 0;
}

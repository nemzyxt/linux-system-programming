#include <stdio.h>

int main(int argc, char *argv[]) {
    FILE *fp;
    char line_buf[1024] = {0};

    if(argc != 2) {
        fprintf(stderr, "Usage: %s [path]\n", argv[0]);
        return 1;
    }

    while((fp = fopen(argv[1], "r")) == NULL) {
        perror("Can't open file for reading");
        return 1;
    }

    while(fgets(line_buf, sizeof(line_buf), fp) != NULL) {
        printf("%s", line_buf);
    }
    fclose(fp);

    return 0;
}

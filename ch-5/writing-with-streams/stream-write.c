#include <stdio.h>

int main(int argc, char *argv[]) {
    FILE *fp;
    char line_buf[1024] = {0};

    if(argc != 2) {
        fprintf(stderr, "Usage: %s [path]\n", argv[0]);
        return 1;
    }

    while((fp = fopen(argv[1], "w")) == NULL) {
        perror("Can't open file for writing\n");
        return 1;
    }

    while(fgets(line_buf, sizeof(line_buf), stdin) != NULL) {
        fprintf(fp, line_buf);
    }
    fclose(fp);

    return 0;
}

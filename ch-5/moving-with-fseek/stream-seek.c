#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int ch;
    FILE *fp;

    if(argc < 3 || argc > 4) {
        fprintf(stderr, "Usage: %s [path] [from_pos] [to_pos]\n", argv[0]);
        return 1;
    }

    if((fp = fopen(argv[1], "r")) == NULL) {
        perror("Can't open file for reading");
        return 1;
    }

    fseek(fp, atoi(argv[2]), SEEK_SET);
    while((ch = fgetc(fp)) != EOF) {
        if(argv[3] != NULL) {
            if(ftell(fp) >= atoi(argv[3])) {
                break;
            }
        }
        putchar(ch);
    }
    printf("\n");
    fclose(fp);

    return 0;
}

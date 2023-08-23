#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char buf[10] = {0};

    if(argc != 2) {
        fprintf(stderr, "Supply one argument\n");
        return 1;
    }

    strncat(buf, argv[1], sizeof(buf)-1);
    printf("Text : %s\n", buf);
    return 0;
}

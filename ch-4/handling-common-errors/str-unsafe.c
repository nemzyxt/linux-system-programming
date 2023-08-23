#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char buf[10] = {0};
    strcpy(buf, argv[1]);
    printf("Text : %s\n", buf);
    return 0;
}

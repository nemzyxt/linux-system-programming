#include <stdio.h>
#include <string.h>

int main(void) {
    char a[] = "Hello";
    char *b;
    b = strdup(a);
    printf("b = %s\n", b);
    return 0;
}

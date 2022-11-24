#include <stdio.h>

int main(void) {
    char c;
    for(c=65; c<=90; c++) {
        printf("%c = %d    ", c, c); // uppercase letters
        printf("%c = %d\n", c+32, c+32); // lowercase letters
    }

    return 0;
}
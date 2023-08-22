#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    printf("Your username is : %s\n", getenv("USER"));
    printf("Your home directory is : %s\n", getenv("HOME"));
    printf("Your shell is : %s\n", getenv("SHELL"));
    printf("Your preferred editor is : %s\n", getenv("EDITOR"));

    // check if current terminal supports colors
    if(strstr(getenv("TERM"), "256color")) {
        printf("\033[0;31mYour \033[0;32mterminal \033[0;33msupports \033[0;34mcolors\033[0m\n");
    } else {
        printf("Your terminal doesn't support colors\n");
    }

    return 0;
}

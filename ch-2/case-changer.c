#include <stdio.h>
#include <string.h>

int main(void) {
    int i;
    char c[20] = {0};
    char new_case[20] = {0};

    while(fgets(c, sizeof(c), stdin) != NULL) {
        for(i = 0; i <= sizeof(c); i++) {
            // uppercase to lowercase
            if(c[i] >= 65 && c[i] <= 90) {
                new_case[i] = c[i] + 32;
            }

            // lowercase to uppercase
            if(c[i] >= 97 && c[i] <= 122) {
                new_case[i] = c[i] - 32;
            }
        }
        printf("%s\n", new_case);

        // zero out the arrays
        memset(c, 0, sizeof(c));
        memset(new_case, 0, sizeof(new_case));
    }
}

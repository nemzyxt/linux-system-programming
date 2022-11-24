#include <stdio.h>
#include <string.h>

int main(void) {
    char c[20] = { 0 };
    char newcase[20] = { 0 };
    int i;

    while(fgets(c, sizeof(c), stdin) != NULL) {
        for(i=0; i<=sizeof(c); i++) {
            // uppercase to lowercase
            if((c[i]>=65) && (c[i]<=90)) {
                newcase[i] = c[i] + 32;
            }

            // lowercase to uppercase
            if((c[i]>=97) && c[i]<=122) {
                newcase[i] = c[i] - 32;
            }
        }

        printf("%s\n", newcase);

        // zero out the arrays to ensure there are no leftovers
        // in the next run
        memset(c, 0, sizeof(c));
        memset(newcase, 0, sizeof(newcase));

    }

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char mph[20] = {0};

    while(fgets(mph, sizeof(mph), stdin) != NULL) {
        // check whether mph is numeric and perform conversion
        if(strspn(mph, "0123456789.-\n") == strlen(mph)) {
            printf("%.1f\n", (atof(mph)*1.60934));
        } else {
            // mph is non-numeric
            fprintf(stderr, "Error : Found non-numeric value\n");
            return 1;
        }
    }

    return 0;
}

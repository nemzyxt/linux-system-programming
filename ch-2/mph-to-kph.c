#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char mph[10] = { 0 };
    while (fgets(mph, sizeof(mph), stdin) != NULL)
    {
        // check that mph is numeric and perform the conversion
        if(strspn(mph, "0123456789-\n") == strlen(mph)) {
            printf("%.1f\n", (atof(mph))*1.60934);
        } else {
            // output an error
            fprintf(stderr, "[!] Encountered a non-numeric value\n");
            return 1;
        }
    }

    return 0;
}
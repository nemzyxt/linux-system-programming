#define _XOPEN_SOURCE 500

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void printHelp(FILE *stream, char progname[]);

int main(int argc, char* argv[]) {
    char mph[10] = { 0 };
    int opt;
    int cont = 0;

    // parse the command-line options
    while((opt = getopt(argc, argv, "ch")) != -1) {
        switch (opt) {
            case 'h':
                printHelp(stdout, argv[0]);
                break;
            case 'c':
                cont = 1;
                break;
            default:
                printHelp(stderr, argv[0]);
                return 1;
        }
    }

    while(fgets(mph, sizeof(mph), stdin) != NULL) {
        if(strspn(mph, "0123456789.-\n") == strlen(mph)) {
            fprintf(stdout, "%.1f\n", (atof(mph))*1.60934);
        } else {
            fprintf(stderr, "[!] Encountered a non-numeric value\n");
            if(cont == 1) {
                continue;
            } else {
                return 1;
            }
        }
    }

    return 0;
}
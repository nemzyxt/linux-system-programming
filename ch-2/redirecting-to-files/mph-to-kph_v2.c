#define _XOPEN_SOURCE 500
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void print_help(FILE *stream, char progname[]);

int main(int argc, char *argv[]) {
    char mph[20] = {0};

    int opt, cont = 0;

    // parse command-line options
    while((opt = getopt(argc, argv, "hc")) != -1) {
        switch (opt) {
            case 'h':
                print_help(stdout, argv[0]);
                return 0;
            case 'c':
                cont = 1;
                break;
            default:
                print_help(stderr, argv[0]);
                return 1;
        }
    }

    while(fgets(mph, sizeof(mph), stdin) != NULL) {
        // check whether mph is numeric and perform conversion
        if(strspn(mph, "0123456789.-\n") == strlen(mph)) {
            printf("%.1f\n", (atof(mph)*1.60934));
        } else {
            // mph is non-numeric
            fprintf(stderr, "Error : Found non-numeric value\n");
            if(cont == 1)
                continue;
            else
                return 1;
        }
    }
}

void print_help(FILE *stream, char progname[]) {
    fprintf(stream, "%s [-c] [-h]\n", progname);
    fprintf(stream, "-c continue even after detecting a non-numeric value\n"
                    "-h print help\n");
}

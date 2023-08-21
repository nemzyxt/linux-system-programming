#include <stdio.h>
#include <stdlib.h>

void print_help(char progname[]);

int main(int argc, char *argv[]) {
    int i, sum = 0;

    if(argc == 1) {
        print_help(argv[0]);
        return 1;
    }

    for(i=1; i<argc; i++) {
        sum += atoi(argv[i]);
    }

    printf("Total Sum : %d\n", sum);
    return 0;
}

void print_help(char progname[]) {
    printf("%s integer ...\n", progname);
    printf("This program takes any number of integer values and sums them up\n");
}

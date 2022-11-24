#include <stdio.h>
#include <stdlib.h>

void printhelp(char progname[]);

int main(int argc, char* argv[]) {
    int i, sum = 0;

    if(argc == 1) {
        printhelp(argv[0]);
        return 1;
    }

    for(i=0; i<argc; i++) {
        sum += atoi(argv[i]);
    }

    printf("Total sum : %d\n", sum);
    return 0;
}

void printhelp(char progname[]) {
    printf("%s integer ... \n", progname);
    printf("This program takes any number of integer values"
           " as arguments and sums them up");
}
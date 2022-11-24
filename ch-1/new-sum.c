#define _XOPEN_SOURCE 500

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void printhelp(char progname[]);

int main(int argc, char* argv[]) {
    int i, opt, result;

    if(argc == 1) {
        printhelp(argv[0]);
        return 1;
    }

    while((opt = getopt(argc, argv, "smh")) != -1) {
        switch(opt) {
            case 's':
                result = 0;
                for(i=2; i<argc; i++) {
                    result += atoi(argv[i]);
                }
            case 'm':
                result = 1;
                for(i=2; i<argc; i++) {
                    result *= atoi(argv[i]);
                }
            case 'h':
                printhelp(argv[0]);
                return 0;
            default:
                printhelp(argv[0]);
                return 1;
        }
    }

    printf("The result is : %d", result);
    return 0;
}

void printhelp(char progname[]) {
    printf("%s [-s] [-m] integer ... \n", progname);
    printf("-s sums all the integers\n"
           "-m multiplies all the integers\n"
           "This program takes any number of integers and"
           "either sums or multiplies them\n"
           "eg. %s -m 5 4 3 2 1\n", progname);
}
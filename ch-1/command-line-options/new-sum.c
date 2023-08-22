#define _XOPEN_SOURCE 500
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void print_help(char progname[]);

int main(int argc, char *argv[]) {
    int i, result;
    char opt;

    if(argc == 1) {
        print_help(argv[0]);
        return 1;
    }

    while((opt = getopt(argc, argv, "smh")) != -1) {
        switch (opt) {
            case 's':
                result = 0;
                for(i=2; i<argc; i++)
                    result += atoi(argv[i]);
                break;

            case 'm':
                result = 1;
                for(i=2; i<argc; i++)
                    result *= atoi(argv[i]);
                break;

            case 'h':
                print_help(argv[0]);
                return 0;
            
            default:
                print_help(argv[0]);
                return 1;
        }
    }
    printf("Result : %d\n", result);
    return 0;
}

void print_help(char progname[]) {
    printf("%s [-s] [-m] integer ...\n", progname);
    printf("-s sums all integers\n"
        "-m multiplies all integers\n"
        "The program takes any number of integers and either sums or multiplies them\n"
        "Example : %s -s 5 5 5\n", progname);
}

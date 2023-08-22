#include <stdio.h>

void print_help(FILE *stream, char progname[]) {
    fprintf(stream, "Usage : %s [-c] [-r] [-t] [-h]\n"
                    "-c calculate the area of a circle\n"
                    "-r calculate the area of a rectangle\n"
                    "-t calculate the area of a triangle\n"
                    "Example : %s -t\n"
                    "Enter the height and width of the triangle : 5 9\n"
                    "22.500\n", progname, progname);

}

#define _XOPEN_SOURCE 700
#include <stdio.h>
#include <unistd.h>
#include "area.h"

int main(int argc, char *argv[]) {
    int opt;

    if(argc != 2) {
        print_help(stderr, argv[0]);
        return 1;
    }

    while((opt = getopt(argc, argv, "crth")) != -1) {
        switch (opt) {
            case 'c':
                if(circle() == -1) {
                    print_help(stderr, argv[0]);
                    return 1;
                }
                break;
            case 'r':
                if(rectangle() == -1) {
                    print_help(stderr, argv[0]);
                    return 1;
                }
                break;
            case 't':
                if(triangle() == -1) {
                    print_help(stderr, argv[0]);
                    return 1;
                }
                break;
            case 'h':
                print_help(stdout, argv[0]);
                return 0;
            default:
                print_help(stderr, argv[0]);
                return 1;
        }
    }
}

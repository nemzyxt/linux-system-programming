#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "prime.h"

int main(int argc, char *argv[]) {
    long int num;

    if(argc != 2) {
        fprintf(stderr, "Usage : %s number\n", argv[0]);
        return 1;
    }

    if(strspn(argv[1], "0123456789") != strlen(argv[1])) {
        fprintf(stderr, "Only numeric values are accepted\n");
        return 1;
    }

    num = atol(argv[1]);
    if(is_prime(num)) {
        printf("%ld is a prime number\n", num);
    } else {
        printf("%ld is not a prime number\n", num);
    }

    return 0;
}

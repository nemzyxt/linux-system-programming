// using return statements - Good

#include <stdio.h>

int func1(void);
int func2(void);

int main(int argc, char* argv[]) {
    printf("Inside main function\n");
    printf("Calling function 1 now\n");
    if(func1()) {
        printf("Everything OK from function one\n");
        printf("Return with 0 from main - All OK\n");
        return 0;
    } else {
        printf("Caught an error from function one\n");
        printf("Return with 1 from main - Error\n");
        return 1;
    }

    return 0;
}

int func1(void) {
    printf("Inside function 1\n");
    printf("Calling function 2 now\n");
    if(func2()) {
        printf("Everything OK from function two\n");
        return 1;
    } else {
        printf("Caught an error from function two\n");
        return 0;
    }
}

int func2(void) {
    printf("Inside function two\n");
    printf("Returning with error(0) from function two\n");
    return 0;
}
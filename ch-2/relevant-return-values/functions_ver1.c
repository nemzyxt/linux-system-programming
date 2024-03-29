// using return values

#include <stdio.h>

int func1(void);
int func2(void);

int main(void) {
    printf("Inside main\n");
    printf("Calling function one\n");

    if(func1()) {
        printf("Everything ok from function one\n");
        printf("Return with 0 from main - all ok\n");
        return 0;
    } else {
        printf("Caught an error from function one\n");
        printf("Return with 1 from main - error\n");
        return 1;
    }

    return 0;
}

int func1(void) {
    printf("Inside function one\n");
    printf("Calling function two\n");

    if(func2()) {
        printf("Everything ok from function two\n");
        return 1;
    } else {
        printf("Caught an error from function two\n");
        return 0;
    }
}

int func2(void) {
    printf("Inside function two\n");
    printf("Returning with 0(error) from function two\n");
    return 0;
}

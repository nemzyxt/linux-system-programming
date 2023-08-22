#include <stdio.h>

int triangle(void) {
    float base, height;

    printf("Enter the base and height of the triangle : ");
    if(scanf("%f %f", &base, &height)) {
        printf("%.3f\n", 0.5*base*height);
        return 1;
    } else {
        return -1;
    }
}

#define _XOPEN_SOURCE 700
#include <stdio.h>
#include <math.h>

int circle(void) {
    float radius;

    printf("Enter the radius of the circle : ");
    if(scanf("%f", &radius)) {
        printf("%.3f\n", M_PI*pow(radius,2));
        return 1;
    } else {
        return -1;
    }
}

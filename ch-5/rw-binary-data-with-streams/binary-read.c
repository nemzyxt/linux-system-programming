#include <stdio.h>

int main(void) {
    FILE *fp;
    float x[2];

    if((fp = fopen("my-binary-file", "rb")) == 0) {
        fprintf(stderr, "Can't open file for reading\n");
        return 1;
    }

    fread(&x, sizeof(x), sizeof(float)/sizeof(float), fp);
    printf("The first number : %f\n", x[0]);
    printf("The second number : %f\n", x[1]);
    fclose(fp);

    return 0;
}

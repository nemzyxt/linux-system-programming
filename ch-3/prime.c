int is_prime(long int number) {
    long int j;
    int prime = 1;

    for(j=2; j<number; j++) {
        if(number % j == 0) {
            prime = 0;
        }
    }

    if(prime == 1) {
        return 1;
    } else {
        return 0;
    }
}

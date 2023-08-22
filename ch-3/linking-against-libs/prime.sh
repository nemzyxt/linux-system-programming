#! /bin/bash

# compile the source into an object file
gcc -Wall -Wextra -pedantic -fPIC -c prime.c # output : prime.o

# package the object file as a library
gcc -shared -Wl,-soname,libprime.so -o libprime.so prime.o # output : libprime.so

# compile is-it-prime.c
gcc -L${PWD} -lprime is-it-prime.c -o is-it-prime

# set LD_LIBRARY_PATH env-var to out current path
export LD_LIBRARY_PATH=${PWD}:${LD_LIBRARY_PATH}

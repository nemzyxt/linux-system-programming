#! /bin/bash

# check for exactly one argument
if [ "$#" -ne 1 ]; then
    echo "You need to provide exactly one argument"
    echo "Example : $0 /etc"
    exit 1
fi

# check for existence of the file or directory
test -e "$1"

if [ "$?" -eq 0 ]; then
    echo "File or directory exists"
elif [ "$?" -eq 1 ]; then
    echo "File or directory doesn't exist"
    exit 3 # return error code
else
    echo "Unknown return value from test"
    exit 1
fi

exit 0

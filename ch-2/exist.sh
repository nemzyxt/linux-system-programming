#! /bin/bash

if [ "$#" -ne 1 ]; then
    echo "You must supply exactly one argument"
    echo "Example : $0 /etc"
    exit 1
fi

test -e "$1"
if [ "$?" -eq 0 ]; then
    echo "The file or directory exists"
    exit 0
elif [ "$?" -eq 1 ]; then 
    echo "The file or directory does not exist"
    exit 3 # a more specific exit code
else
    echo "Unknown return value from test !"
    exit 1
fi

exit 0 # if the file or directory exists
#! /bin/bash

# list all the symbolic links in the root directory

ls -l / | grep lrwx | awk '{ print $9 }' | sed 's/^/This is a link : /'
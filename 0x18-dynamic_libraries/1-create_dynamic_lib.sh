#!/bin/bash
gcc -Wall -pedantic -Werror -Wextra -pedantic -c -fPIC *.c
gcc -shared -0 liball.so *.o
export LD_LIBARY_PATH=.:$LD_LIBRARY_PATH

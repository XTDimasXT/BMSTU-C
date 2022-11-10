#!/bin/bash
gcc -std=gnu99 -Wall -Werror -Wpedantic -Wextra -c ./*.c -ggdb
gcc -o app.exe ./*.o -lm

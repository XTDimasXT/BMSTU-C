#!/bin/bash
gcc -std=c99 -Wall -Werror -Wpedantic -Wextra -c ./*.c
gcc -o app.exe ./*.o -lm

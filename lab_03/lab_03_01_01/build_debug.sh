#!/bin/bash
gcc -std=c99 -Wall -Werror -Wpedantic -Wextra -c main.c -ggdb
gcc -o app.exe main.o -lm

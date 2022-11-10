#!/bin/bash
gcc -std=c99 -Wall -Werror -Wpedantic -Wextra -c main.c
gcc -o app.exe main.o -lm

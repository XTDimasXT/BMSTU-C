#!/bin/bash
gcc -std=c99 -Wall -Werror main.c --coverage -o app.exe -lm

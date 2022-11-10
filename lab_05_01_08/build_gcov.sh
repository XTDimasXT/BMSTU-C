#!/bin/bash
gcc -std=c99 -Wall -Werror ./*.c --coverage -o app.exe -lm

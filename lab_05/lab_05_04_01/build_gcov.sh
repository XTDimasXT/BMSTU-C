#!/bin/bash
gcc -std=gnu99 -Wall -Werror ./*.c --coverage -o app.exe -lm

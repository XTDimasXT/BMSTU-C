#!/bin/bash
if diff -q "$1" "$2" &> /dev/null; then
	exit 0
fi
exit 1

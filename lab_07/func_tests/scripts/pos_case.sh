#!/bin/bash
if [ $# -lt 2 ]; then
	exit 1
fi
in="${1}"
out="${2}"
args=""

if [ $# -gt 2 ]; then
	args=$(cat "${3}")
fi

echo $3
echo $args

if [ -n "$USE_VALGRIND" ]; then
	eval "valgrind --log-file=valgrind_log ./app.exe ./'$args'"
else
	eval "./app.exe ./'$args' > ./func_tests/test.txt"
fi
if test $? -ne 0; then
	exit 1
fi

temp1=$(cat "$out")
temp2=$(cat "./func_tests/test.txt")
echo "$temp1"
echo "$temp2"

bash ./func_tests/scripts/comparator.sh "$out" ./func_tests/test.txt
if test $? -eq 0; then
	exit 0
else
	exit 1
fi

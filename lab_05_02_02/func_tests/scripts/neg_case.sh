#!/bin/bash
if [ $# -lt 1 ]; then
	exit 1
fi
in="${1}"
args=""

if [ $# -gt 1 ]; then
	args="${2}"
fi

if [ -n "$USE_VALGRIND" ]; then
	eval "valgrind --log-file=valgrind_log ../../app.exe $in > ./out.txt $args"
else
	eval "../../app.exe $in > ./out.txt $args"
fi

if test $? -ne 0; then
	exit 0
else
	exit 1
fi

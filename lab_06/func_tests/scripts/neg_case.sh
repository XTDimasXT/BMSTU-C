#!/bin/bash
if [ $# -lt 1 ]; then
	exit 1
fi
in="${1}"
args=""
if [ $# -gt 1 ]; then
	args=$(cat "${2}")
fi

if [ -n "$USE_VALGRIND" ]; then
	eval "valgrind --log-file=valgrind_log ../../app.exe ../../'$args'"
else
	eval "../../app.exe ../../$args &> /dev/null"
fi


if test $? -ne 0; then
	exit 0
else
	exit 1
fi

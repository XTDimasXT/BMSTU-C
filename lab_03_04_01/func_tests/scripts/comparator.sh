#!/bin/bash
regular="[+-]?([[:digit:]]+[.])?[[:digit:]]+"
temp1=$(grep -oE "$regular" "$1")
temp2=$(grep -oE "$regular" "$2")

if [[ -z "$temp1" ]] && [[ -z "$temp2" ]]; then
	exit 1
fi

if [ "$temp1" = "$temp2" ]; then
	exit 0
else
	exit 1
fi
exit 1

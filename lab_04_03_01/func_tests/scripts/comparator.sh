#!/bin/bash
regular="(^Result:[[:space:]])([A-Za-z0-9][A-Za-z0-9]*[[:space:]]*)*"
temp1=$(grep -oE "$regular" "$1")
temp2=$(grep -oE "$regular" "$2")
temp1=${temp1:8}
temp2=${temp2:8}

if [[ -z "$temp1" ]] && [[ -z "$temp2" ]]; then
	exit 1
fi

if [ "$temp1" = "$temp2" ]; then
	exit 0
else
	exit 1
fi
exit 1

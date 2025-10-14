#!/bin/bash
cat unsorted.txt | sort -n > shell_sorted.txt
DIFF=`diff sorted.txt shell_sorted.txt --color=auto -u`
if [ -z "$DIFF" ]; then
	echo "No difference found!"
else
	echo "Difference found:"
	diff sorted.txt shell_sorted.txt --color=auto -u
fi
rm shell_sorted.txt

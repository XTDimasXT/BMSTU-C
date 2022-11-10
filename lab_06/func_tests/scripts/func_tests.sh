#!/bin/bash
pos_l=$(find ../data/ -name "pos_[[:digit:]][[:digit:]]_in.txt" | wc -l)
i=1
while [ $i -le $pos_l ]; do
	bash pos_case.sh "../../func_tests/data/pos_0${i}_in.txt" "../../func_tests/data/pos_0${i}_out.txt" "../../func_tests/data/pos_0${i}_args.txt"
	if test "$?" -eq 0; then
		echo -e TEST "$i": '\033[0;32mPASS\033[0;37m'
	else
		echo -e TEST "$i": '\033[0;31mFAIL\033[0;37m'
	fi
	i=$((i+1))
done


k=$i
i=1
neg_l=$(find ../data/ -name "neg_[[:digit:]][[:digit:]]_in.txt" | wc -l)
while [ $i -le "$neg_l" ]; do
	bash neg_case.sh "../../func_tests/data/neg_0${i}_in.txt" "../../func_tests/data/neg_0${i}_args.txt"
	if test "$?" -eq 0; then
		echo -e TEST "$i": '\033[0;32mPASS\033[0;37m'
	else
		echo -e TEST "$i": '\033[0;31mFAIL\033[0;37m'
	fi
	k=$((k+1))
	i=$((i+1))
done

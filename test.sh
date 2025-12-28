#!/bin/bash

make test
for infile in test/in*; do
    [[ -f "$infile" ]] || continue

    filename="$(basename "$infile")"
    suffix="${filename#in}"
    outfile="test/out$suffix"

    if [[ ! -f "$outfile" ]]; then
        continue
    fi

    echo -n "$filename : "
    if diff -qw <(./main < "$infile") "$outfile" > /dev/null; then
        echo -e "\e[92mPASS\e[0m"
    else
        echo -e "\e[91mFAIL\e[0m"
        diff <(./main < "$infile") "$outfile"
    fi
done

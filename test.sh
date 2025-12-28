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
        echo "PASS"
    else
        echo "FAIL"
        diff <(./main < "$infile") "$outfile"
    fi
done

for impl in cstyle iterstyle rangestyle; do
    for opt in O0 O1 O2 O3; do
	for n in 100 1000 10000 100000 1000000; do
	    ./$impl.$opt $n >> $impl.$opt.dat
	done
    done
done

for impl in cstyle iterstyle rangestyle; do
    for opt in O0 O1 O2 O3; do
	g++ --std=c++11 -$opt -S $impl.cpp -o $impl.$opt.s
	g++ --std=c++11 -$opt $impl.cpp -o $impl.$opt
    done
done

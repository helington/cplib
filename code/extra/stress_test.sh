P=code   # variable for code file
Q=brute  # variable for brute force code file

g++ ${P}.cpp -o sol -O2 -std=c++17 || exit 1
g++ ${Q}.cpp -o brt -O2 -std=c++17 || exit 1
g++ gen.cpp  -o gen -O2 -std=c++17 || exit 1

for ((i = 1; ; i++)) do
	echo $i
	./gen $i > in
	./sol < in > out
	./brt < in > out2
	if (! cmp -s out out2) then
		echo "--> input:"
		cat in
		echo "--> output code:"
		cat out
		echo "--> output brute:"
		cat out2
		break;
	fi
done
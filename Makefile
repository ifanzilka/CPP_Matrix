

all:
	clang++ -Iincludes main.cpp src/CPP_Matrix.cpp -o test

test:
	clang++ -Iincludes main.cpp src/CPP_Matrix.cpp && ./a.out

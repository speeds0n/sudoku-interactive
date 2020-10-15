all:
	g++ -Wall -std=c++11 -c src/sudoku.cpp -o sudoku.o
	g++ -Wall -std=c++11 -O sudoku.o main.cpp -o sudoku
run:
	./sudoku
rl:
	rm sudoku.o
	rm sudoku

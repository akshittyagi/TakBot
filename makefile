all: main1.o Board.o
	g++ main1.o Board.o
main1.o: main1.cpp Board.h
	g++ -std=c++11 -c main1.cpp
Board.o: Board.cpp Board.h
	g++ -c Board.cpp
test:
	g++ -O3 -std=c++11 main1.cpp -o out
	./out

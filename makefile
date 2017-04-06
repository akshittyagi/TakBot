all:
	clang++ -O3 -std=c++11 -pg mainFile.cpp -o out1
main1.o: main1.cpp Board.h
	g++ -std=c++11 -c main1.cpp
Board.o: Board.cpp Board.h
	g++ -c Board.cpp
test:
	./out1
clean:
	rm out*
	rm *.out
	rm *.o

all: test hash1 hash2 hash3

test: test_hash_table.o
	g++ -std=c++11 -o test test_hash_table.o

test_hash_table.o: test_hash_table.cpp
	g++ -std=c++11 -c test_hash_table.cpp
	
hash3: main.cpp Board.h Board.cpp hash_table.h hash_table.cpp 
	g++ -std=c++11 -o hash3 -DHASHFUNCTION3 main.cpp Board.cpp

hash2: main.cpp Board.h Board.cpp hash_table.h hash_table.cpp 
	g++ -std=c++11 -o hash2 -DHASHFUNCTION2 main.cpp Board.cpp

hash1: main.cpp Board.h Board.cpp hash_table.h hash_table.cpp 
	g++ -std=c++11 -o hash1 -DHASHFUNCTION1 main.cpp Board.cpp

clean:
	rm -f test hash1 hash2 hash3 *.o

all: test

test: test_set.o
	g++ -o test test_set.o
	
test_set.o: test_set.cpp
	g++ -c test_set.cpp

clean:
	rm -f test *.o
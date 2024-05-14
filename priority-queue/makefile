# Makefile for project 2
#************************

all: test usecase # Makes it so it creates 2 executables when doing make

test: test_minqueue.o
	g++ -o test test_minqueue.o

test_minqueue.o: test_minqueue.cpp
	g++ -c test_minqueue.cpp

usecase: usecase.o
	g++ -o usecase usecase.o

usecase.o: main.cpp
	g++ -c -o usecase.o main.cpp

clean:
	rm -f test usecase *.o
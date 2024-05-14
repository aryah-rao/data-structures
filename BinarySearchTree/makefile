all: test usecase # Makes it so it creates 2 executables when doing make

test: test_bst.o
	g++ -o test test_bst.o

test_bst.o: test_bst.cpp
	g++ -c test_bst.cpp

usecase: usecase.o
	g++ -o usecase usecase.o

usecase.o: main.cpp
	g++ -c -o usecase.o main.cpp

clean:
	rm -f test usecase *.o
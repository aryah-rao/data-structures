# Priority Queue Implementation in C++

This project provides an implementation of a Min Priority Queue data structure in C++. The Min Priority Queue is implemented as a templated class, allowing it to store elements of any data type.

## Features

- Insert elements into the Min Priority Queue
- Get the minimum element from the Min Priority Queue
- Extract the minimum element from the Min Priority Queue
- Decrease the value of an element at a specific index
- Perform Min Heapify operation to maintain the heap property
- Build a Min Heap from an unsorted array
- Sort an array using Heap Sort
- Convert the Min Priority Queue to a string representation
- Set the value at a specific index in the Min Priority Queue
- Allocate space for a specific number of elements in the Min Priority Queue

## Files

- `minqueue.h`: Header file containing the declaration of the MinQueue class and its member functions.
- `minqueue.cpp`: Implementation file containing the definitions of the MinQueue class member functions.
- `test_minqueue.cpp`: Test file containing various test cases to verify the correctness of the Min Priority Queue implementation.
- `usecase.h`: Header file containing the declaration of the sliding window problem solution function.
- `usecase.cpp`: Implementation file containing the definition of the sliding window problem solution function.

## Usage

1. Include the `minqueue.h` header file in your C++ program.
2. Create an instance of the MinQueue class, specifying the desired data type as the template argument.
3. Use the provided member functions to perform operations on the Min Priority Queue, such as insertion, extraction, and querying.
4. Compile and run your program along with the `minqueue.cpp` file to link the Min Priority Queue implementation.

## Testing

The `test_minqueue.cpp` file contains a comprehensive set of test cases to verify the correctness of the Min Priority Queue implementation. It includes tests for various operations such as insertion, minimum element retrieval, minimum element extraction, decreasing key, min heapify, building a min heap, heap sort, and the sliding window problem.

To run the tests, compile and run the `test_minqueue.cpp` file along with the `minqueue.cpp` and `usecase.cpp` files.

## Use Case: Sliding Window Problem

The project includes a solution for the Sliding Window Problem using the Min Priority Queue. The sliding window function takes an array, its length, and the window size as input and returns a string representing the minimum elements within each window cycle.

The implementation of the sliding window function can be found in the `usecase.cpp` file, and its header is declared in the `usecase.h` file. 

## Time Complexity

The Min Priority Queue implementation provides efficient time complexity for various operations:

- Insertion: O(log n)
- Minimum element retrieval: O(1)
- Minimum element extraction: O(log n)
- Decreasing key: O(log n)
- Min Heapify: O(log n)
- Building a Min Heap: O(n)
- Heap Sort: O(n log n)

where n is the number of elements in the Min Priority Queue.

## Contributors

- Dr. Stacey Truex
- Aryah Rao

## License

This repository is licensed under the [MIT License](LICENSE).

Feel free to use, modify, and distribute this Min Priority Queue implementation.

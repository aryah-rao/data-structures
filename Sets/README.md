# Set Implementation in C++

This project provides an implementation of a Set data structure in C++ (using Linked Lists). The Set is implemented as a templated class, allowing it to store elements of any data type.

## Features

- Insert elements into the Set
- Remove elements from the Set
- Check the cardinality (size) of the Set
- Check if the Set is empty
- Check if the Set contains a specific element
- Perform equality comparison between two Sets
- Check if one Set is a subset of another
- Perform union operation between two Sets
- Perform intersection operation between two Sets
- Perform difference operation between two Sets
- Convert the Set to a string representation

## Files

- `set.h`: Header file containing the declaration of the Set class and its member functions.
- `set.cpp`: Implementation file containing the definitions of the Set class member functions.
- `test_set.cpp`: Test file containing various test cases to verify the correctness of the Set implementation.

## Usage

1. Include the `set.h` header file in your C++ program.
2. Create an instance of the Set class, specifying the desired data type as the template argument.
3. Use the provided member functions to perform operations on the Set, such as insertion, removal, and querying.
4. Compile and run your program along with the `set.cpp` file to link the Set implementation.

## Testing

The `test_set.cpp` file contains a comprehensive set of test cases to verify the correctness of the Set implementation. It includes tests for various operations such as insertion, removal, cardinality, emptiness, element existence, equality, subset, union, intersection, and difference. The test file also includes tests for different data types like integers, characters, and strings.

To run the tests, compile and run the `test_set.cpp` file along with the `set.cpp` file.

## Time Complexity

The Set implementation provides efficient time complexity for various operations:

- Insertion: O(1) average case, O(n) worst case
- Removal: O(n)
- Cardinality: O(1)
- Emptiness: O(1)
- Element existence: O(n)
- Equality comparison: O(n)
- Subset check: O(n)
- Union: O(n)
- Intersection: O(n)
- Difference: O(n)

where n is the number of elements in the Set.

## Contributors

- Dr. Stacey Truex
- Aryah Rao

Feel free to use, modify, and distribute this Set implementation as per the terms of the license.
# Binary Search Tree Implementation in C++

This project provides an implementation of a Binary Search Tree (BST) data structure in C++. The BST is implemented as a templated class, allowing it to store elements of any data type for both the key and the associated data. 

## Features

- Insert elements into the BST
- Get the data associated with a given key
- Remove elements from the BST
- Get the maximum data and key in the BST
- Get the minimum data and key in the BST
- Find the successor of a given key
- Get the keys in non-descending order (in-order traversal)
- Trim the BST within a specified key range
- Convert the BST to a string representation

## Files

- `bst.h`: Header file containing the declaration of the BST class and its member functions.
- `bst.cpp`: Implementation file containing the definitions of the BST class member functions.
- `usecase.cpp`: Implementation file containing the solution for the hexadecimal conversion problem using the BST.
- `main.cpp`: Example file demonstrating the usage of the BST and the hexadecimal conversion problem.
- `test_bst.cpp`: Test file containing various test cases to verify the correctness of the BST implementation.

## Usage

1. Include the `bst.h` header file in your C++ program.
2. Create an instance of the BST class, specifying the desired data types for the key and the associated data as template arguments.
3. Use the provided member functions to perform operations on the BST, such as insertion, removal, and querying.
4. Compile and run your program along with the `bst.cpp` file to link the BST implementation.

## Use Case: Binary to Hexadecimal Conversion

The project includes a solution for converting binary numbers to their hexadecimal representation using the BST. The solution reads a CSV file (`binhex.txt`) containing binary-hexadecimal pairs and builds a BST based on the data. It then provides a function (`convert`) to convert a given binary number to its hexadecimal representation using the BST.

The implementation of the binary to hexadecimal conversion can be found in the `usecase.cpp` file, and an example usage is demonstrated in the `main.cpp` file.

## Testing

The `test_bst.cpp` file contains a comprehensive set of test cases to verify the correctness of the BST implementation. It includes tests for various operations such as insertion, removal, getting data, finding the maximum and minimum elements, finding the successor, in-order traversal, trimming the BST, and the binary to hexadecimal conversion use case.

To run the tests, compile and run the `test_bst.cpp` file along with the `bst.cpp` and `usecase.cpp` files.

## Time Complexity

The BST implementation provides the following time complexities for various operations:

- Insertion: O(log n) average case, O(n) worst case
- Removal: O(log n) average case, O(n) worst case
- Get data: O(log n) average case, O(n) worst case
- Get maximum: O(log n) average case, O(n) worst case
- Get minimum: O(log n) average case, O(n) worst case
- Find successor: O(log n) average case, O(n) worst case
- In-order traversal: O(n)
- Trim: O(n)

where n is the number of elements in the BST.

## Contributors

- Dr. Stacey Truex
- Aryah Rao

## License

This repository is licensed under the [MIT License](LICENSE).

Feel free to use, modify, and distribute this BST implementation.

# Hash Table Implementation and Analysis

This project focuses on implementing a hash table data structure and analyzing the performance of different hash functions. The hash table is implemented as a vector of doubly linked lists, where each element in the hash table is represented by a templated `Element` class that stores data and a corresponding key.

## Features

- Templated `Element` class for storing data and key pairs
- Templated `HashTable` class for managing the hash table operations
- Support for inserting, removing, and checking membership of elements in the hash table
- Three different hash functions implemented for performance comparison
- Analysis of hash table metrics such as number of unique elements, average items per slot, standard deviation, and minimum/maximum slot counts
- Comprehensive test suite for verifying the correctness of the hash table implementation

## Files

- `hash_table.h`: Header file containing the class definitions for `Element` and `HashTable`
- `hash_table.cpp`: Implementation file for the `Element` and `HashTable` classes
- `Board.h`: Header file for the `Board` class used in the Rush Hour game
- `Board.cpp`: Implementation file for the `Board` class
- `test_hash_table.cpp`: Test file for verifying the correctness of the hash table implementation

## Usage

1. Include the `hash_table.h` header file in your C++ source code.
2. Create an instance of the `HashTable` class with the desired size.
3. Use the provided member functions to insert, remove, and check membership of elements in the hash table.
4. Optionally, you can analyze the performance of the hash table by calling the `analyze()` member function, which generates a CSV file with slot count information and prints metrics to the console.

## Hash Functions

The project includes three different hash functions implemented in the `Board` class:

1. `HASHFUNCTION1`: A naive hash function that combines board indices and cell values using prime numbers and basic arithmetic operations.
2. `HASHFUNCTION2`: An improved hash function that uses the multiplication method and a combination of board indices and cell values.
3. `HASHFUNCTION3`: The best-performing hash function that incorporates divisibility checks, prime numbers, and the multiplication method to achieve better distribution and fewer collisions.

To switch between the hash functions, you can define the corresponding macro (`HASHFUNCTION1`, `HASHFUNCTION2`, or `HASHFUNCTION3`) in the `Board.cpp` file.

## Testing

The project includes a comprehensive test suite in the `test_hash_table.cpp` file. The test cases cover various scenarios and edge cases to ensure the correctness of the hash table implementation. To run the tests, compile and execute the `test_hash_table.cpp` file.

## Analysis

The `analyze()` member function of the `HashTable` class generates a CSV file named `hash_table_slots.csv` that contains the slot counts for each slot in the hash table. It also prints the following metrics to the console:

- Total number of unique elements
- Average number of items per slot
- Minimum slot count
- Maximum slot count
- Standard deviation of the slot counts

These metrics can be used to evaluate the performance and distribution of the hash functions.

## Contributors

- Dr. Matt Kretchmar
- Dr. Stacey Truex
- Aryah Rao

## License

This repository is licensed under the [MIT License](LICENSE).

Feel free to use, modify, and distribute this Hash Table implementation.
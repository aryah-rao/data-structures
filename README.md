# Data Structures and Algorithms

This repository contains a collection of data structure and algorithm implementations in C++, designed to provide a comprehensive resource for learning and utilizing fundamental concepts in your projects. Each data structure and algorithm is implemented in a separate directory, making it easy to navigate and explore the code.

## Table of Contents
- [Set](#set)
- [Priority Queue](#priority-queue)
- [Hash Table](#hash-table)
- [Graph](#graph)
- [Binary Search Tree](#binary-search-tree)

## Set (Linked List)
The `set` directory contains an implementation of a Set data structure using Linked Lists. It provides various operations such as insertion, removal, cardinality, emptiness check, element existence, equality comparison, subset check, union, intersection, and difference. The Set implementation is templated, allowing it to store elements of any data type.

## Priority Queue
The `priority-queue` directory includes an implementation of a Min Priority Queue data structure. It supports operations like insertion, minimum element retrieval, minimum element extraction, decreasing key, min heapify, building a min heap, and heap sort. The Min Priority Queue is templated, enabling it to store elements of any data type. Additionally, it includes a solution for the Sliding Window Problem using the Min Priority Queue.

## Hash Table
The `hash-table` directory provides an implementation of a Hash Table data structure along with an analysis of different hash functions. The Hash Table is implemented as a vector of doubly linked lists, where each element is represented by a templated `Element` class that stores data and a corresponding key. It supports insertion, removal, and membership checking operations. The project includes three different hash functions for performance comparison and analysis.

## Binary Search Tree
The `binary-search-tree` directory includes an implementation of a Binary Search Tree (BST) data structure. The BST is implemented as a templated class, supporting elements of any data type for both the key and the associated data. It provides operations like insertion, removal, data retrieval, maximum and minimum element finding, successor finding, in-order traversal, and trimming the BST within a specified key range. Additionally, it includes a use case for converting binary numbers to their hexadecimal representation using the BST.

## Graph
The `graph` directory contains an implementation of a Graph data structure. The Graph is implemented as a templated class, allowing it to store elements of any data type for both the key and the associated data. It provides various operations such as constructing a graph from keys, data, and edges, reachability checking, breadth-first search (BFS), shortest path finding, edge classification, BFS tree printing, and depth-first search (DFS).

Each data structure and algorithm directory contains its own README file with detailed explanations, usage instructions, and examples. The implementations are thoroughly tested using comprehensive test suites to ensure correctness and robustness.

Feel free to explore the code, contribute improvements, and utilize these implementations in your own projects. Happy coding!

## Contributors
- Dr. Stacey Truex
- Dr. Matt Kretchmar
- Aryah Rao

## License
This repository is licensed under the [MIT License](LICENSE).

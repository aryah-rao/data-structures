# Graph Implementation in C++

This project provides an implementation of a Graph data structure in C++. The Graph is implemented as a templated class, allowing it to store elements of any data type for both the key and the associated data. 

## Features

- Construct a Graph from a set of keys, data, and edges
- Get a pointer to a vertex based on its key
- Check if a vertex is reachable from another vertex
- Perform breadth-first search (BFS) starting from a given source vertex
- Print the shortest path between two vertices
- Classify the type of edge between two vertices (tree edge, back edge, forward edge, cross edge, or no edge)
- Print the BFS tree starting from a given source vertex
- Perform depth-first search (DFS) on the entire graph

## Files

- `graph.h`: Header file containing the declaration of the Graph class and its member functions.
- `graph.cpp`: Implementation file containing the definitions of the Graph class member functions.
- `graph_description.txt`: Text file containing a sample graph description used for testing.
- `test_graph.cpp`: Test file containing various test cases to verify the correctness of the Graph implementation.

## Usage

1. Include the `graph.h` header file in your C++ program.
2. Create an instance of the Graph class, specifying the desired data types for the key and the associated data as template arguments.
3. Construct the Graph by providing the keys, data, and edges as vectors.
4. Use the provided member functions to perform operations on the Graph, such as reachability checking, BFS, shortest path finding, edge classification, and BFS tree printing.
5. Compile and run your program along with the `graph.cpp` file to link the Graph implementation.

## Testing

The `test_graph.cpp` file contains a comprehensive set of test cases to verify the correctness of the Graph implementation. It includes tests for various operations such as getting vertices, reachability checking, BFS, shortest path finding, edge classification, and BFS tree printing.

The test cases cover different data types for both keys and associated data, including integers, floating-point numbers, characters, and strings. The test file also includes a sample graph description file (`graph_description.txt`) for testing purposes.

To run the tests, compile and run the `test_graph.cpp` file along with the `graph.cpp` file.

## Time Complexity

The Graph implementation provides the following time complexities for various operations:

- Constructor: O(V + E), where V is the number of vertices and E is the number of edges
- Get vertex: O(1)
- Reachability check: O(V + E)
- BFS: O(V + E)
- Shortest path: O(V + E)
- Edge classification: O(1)
- BFS tree printing: O(V + E)
- DFS: O(V + E)

## Contributors

- Dr. Stacey Truex
- Aryah Rao

## License

This repository is licensed under the [MIT License](LICENSE).

Feel free to use, modify, and distribute this Graph implementation.

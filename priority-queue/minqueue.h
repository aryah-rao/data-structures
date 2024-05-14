//=================================
// Aryah Rao
// minqueue.h
// Feb 2024
// This file contains the class template header for min-priority queue.
//=================================

#ifndef MINQUEUE_H
#define MINQUEUE_H

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <unordered_map>

using namespace std;

template <class T>
class MinQueue 
{
    private:
    vector<T> heap;             // Heap implementation using vectors
    int heap_capacity;          // Heap capacity (Manually checking because vector doubles its size if more elements are added)

    public:
        MinQueue();                                 // Default Constructor
        MinQueue(T* A, int n);                      // Array Constructor
        ~MinQueue(void);                            // Default Destructor
        void insert(const T &item);                 //Insert Method
        T min() const;                              // Min Method
        T extract_min();                            // Extract-Min Method
        void decrease_key(int i, const T &item);    // Decrease-Key Method
        void min_heapify(int i);                    // Min-Heapify Method
        void build_heap();                          // Build Min-Heap Method
        void sort(T* A);                            // HeapSort Method
        string to_string() const;                   // To_string Method
        void set(int i, const T &val);              // Set Method
        void allocate(int n);                       // Allocate Method
};

#endif
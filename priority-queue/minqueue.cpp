//=================================
// Andrew Angulo, Ethan Tecson and Aryah Rao
// minqueue.cpp
// Feb 2024
// This file contains the class template implementation for min-priority queue.
//=================================

#include "minqueue.h"

/**
 * @brief Constructor Class
 *
 * creates a heap
 *
 * @note Pre-Condition: None
 * @note Post-Condition: Creates an MinQueue Object
 *
 * @returns none
 */
template <class T>
MinQueue<T>::MinQueue() {
    // The constructor doesn't need to perform initialization for the heap vector
}

/**
 * @brief Constructor Class
 *
 * Establishes and builds a min-heap using array
 *
 * @param A pointer to an array
 *
 * @param n length based on the array
 *
 * @note Pre-Condition: Array A is a pointer & n >= 0
 * @note Post-Condition: Creates an MinQueue object from elements within A and creates a min-heap
 *
 * @returns none
 */
template <class T>
MinQueue<T>::MinQueue(T* A, int n) {

    // Initialize the heap vector with the elements from array 'A'
    heap.assign(A, A + n);
    heap_capacity = n;
    
    // Build a min-heap from the elements
    build_heap();
}

/**
 * @brief Destructor Class
 *
 * Cleans up resources associated with the MinQueue object
 *
 * @note Pre-Condition: None
 * @note Post-Condition: Cleans up resources that are based on the MinQueue Object
 *
 * @returns none
 */
template <class T>
MinQueue<T>::~MinQueue() {
    // The destructor doesn't need to perform cleanup for the heap vector
}

/**
 * @brief Insert class
 *
 * Inserts an element into the min-heap
 *
 * @param item is the element to be inserted
 *
 * @note Pre-Condition: None
 * @note Post-Condition: The element is added to the heap while still maintaining the min-heap properpty
 * 
 * @returns none
 */
template <class T> 
void MinQueue<T>::insert(const T &item) { // add test case to see if you can insert itemif array is full.

    // Check for heap overflow
    /*                                                        // Dr. Truex's test file fails if this code is not commented 
    if (heap.size() == heap_capacity) {                       // because it tries to add elements beyond the capacity and 
        return;                                               // expects the queue to have the elements.
    }
    */

    // Insert the new element to the end of the heap vector
    heap.push_back(item);
    heap_capacity++;

    // Get the index of the newly added element
    int i = heap.size() - 1;

    // While the parent of the current element is greater than the current element,
    while (i > 0 && heap[(i - 1) / 2] > heap[i]) {

        // Swap the current element with its parent
        swap(heap[i], heap[(i - 1) / 2]);

        // Move up to the parent's position
        i = (i - 1) / 2;
    }
}



/**
 * @brief Min Class
 *
 * Returns the minimum element in the min-heap
 *
 * @note Pre-Condition: None
 * @note Post-Conditon: Returns the minimum element within the min-heap
 *
 * @returns the minimum element in the min-heao
 */
template <class T>
T MinQueue<T>::min() const{
    if(heap.size() == 0){
        return T();
    }
    // Returns the root which in a min heap will always be the first element
    return heap[0];
}

/**
 * @brief Extract-Min Class
 *
 * Extracts the minimum value and rebuils the min-heap
 *
 * @note Pre-Condition: None
 * @note Post-Condition: The minimum element is removed from min-heap while the min-heap property is maintained
 *
 * @returns the minimum value
 */
template <class T>
T MinQueue<T>::extract_min() { 
    if(heap.size() == 0){
        return T();
    }

    // Grab the min value
    T min_val = min();

    // Replace the root with the last element in the heap
    heap[0] = heap[heap.size()-1];

    // Remove the last element from the heap
    heap.pop_back();
    heap_capacity--;

    // Restore the min-heap property starting from the root
    min_heapify(0);

    // Return min value
    return min_val;
}

/**
 * @brief Decrease Key Class
 *
 * This function decreases the value of a key at a given index 'i' in a min heap.
 *
 * @param i The index of the element in the heap to be decreased
 *
 * @param item he new value to replace the current value at index i
 *
 * @note Pre-Conditon: index i must be within the bounds of the heap size and the new item must be less than or equal to the current value at index i
 * @note Post-Conditon: The value at index i in the heap is decreased to item and the min-heap property is maintained
 *
 * @returns none
 */
template <class T>
void MinQueue<T>::decrease_key(int i, const T &item) {

    // Check if the index is out of bounds
    if (i < 0 || i >= heap.size() || heap.size() == 0) {
        return;
    }
    // Check if the new item is greater than the current value
    if (item > heap[i]) {
        return;
    }
    // Update the value at index 'i'
    heap[i] = item;

    // Heapify up to maintain the min-heap property
    while (i > 0 && heap[(i - 1)/2] > heap[i]) {
        swap(heap[i], heap[(i - 1)/2]);
        i = (i - 1)/2;
    }
}

/**
 * @brief Min Heapify Class
 *
 * This function ensures the min-heap property is maintained at a given index i
 *
 * @param i The index of the node in the heap that needs to be heapified.'
 *
 * @note Pre-Condition: index i must be within the bounds of the heap size
 * @note Post-Condition: The value at index i in the heap is heapified such that min-heapify property is maintained . If i isn't the samllest element then it's swapped with the smallest child and the subtree is recursively heapified
 *
 * @returns none
 */
template <class T>
void MinQueue<T>::min_heapify(int i) {
    
    // Calculate indices of left and right children in the binary heap
    int left = 2*i+1;
    int right = 2*i+2;

    // Assume the current node is the smallest (Problem parent)
    int smallest = i;

    // Check if the left child is smaller than the current smallest
    if (left < heap.size() && heap[left] < heap[smallest]) {
        smallest = left;
    }

    // Check if the right child is smaller than the current smallest
    if (right < heap.size() && heap[right] < heap[smallest]) {
        smallest = right;
    }

    // If the smallest element is not the current node, swap them and continue heapifying
    if (smallest != i) {
        swap(heap[i], heap[smallest]);
        min_heapify(smallest); // Recursively min_heapify the child subtree
    }
}

/**
 * @brief Build Heap Class
 *
 * This function creates a min heap from an unordered array. It starts from the last non-leaf node and 
 * performs min_heapify on each node, moving upwards in the binary heap. After this function is called, 
 * the binary heap property is established.
 *
 * @note Pre-Condition: The heap must be non-empty
 * @note Post-Condition: The heap property is established which creates a min heap from an unsorted array
 *
 * @returns none
 */
template <class T>
void MinQueue<T>::build_heap() {

    // Perform min-heapify on each node starting from the last non-leaf node and move upwards in the binary heap.
    for (int i = (heap.size()/2)-1; i >= 0; --i) {
        min_heapify(i);
    }
}

/**
 * @brief Sort Class
 *
 * This function sorts an array A using a min heap. It iterates through the heap, 
 * replacing the root of the heap with the last element, then restoring the min-heap 
 * property. The sorted elements are stored in the array A.
 *
 * @param A The array to be sorted.
 *
 * @note: Pre-Conditon:The heap must be non-empty and the array A must have enough space to hold the sorted elements
 * @note: Post-Condition: Array A contains the elements of the heap in sorted order and the heap is empty
 *
 * @returns none
 */
template <class T>
void MinQueue<T>::sort(T* A) {
    int n = heap.size();

    // Iterate through the heap
    for (int i = 0; i < n; ++i) {
        A[i] = heap[0];
        heap[0] = heap.back();

        // Removes the last element in the heap
        heap.pop_back();

        // Restore the min-heap property after the swap
        min_heapify(0);              
    }
}

/**
 * @brief To String Class
 *
 * This function converts the heap into a string representation. It iterates through the heap, 
 * appending each element to a string, separated by spaces. If the heap is empty, it returns an empty string.
 *
 * @note Pre-Conditon: None
 * @note Post-Condition: A string of the heap is returned. If the heap is empty then an empty string is returned
 *
 * @returns A string representation of the heap.
 */
template <class T>
string MinQueue<T>::to_string() const {
    stringstream ss;

    // Check if the heap is empty
    if (!heap.empty()) {

        // Iterate and append the elements followed by a space
        for (size_t i = 0; i < heap.size() - 1; ++i) {
            ss << heap[i] << " ";
        }

        // Append the last element without a trailing space
        ss << heap.back(); 
    }
    // Return string representation of the priority queue
    return ss.str();
}

/**
 * @brief Set Class
 *
 * This function sets the value at a given index 'i' in the heap to a new value 'val'. 
 * If the index 'i' is within the bounds of the heap and the space is reserved in the heap vector, 
 * the function resizes the vector if needed and sets the value at index 'i' to 'val'.
 *
 * @param i The index in the heap where the new value will be set.
 * @param val The new value to be set at index 'i'.
 *
 * @note Pre-Condition: index i must be within the bounds of the heap capacity 
 * @note: Post-Condition: If i is within the bounds of the heap size, the value of index i in the heap becomes val. If i is outside the heap size but within the heap capacity, the heap is resized and the value at index i is set to val
 *
 * @returns none
 */
template <class T>
void MinQueue<T>::set(int i, const T &val) {

    // Check if the index is within valid bounds of the heap vector
    if (i >= 0 && i < heap_capacity) {

        // Check if the space is reserved in the heap vector
        if (i >= heap.size()) {

            // Resize the vector if needed
            heap.resize(i + 1);
        }

        // Set the value at index i to val
        heap[i] = val; 
    }
    return;
}


/**
 * @brief Allocate Class
 *
 * This function reserves space for 'n' elements in the heap vector. It defines the capacity of the heap to 'n'.
 *
 * @param n The number of elements for which space should be reserved in the heap.
 *
 * @note Pre-Condition: n >= 0
 * @note Post-COnditon: Theap has reserved space for n elements and the capacity of the heap is set to n
 *
 * @returns none
 */
template <class T>
void MinQueue<T>::allocate(int n) {

    // Defining space for 'n' elements in the heap vector
    heap.reserve(n);
    heap_capacity = n;
}
//=================================
// Andrew Angulo, Ethan Tecson and Aryah Rao
// usecase.cpp
// Feb 2024
// This file contains the solution for the sliding window problem.
//=================================

#include "minqueue.cpp"
using namespace std;

/**
 * @brief Sliding Window Class
 *
 * Goes through an array of type T where the length and window are Natural Numbers
 * and window <= len.
 *
 * @param arr array on which the sliding window has to be performed
 *
 * @param len length of the array
 *
 * @param window length of the window
 *
 * @note Pre-Condition: arr must not be empty, len must be a non-negative integer representing the length of arr, and window must be a positive integer <= len.
 * @note Post-Condition: Returns a string of all of the minimum elements within each window cycle separated by spaces. If len or window is less than or equal to 0, or window is greater than len, an empty string is returned.
 *
 * @returns A string of all of the minimum elements within each window cycle seperated by spaces
 */
template <class T>
string sliding_window(T arr[], int len, int window) {
    
    // Return an empty string for invalid inputs
    if (len <= 0 || window <= 0 || window > len) {

        // Invalid input
        return ""; 
    }
    
    stringstream result;
    MinQueue<T> minQueue;

    // Map to store indexes of elements in the current window
    unordered_map<int, int> indexMap; 

    // Process the first window
    for (int i = 0; i < window; ++i) {
        minQueue.insert(arr[i]);
        indexMap[arr[i]] = i;
    }
    result << minQueue.min();

    // Process the remaining windows
    for (int i = window; i < len; ++i) {

        // Check if the index of the minimum element is out of the window
        while (i - window >= indexMap[minQueue.min()]) {

            // Remove the minimum element if its index is out of the window
            minQueue.extract_min(); 
        }

        // Add the new element to the window
        minQueue.insert(arr[i]);            // We can't just insert elements that are smaller than the current minimum as they might become the new minimum when the window moves
        indexMap[arr[i]] = i;               // Make a test case for it

        // Append the minimum element to the result
        result << " " << minQueue.min();
    }

    // Return result string
    return result.str(); 
}

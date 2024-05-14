//=================================
// Andrew Angulo, Ethan Tecson and Aryah Rao
// main.cpp
// Feb 2024
// This file contains the main file for the sliding window problem.
//=================================

#include "usecase.cpp"

using namespace std;

int main() {
    // Example usage
    int nums[] = {16, 4, 8, 2, 10, 7, 1, 9, 3, 6, 5, 11, 15, 13, 12, 14};
    int len = sizeof(nums)/4;
    int window = 4;

    // Call the sliding_window function
    string result = sliding_window(nums, len, window);

    // Display the result
    cout << "Sliding window result for (16, 4, 8, 2, 10, 7, 1, 9, 3, 6, 5, 11, 15, 13, 12, 14) is : " << result << endl;

    return 0;
}
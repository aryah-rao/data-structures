//=================================
// Khoa Ho, Phan Anh Le and Aryah Rao
// main.cpp
// March 2024
// This file contains the example for the hexidecimal problem.
//=================================

#include "usecase.cpp"

//========================================================
// Main
// Asks the user for a binary representation as input and outputs the hexadecimal representation as output
// Parameters: None
// Pre-condition: None
// Post-condition: None
// Return: None
//========================================================
int         main        ()
{
    string bin;
    BST<string, string>* bst = create_bst<string, string>("binhex.txt");
    cout << "Enter binary number: ";
    cin >> bin;
    string result = convert<string, string>(bst, bin);
    if (result == "Error in binary string.") {
        cout << result << endl;
    } else {
       cout << "Hexadecimal representation is " << result << endl;
    }
    
    return 0;
}
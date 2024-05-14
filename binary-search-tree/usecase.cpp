//=================================
// Aryah Rao
// usecase.cpp
// March 2024
// This file contains the solution for the hexidecimal problem.
//=================================

#include "bst.h"

//========================================================
// Create_BST
// Creates a BST from a csv file with the first column as data and second column as keys
// Parameters: None
// Pre-condition: None
// Post-condition: None
// Return: None
//========================================================
template <typename D, typename K>
BST<D, K>*          create_bst          (string fname)
{
    // Open the CSV file
    ifstream file(fname);

    // Create a new BST
    BST<D, K>* bst = new BST<D, K>();

    // Read the file line by line
    string line;
    while (getline(file, line)) {
        // Split the line into binary and hex values
        stringstream ss(line);
        string binary, hex;
        getline(ss, hex, ',');
        getline(ss, binary, ',');

        // Insert the binary and hex values into the BST
        bst->insert(hex, binary);
    }

    // Close the file
    file.close();

    return bst;
}

//========================================================
// Convert
// Converts a binary string to a hexadecimal string
// Parameters: None
// Pre-condition: None
// Post-condition: None
// Return: None
//========================================================
template <typename D, typename K>
string              convert             (BST<D,K>* bst, string bin)
{
    // Check if string is empty
    if (bin.length() < 1) {
        return string();
    }

    // Make bin a multiple of 4
    while (bin.length() % 4 != 0) {
        bin = "0" + bin;
    }

    // Search for the binary value in the BST
    string hex = "";
    for (int i = 0; i < bin.size(); i += 4) {
    string result = bst->get(bin.substr(i, 4));
        if (result == "") {
            hex = "Error in binary string.";
            break;
        } else {
            hex += result; // Append hex value for every 4-bit substring
        }
    }

    return hex;
}
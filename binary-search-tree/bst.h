//=================================
// Aryah Rao
// bst.h
// March 2024
// This file contains the class header for the templated Binary Search Tree Class.
//=================================

#ifndef BST_H
#define BST_H

#include <iostream>
#include <sstream>
#include <string>
#include <queue>
#include <fstream>

using namespace std; 

template <typename Data, typename Key>
class BST {
private:
    struct Node {
        Data        data;       // Data associated with node
        Key         key;        // Key associated with node
        Node*       left;       // Left child of the node
        Node*       right;      // Right child of the node
        Node*       p;          // Parent of the node
        Node(const Data& d, const Key& k) : data(d), key(k), left(nullptr), right(nullptr), p(nullptr) {} // Custom Constructor
    };
    Node        *root;          // Root of the BST

public:
            BST             (void);                     // Constructor
            ~BST            (void);                     // Destructor
bool        empty           (void) const;               // Check if BST is empty
void        insert          (Data data, Key key);       // Insert a node into the BST
Data        get             (Key key) const;            // Return data associated with given key
void        remove          (Key key);                  // Remove a node from the BST with given key
Data        max_data        (void) const;               // Return data associated with max key
Key         max_key         (void) const;               // Return max key
Data        min_data        (void) const;               // Return data associated with min key
Key         min_key         (void) const;               // Return min key
Key         successor       (Key key) const;            // Return successor of given key
string      in_order        (void) const;               // Return a string of keys in non-descending order
void        trim            (Key low, Key high);        // Trim the BST within low and high interval
string      to_string       (void) const;               // Get a string representation of the BST
Node*       removeHelper    (Node* node, Key key);      // Helper function to recursively remove a node from the BST
Node*       min_helper      (Node* node) const;         // Return node associated with min key
Node*       max_helper      (Node* node) const;         // Return node associated with max key
void        in_order_helper (Node* root, stringstream& result) const;   // Append a string of keys in non-descending order to a stringstream object
Node*       trimHelper      (Node* node, Key low, Key high);    // Helper function to recursively trim the BST within the specified interval
void        clear           (Node* node);                // Deletes all the nodes in the subtree rooted at node.
};

#include "bst.cpp"

#endif

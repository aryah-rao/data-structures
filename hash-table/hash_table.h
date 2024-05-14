//=================================
// Lam Do and Aryah Rao
// hash_table.h
// Feb 2024
// This file contains the class header for the templated Element and HashTable Class.
//=================================

#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <iostream>
#include <sstream>
#include <string>
#include <list>
#include <vector>
#include <unordered_set>
#include <cmath>
#include <climits>
#include <fstream>

using namespace std; 

// Template for Element class
template <typename T>
class Element {
private:
    T data;
    long int key; // Large integers

public:
    // Default constructor
    Element() {
        key = -1;
        data = T();
    };

    // Custom Constructor
    Element(T data, long int key) {
        this->key = key;
        this->data = data;
    }

    // Getter for key
    long int get_key() const {
        return key;
    }

    // Getter for data
    T get_data() const {
        return data;
    }
};

template <typename T>
class HashTable {
private:
    int size;                                               // Size of hashtable
    vector< list < Element<T> > > table;                    // Vector of doubly linked lists

public:
            HashTable       (int size);                     // Constructor
            ~HashTable      (void);                         // Destructor
long int    hash_function   (long int key) const;           // Hash function
void        insert          (T data, long int key);         // Insert an element into the hash table
void        remove          (long int key);                 // Remove an element from the hash table by key
bool        member          (T data, long int key) const;   // Check if an element with given data and key is a member of the hash table  
string      to_string       (void) const;                   // Get a string representation of the hash table
int         get_slot_count  (long int slot);                // Return number of items in a particular slot
void        analyze         (void);                         // Compute metrics for analyzing hash function
};

#include "hash_table.cpp"

#endif

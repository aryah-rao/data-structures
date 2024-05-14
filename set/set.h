//=================================
// Aryah Rao and John Yoon
// set.h
// Jan 2024
// This file contains the class header for the templated Set class
//=================================

#ifndef SET_H
#define SET_H

#include <iostream>
#include <string>
using namespace std;

// Template for Set class
template <class T>
class Set
{
private:
    // struct for Node for set
    struct Node
    {
        T           item; // Data of the node
        Node        *next; // Pointer to the next node
    };
    Node            *head; // Pointer to the head of the linked list
	int 			size; // Size of the set
    
public:
        Set         (void); // Default constructor
        Set         (const Set<T> &otherSet); // Copy constructor
        ~Set        (void); // Destructor 
Set<T>  operator=   (const Set<T> &otherSet); // Assignment operator
void    insert      (const T &item); // Insert Method
void    remove      (const T &item); // Remove Method
int     cardinality (void) const; // Cardinality Method
bool    empty       (void) const;  // Empty Method
bool    contains    (const T &item) const; // Contains Method
bool    operator==  (const Set<T> &otherSet) const; // == Operator (Equality)
bool    operator<=  (const Set<T> &otherSet) const;  // <= Operator (Subset)
Set<T>  operator+   (const Set<T> &otherSet) const; // + Operator (Union)
Set<T>  operator&   (const Set<T> &otherSet) const;  // & Operator (Intersection)
Set<T>  operator-   (const Set<T> &otherSet) const;  // - Operator (Difference)
string  to_string   (void) const; // To_string Method

};

#endif
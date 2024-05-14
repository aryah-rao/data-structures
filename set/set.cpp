//=================================
// Aryah Rao
// set.cpp
// Jan 2024
// This file contains the class methods for the templated Set class
//=================================

#include <iostream>
#include <string>
#include <sstream>
#include "set.h"

using namespace std;

//=================================
// Default Constructor
// Parameters: None
// Pre-Condition: None
// Post Condition: Creates an empty set with no elements.
//=================================
template <typename T>
        Set<T>::Set         (void)
{
    // Initialize head and size
    head = NULL;
    size = 0;
}

//=================================
// Copy Constructor
// Parameters: otherSet - The set to be copied.
// Pre-Condition: None
// Post Condition: Creates a new set that is a copy of the provided set.
//=================================
template <typename T>
        Set<T>::Set         (const Set<T> &otherSet)
{
    // Initialize nodes
    Node *ptr;
    Node *qtr;

    // If other set is empty
    if(otherSet.head == NULL)
    {
        head = NULL;
    }
    else
    {
        // Copying first node
        ptr = otherSet.head;
        head = new Node;
        head->item = ptr->item;

        // Copying remaining nodes
        qtr = head;
        ptr = ptr->next;
        while(ptr != NULL)
        // Copying nodes from original to duplicate
        {
            qtr->next = new Node;
            qtr = qtr->next;
            qtr->item = ptr->item;
            ptr = ptr->next;
        }
        qtr->next = NULL;
    }
    size = otherSet.size;
}

//=================================
// Destructor
// Parameters: None
// Pre-Condition: None
// Post Condition: Deletes the set and frees the memory occupied by its nodes.
//=================================
template <typename T>
        Set<T>::~Set        (void)
{
    Node *ptr = head;
    while(ptr != NULL)
    {
        // Step 1: move ptr ahead of head
        ptr = ptr->next;
        // Step 2: delete head
        delete head;
        // Step 3: head catch up to ptr
        head = ptr;
    }
    head = NULL;
    size = 0;
}

//=================================
// Assignment Operator
// Parameters: otherSet - The set to be assigned.
// Pre-Condition: None
// Post Condition: Assigns the content of the provided set to this set.
// Return: A reference to the new set.
//=================================
template <typename T>
Set<T>  Set<T>::operator=   (const Set<T> &otherSet)
{
    Node *ptr = head;
    while(ptr != NULL)
    {
        // Step 1: move ptr ahead of head
        ptr = ptr->next;
        // Step 2: delete head
        delete head;
        // Step 3: head catch up to ptr
        head = ptr;
    }
    size = 0;

    Node *qtr;

    if(otherSet.head == NULL)
    {
        head = NULL;
    }
    else
    {
        // Copying first node
        ptr = otherSet.head;
        head = new Node;
        head->item = ptr->item;

        // Copying remaining nodes
        qtr = head;
        ptr = ptr->next;
        while(ptr != NULL)
        // Copying nodes from original to duplicate
        {
            qtr->next = new Node;
            qtr = qtr->next;
            qtr->item = ptr->item;
            ptr = ptr->next;
        }
        qtr->next = NULL;
    }
    size = otherSet.size;

    return *this;   
}

//=================================
// Insert Method: Insert a new element into the set.
// Parameters: item - The element to be inserted.
// Pre-Condition: The set must exist, and an element 'item' must be provided.
// Post Condition: If the element is not already present in the set, inserts it at the beginning.
//=================================
template <typename T>
void    Set<T>::insert      (const T &item)
{
    // Add only if element is not in the set
    if (!contains(item)) {
        // Create new head and point to previous head
        Node* newHead = new Node;
        newHead->item = item;
        newHead->next = head;
        head = newHead;
        ++size;  // Increment the size
    }
}

//=================================
// Remove Method: Remove an element from the set.
// Parameters: item - The element to be removed.
// Pre-Condition: The set must exist, and an element 'item' must be provided.
// Post Condition: If the element is present in the set, removes it.
//=================================
template <typename T>
void    Set<T>::remove    (const T &item)
{
    // Create two nodes
    Node* current = head;
    Node* prev = NULL;

    // Traverse the set until you reach the target or the end
    while (current != NULL && current->item != item) {
        prev = current;
        current = current->next; // Go to next node
    }

    // If target is found
    if (current != NULL) {
        // If target is the only element in the set, make head null
        if (prev == NULL) {
            head = current->next;
        } 
        // Else, attach prev and next nodes
        else {
            prev->next = current->next; // Go to next node
        }
        
        delete current; // Delete target node
        --size; // Decrement the size
    }
}

//=================================
// Cardinality Method: Get the number of elements in the set.
// Parameters: None
// Pre-Condition: The set must exist.
// Post Condition: Returns - The number of elements in the set.
//=================================
template <typename T>
int     Set<T>::cardinality (void) const
{
    return size; // Return size
}

//=================================
// Empty Method: Check if the set is empty.
// Parameters: None
// Pre-Condition: The set must exist.
// Post Condition: Returns - True if the set is empty, else false.
//=================================
template <typename T>
bool    Set<T>::empty       (void) const
{
    return(head == NULL); // Return if head is null
}

//=================================
// Contains Method: Check if the set contains a specific element.
// Parameters: item - The element to be checked for existence.
// Pre-Condition: The set must exist, and an element 'item' must be provided.
// Post Condition: Returns - True if the element is present, else false.
//=================================
template <typename T>
bool    Set<T>::contains     (const T &item) const
{
    // Traverse the linked list
    Node* current = head;
    while (current != NULL) {
        // If element is found, return true
        if (current->item == item) {
            return true;
        }
        current = current->next; // Go to next node
    }
    // Else element is not found, return false
    return false;
}

//=================================
// == Operator: Equality operator for sets.
// Parameters: otherSet - The set to be compared.
// Pre-Condition: Both sets must exist.
// Post Condition: Returns - True if the sets are equal, else false.
//=================================
template <typename T>
bool    Set<T>::operator==  (const Set<T> &otherSet) const
{
    Node *ptr = head;
    // If size is different, return false because sets are not equal
    if(size != otherSet.cardinality())
    {
        return false;
    }
    // Else, traverse set and check if all elements are in the other set
    while(ptr != NULL)
    {
        // If any element is not present in the other set, return false because sets are not equal
        if(!otherSet.contains(ptr->item))
        {
            return false;
        }
        ptr = ptr->next; // Go to next node
    }
    return true; // All elements are present, sets are equal
}

//=================================
// <= Operator: Subset operator for sets.
// Parameters:otherSet - The set to be checked for being a subset.
// Pre-Condition: Both sets must exist.
// Post Condition: Returns - True if this set is a subset of the provided set, else false.
//=================================
template <typename T>
bool    Set<T>::operator<=  (const Set<T> &otherSet) const
{
    if(head == NULL) // An empty set would be a subset
    {
        return true;
    }
    Node *current = head;
    // Traverse each element in the current set
    while (current != NULL) {
        // Check if the current element is present in the other set
        if (!otherSet.contains(current->item)) {
            return false; // If element is not present, it's not a subset
        }
        current = current->next; // Go to next node
    }

    return true; // All elements are present, it's a subset
}

//=================================
// + Operator: Union operator for sets.
// Parameters: otherSet - The set to be unioned with this set.
// Pre-Condition: Both sets must exist.
// Post Condition: Returns - A new set representing the union of this set and the provided set.
//=================================
template <typename T>
Set<T>  Set<T>::operator+   (const Set<T> &otherSet) const
{
    Set<T> unionSet;
    Node *ptr = otherSet.head;
    // Traverse the other set and insert elements to new set
    while (ptr != NULL) {
        unionSet.insert(ptr->item); // Insert element
        ptr = ptr->next; // Go to next node
    }

    // Traverse the other set and insert elements to new set
    Node *qtr = head;
    while (qtr != NULL) 
    {
        if(!otherSet.contains(qtr->item))
        {
            unionSet.insert(qtr->item); // Insert element
        }
        qtr = qtr->next; // Go to next node
    }

    return unionSet; // Return union set

}

//=================================
// & Operator: Intersection operator for sets.
// Parameters: otherSet - The set to be intersected with this set.
// Pre-Condition: Both sets must exist.
// Post Condition: Returns - A new set representing the intersection of this set and the provided set.
//=================================
template <typename T>
Set<T>  Set<T>::operator&  (const Set<T> &otherSet) const
{
    // Create new set
    Set<T> intersectionSet;
    // Traverse each element in the current set
    Node *current = head;
    // Traverse the set
    while (current != NULL) {
        // Check if the current element is present in the other set
        if (otherSet.contains(current->item)) {
            // If present, insert into the intersection set
            intersectionSet.insert(current->item);
        }
        current = current->next; // Go to next node
    }

    return intersectionSet; // Return intersection set
}

//=================================
// - Operator: Difference operator for sets.
// Parameters: otherSet - The set to be subtracted from this set.
// Pre-Condition: Both sets must exist.
// Post Condition: Returns - A new set representing the difference of this set and the provided set.
//=================================
template <typename T>
Set<T>  Set<T>::operator- (const Set<T> &otherSet) const
{
    Set<T> differenceSet;
    Node *ptr = head;
    // Traverse the set
    while (ptr != NULL) {
        // Check if the current element is present in the other set
        if (!otherSet.contains(ptr->item)) {
            // If not present, insert into the difference set
            differenceSet.insert(ptr->item);
        }
        ptr = ptr->next; // Go to next node
    }
    return differenceSet; // Return difference set
}

//=================================
// To_string Method: Convert the set to a string representation.
// Parameters: None
// Pre-Condition: The set must exist.
// Post Condition: Returns - Return: A string representation of the set.
//================================
template <typename T>
string  Set<T>::to_string   (void) const
{
    // DR TRUEX HINT: stringstream
    stringstream ss;
    // Check if set is empty
    if(head != NULL)
    {
        Node *ptr = head;
        // Traverse set
        while(ptr != NULL)
        {
            ss << ptr->item; // Concatenate item to string s
            if(ptr->next != NULL)
            {
                ss << " "; // Add whitespace if there is another element in the set
            }
            ptr = ptr->next; // Go to next node
        }
    }
    string s = ss.str();
    return s; // Return string 
}
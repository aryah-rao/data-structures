//=================================
// Lam Do and Aryah Rao
// hash_table.cpp
// Feb 2024
// This file implements the templated Element and HashTable Class.
//=================================

#include "hash_table.h"

//========================================================
// Constructor
// Initialize a hash table
// Parameters: 
//          size - Number of slots in the hash table
// Pre-condition: None
// Post-condition: Hash table is created
// Return: None
//========================================================
template <typename T>
            HashTable<T>::HashTable         (int size)
{
    this->size = size;
    table.resize(size);
}

//========================================================
// Destructor
// Clean up the memory of the hash table
// Parameters: None
// Pre-condition: None
// Post-condition: Memory allocated for hash table is cleand up
// Return: None
//========================================================
template <typename T>
            HashTable<T>::~HashTable        (void)
{
    // Doing nothing because no dynamic memory allocation
}

//========================================================
// Hash_function
// Take input key and return the hashed value with formula h(key) = key % size
// Parameters: 
//          key - Key of element
// Pre-condition: None
// Post-condition: We get the hashed version of the key
// Return: None
//========================================================
template <typename T>
long int    HashTable<T>::hash_function        (long int key) const
{
    // Change key to its absolute value if it is negative
    key = (key < 0) ? -key : key;
    // Handle the case where size is zero or negative
    if (size <= 0) {
        return key; // RETURN SOMETHING ELSE
    }
    return (key % size);    // MOD size
}

//========================================================
// Insert
// Insert an element with data and key into the hash table 
// Parameters: 
//      data - Value of element
//      key - Key of element
// Pre-condition: None
// Post-condition: Element with data and key is in hash table
// Return: None
//========================================================
template <typename T>
void        HashTable<T>::insert                (T data, long int key)
{
    // If key already exists, do nothing
    if (member(data, key)) {
        return;
    }

    // Create hash
    long int hashedKey = hash_function(key);

    if (hashedKey < 0 || hashedKey >= size) {
        // If hashed key is out of range, do nothing (case for 0 or negative size)
        return;
    }

    // Create new element
    Element<T> newElement(data, key);

    // Push the new element to the front of the DLL in our vector at index hashedKey
    table[hashedKey].push_front(newElement);
}

//========================================================
// Remove
// Remove an element from the hash table by key
// Parameters: 
//      key - Key of element
// Pre-condition: Keys of elements in the hash table are distinct
// Post-condition: Element with given key is removed from hash table
// Return: None
//========================================================
template <typename T>
void        HashTable<T>::remove                   (long int key)

{
    // Create hash
    long int hashedKey = hash_function(key);

    if (hashedKey < 0 || hashedKey >= size) {
        // If hashed key is out of range, do nothing (case for 0 or negative size)
        return;
    }

    // Access the slot at hashed key        
    list<Element<T>> & slot = table[hashedKey];

    // Search linearly in the list
    for (auto itr = slot.begin(); itr != slot.end(); itr++)
    {
        if (itr->get_key() == key) {
            // Remove key and exit
            slot.erase(itr);
            return;
        }
    }
}

//========================================================
// Member
// Check if an element with given data and key is a member of the hash table  
// Parameters: 
//      data - Value of element
//      key - Key of element
// Pre-condition: None
// Post-condition: None
// Return: Boolean value indicating if the element is in the hash table
//========================================================
template <typename T>
bool        HashTable<T>::member                    (T data, long int key) const
{
    // Create hash
    long int hashedKey = hash_function(key);

    if (hashedKey < 0 || hashedKey >= size) {
        // If hashed key is out of range, do nothing (case for 0 or negative size)
        return false;
    }

    // Access the slot at hashed key        
    list<Element<T>> slot = table[hashedKey];

    // Search linearly in the slot for item with given key and data
    for (auto itr = slot.begin(); itr != slot.end(); itr++)
    {
        // Found: data and key are both duplicate
        if (itr->get_data() == data && itr->get_key() == key) {
            return true;
        }
    }
    // Not Found
    return false;
}

//========================================================
// To_string
// Return a string representation of the hash table
// Parameters: None
// Pre-condition: None
// Post-condition: None
// Return: String representation of the hash table
//========================================================

template <typename T>
string      HashTable<T>::to_string                 (void) const
{
    // Initialize stringstream
    stringstream ss;

    // Iterate through each slot in the hash table
    for (int i = 0; i < size; ++i) {
        // Append slot index
        ss << i << ": ";
        // Iterate through each element in the current slot
        for (const Element<T>& ele : table[i]) {
            // Append data and key of the element
            ss << "(" << ele.get_data() << "," << ele.get_key() << ") ";
        }
        // Next line for new slot
        ss << endl;
    }
    // Return string representation
    return ss.str();
}

//========================================================
// Get_slot_count
// Return the number of items in a particular slot
// Parameters: 
//      slot - Hashed key or index in the hash table
// Pre-condition: None
// Post-condition: None
// Return: The number of items in a particular slot
//========================================================
template <typename T>
int         HashTable<T>::get_slot_count  (long int slot)  
{
    return table[slot].size(); // Return size of DLL (slot size)
}            

//========================================================
// Analyze
// Compute the following metrics: 
//      1. total number of unique items stored in the table
//      2. the average number of items in each slot in the table
//      3. the standard deviation of the number of items in each slot
//      4. the slot count for the minimum numer of items in a slot
//      5. the slot count for the maximum number of items in a slot
// Parameters: 
//      slot - Hashed key or index in the hash table
// Pre-condition: None
// Post-condition: None
// Return: The number of items in a particular slot
//========================================================
template <typename T>
void        HashTable<T>::analyze           (void)
{
    // Initialize metrics
    int num_unique = 0; 
    int num_non_empty_slots = 0;
    float avg = 0;
    float sum_sd = 0;
    float sd = 0;
    int min = INT_MAX;
    int max = 0;

    // Open CSV
    ofstream outputFile("hash_table_slots.csv");
    outputFile << "x" << "," << "y" << endl;

    // Iterate through each slot
    for (int i = 0; i < size; i++)
    {
        int num_slots = get_slot_count(i); // Get slot count

        // Check if the slot is non-empty
        if (num_slots > 0)
        {
            // Increment total number of non-empty slots
            num_non_empty_slots++;

            // 1. Total number of unique items stored in the table
            num_unique += num_slots;

            // 4. The slot count for the minimum number of items in a slot
            if (num_slots < min)
            {
                min = num_slots;
            }

            // 5. The slot count for the maximum number of items in a slot
            if (num_slots > max)
            {
                max = num_slots;
            }
        }
        // Write to CSV file
        outputFile << i << "," << num_slots << endl;
    }


    // 2. the average number of items in each slot in the table
    if (num_non_empty_slots > 0) {
        avg = float(num_unique) / num_non_empty_slots;
    } else {
        avg = -1.0;
    }

    // 3. The standard deviation of the number of items in each slot (ONLY NON-EMPTY SLOTS)
    for (int i = 0; i < size; i++)
    {
        int num_slots = get_slot_count(i);

        // Check if the slot is non-empty
        if (num_slots > 0)
        {
            sum_sd += pow((num_slots - avg), 2); // Summation
        }
    }
    // Calculate standard deviation
    if (num_non_empty_slots > 0) {
        sd = sqrt(sum_sd / num_non_empty_slots);
    } else {
        sd = -1.0;
    }

    outputFile.close(); // Close CSV
    
    // Print metrics
    cout << "Total number of unique elements: " << num_unique << endl;
    cout << "Average: " << avg << endl;
    cout << "Min: " << min << endl;
    cout << "Max: " << max << endl;
    cout << "Standard Deviation: " << sd << endl;
    // cout << "Number of non-empty slots: " << num_non_empty_slots << endl; //COMMENT THIS OUT
}

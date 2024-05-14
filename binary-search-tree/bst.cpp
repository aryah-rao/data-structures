//=================================
// Khoa Ho, Phan Anh Le and Aryah Rao
// bst.cpp
// March 2024
// This file implements the templated Binary Search Tree Class.
//=================================

#include <iostream>
#include <sstream>
#include <string>
#include <queue>
#include <fstream>
using namespace std; 


//========================================================
// Constructor
// Initializes an instance of a binary search tree
// Parameters: None
// Pre-condition: None
// Post-condition: An instance of a binary search tree is initialized.
// Return: None
//========================================================
template<typename Data, typename Key>
            BST<Data, Key>::BST         ()
{
    root = nullptr;
}

//========================================================
// Destructor
// Deletes the instance of a binary search tree
// Parameters: None
// Pre-condition: The binary tree must be initialized.
// Post-condition: The instance of the binary search tree is deleted.
// Return: None
//========================================================
template<typename Data, typename Key>
            BST<Data, Key>::~BST        () 
{
    clear(root); 
}

//========================================================
// Empty Method
// Check if BST is empty
// Parameters: None
// Pre-condition: The binary tree must be initialized.
// Post-condition: None
// Return: Returns a boolean value indicating whether the binary search tree is empty 
//========================================================
template<typename Data, typename Key>
bool        BST<Data, Key>::empty       () const 
{
    return root == nullptr;
}

//========================================================
// Insert Method
// Insert a node into the BST
// Parameters: Data - Data to be inserted as a node.
//             Key - Key to be inserted as a node.
// Pre-condition: The binary tree must be initialized.
// Post-condition: A new node with the provided data and key is inserted into the binary search tree.
// Return: None
//========================================================

template<typename Data, typename Key>
void        BST<Data, Key>::insert      (Data data, Key key) 
{
    // If the tree is empty, create a new node and make it the root
    if (root == nullptr) {
        root = new Node(data, key);
        return;
    }

    // Traverse the tree to find the appropriate position for insertion
    Node* current = root;
    Node* parent = nullptr;
    while (current != nullptr) {
        parent = current;
        if (key < current->key)
            current = current->left; // Move to the left subtree
        else
            current = current->right; // Move to the right subtree
    }

    // Create a new node with the given data and key
    Node* newNode = new Node(data, key);
    newNode->p = parent; // Set the parent of the new node

    // Insert the new node as a child of the appropriate parent node
    if (key < parent->key)
        parent->left = newNode; // Insert to the left subtree
    else
        parent->right = newNode; // Insert to the right subtree
}

//========================================================
// Get Method
// Return data associated with given key
// Parameters: Key - The key for which the data associated with is to be returned.
// Pre-condition: The binary tree must be initialized.
// Post-condition: If a node with the given key is found, returns the data associated with that key, else returns default value of the type.
// Return: The data associated with the given key
//========================================================
template<typename Data, typename Key>
Data            BST<Data, Key>::get             (Key key) const 
{
    Node* current = root; // Start from the root node

    // Traverse the BST until current is not null or current's key matches the given key
    while (current != nullptr && current->key != key) {
        if (key < current->key)
            current = current->left; // Move to the left subtree
        else
            current = current->right; // Move to the right subtree
    }

    // If current is null
    if (current == nullptr)
        return Data(); // Return the default value of Data

    // Else, return the data associated with the found key
    return current->data;
}

//========================================================
// Remove Method
// Remove a node from the BST with given key
// Parameters: Key - the key of the node to be removed from the binary search tree.
// Pre-condition: The binary tree must be initialized.
// Post-condition: The node with the given key is removed from the binary search tree.
// Return: None
//========================================================
template<typename Data, typename Key>
void BST<Data, Key>::remove(Key key) {
    root = removeHelper(root, key);
}

//========================================================
// Remove Helper
// Helper function to recursively remove a node from the BST
// Parameters: Node - A pointer to the root of the binary search tree
//             Key - the key of the node to be removed from the binary search tree.
// Pre-condition: The binary tree must be initialized.
// Post-condition: The node with the given key is recursively removed from the binary search tree.
// Return:  A pointer to the root of the updated subtree after removal.
//========================================================
template<typename Data, typename Key>
typename BST<Data, Key>::Node* BST<Data, Key>::removeHelper(Node* node, Key key) {
    if (node == nullptr) {
        return nullptr; // Base case: return nullptr
    }

    // Search for the node to remove
    if (key < node->key) {
        // If key is smaller, search in the left subtree
        node->left = removeHelper(node->left, key);
    } else if (key > node->key) {
        // If key is greater, search in the right subtree
        node->right = removeHelper(node->right, key);
    } else {
        // Node with the key found, perform removal
        if (node->left == nullptr && node->right == nullptr) {
            // Case 1: Node to be removed is a leaf node
            delete node;
            node = nullptr;
        } else if (node->left == nullptr) {
            // Case 2: Node to be removed has only a right child
            Node* temp = node;
            node = node->right;
            delete temp;
        } else if (node->right == nullptr) {
            // Case 3: Node to be removed has only a left child
            Node* temp = node;
            node = node->left;
            delete temp;
        } else {
            // Case 4: Node to be removed has both left and right children
            // Find the successor node (minimum node in the right subtree)
            Node* successor = min_helper(node->right);
            // Copy the successor's key and data to the current node
            node->key = successor->key;
            node->data = successor->data;
            // Recursively remove the successor node
            node->right = removeHelper(node->right, successor->key);
        }
    }

    return node;
}

//========================================================
// Max Helper
// Return node associated with max key
// Parameters: Node - Pointer to the root of the current subtree.
// Pre-condition: The binary tree must be initialized.
// Post-condition: None
// Return: Pointer to the node with the maximum key.
//========================================================
template<typename Data, typename Key>
typename BST<Data, Key>::Node* BST<Data, Key>::max_helper(typename BST<Data, Key>::Node* node) const 
{
    if (node == nullptr)
        return nullptr; // Return nullptr if the tree is empty
    if (node->right == nullptr)
        return node; // Return the current node if it doesn't have a right child
    return max_helper(node->right); // Recursively find the rightmost node
}

//========================================================
// Max_data Method
// Return data associated with max key
// Parameters: None
// Pre-condition: The binary tree must be initialized.
// Post-condition: None
// Return: Data associated with the maximum key.
//========================================================
template<typename Data, typename Key>
Data            BST<Data, Key>::max_data            () const 
{
    if (root == nullptr)
        return Data(); // Return default value if BST is empty
    return max_helper(root)->data; // Return data associated with the rightmost node (max key)
}

//========================================================
// Max_key Method
// Return max key
// Parameters: None
// Pre-condition: The binary tree must be initialized.
// Post-condition: None
// Return: Maximum key in the binary search tree.
//========================================================
template<typename Data, typename Key>
Key             BST<Data, Key>::max_key         () const 
{
    if (root == nullptr)
        return Key(); // Return default value if BST is empty
    return max_helper(root)->key; // Return key associated with the rightmost node (max key)
}

//========================================================
// Min Helper
// Return node associated with min key
// Parameters: Node - Pointer to the root of the current subtree.
// Pre-condition: The binary tree must be initialized.
// Post-condition: None
// Return: Pointer to the node with the minimum key.
//========================================================
template<typename Data, typename Key>
typename BST<Data, Key>::Node* BST<Data, Key>::min_helper(typename BST<Data, Key>::Node* node) const
{
    if (node == nullptr)
        return nullptr; // Return nullptr if the tree is empty
    if (node->left == nullptr)
        return node; // Return the current node if it doesn't have a left child
    return min_helper(node->left); // Recursively find the leftmost node
}


//========================================================
// Min_data Method
// Return data associated with min key
// Parameters: None
// Pre-condition: The binary tree must be initialized.
// Post-condition: None
// Return: Data associated with the minimum key.
//========================================================
template<typename Data, typename Key>
Data            BST<Data, Key>::min_data            () const 
{
    if (root == nullptr)
        return Data(); // Return default value if BST is empty

    return min_helper(root)->data; // Return data associated with the leftmost node (min key)
}

//========================================================
// Min_key Method
// Return min key
// Parameters: None
// Pre-condition: The binary tree must be initialized.
// Post-condition: None
// Return: Minimum key in the binary search tree.
//========================================================
template<typename Data, typename Key>
Key             BST<Data, Key>::min_key         () const 
{
    if (root == nullptr)
        return Key(); // Return default value if BST is empty

    return min_helper(root)->key; // Return key associated with the leftmost node (min key)
}

//========================================================
// Successor Method
// Return successor of given key
// Parameters: Key - The key for which the successor needs to be found.
// Pre-condition: The binary tree must be initialized.
// Post-condition: None
// Return: Successor key of the given key if it exists, else default value of key. 
//========================================================
template<typename Data, typename Key>
Key             BST<Data, Key>::successor       (Key key) const  // Successor of maximum value??
{
    if (root == nullptr)
        return Key(); // Return default value if BST is empty

    Node* current = root;
    Key successorKey = Key(); // Initialize the successor key to default value

    // Traverse the tree to find the node with the given key
    while (current != nullptr && current->key != key) {
        if (key < current->key)
            current = current->left;
        else
            current = current->right;
    }

    // If the key is not found, return default value
    if (current == nullptr)
        return Key();

    // If the node has a right subtree, find the minimum key in that subtree
    if (current->right != nullptr) {
        return min_helper(current->right)->key; // Use min_helper method
    } else {
        // If the node doesn't have a right subtree, find the first ancestor which is greater than the key
        Node* ancestor = current->p;
        // Traverse up the tree until you find an ancestor with a greater key
        while (ancestor != nullptr) {
            if (current->key < ancestor->key) {
                successorKey = ancestor->key;
                break; // Exit the loop
            }
            ancestor = ancestor->p; // Move to next ancestor
        }
    }
    return successorKey;
}

//========================================================
// Inorder Helper
// Append a string of keys in non-descending order to a stringstream object
// Parameters: Root - Pointer to the root node of the subtree.
//             Result - A reference to a stringstream object where the keys in non-descending order will be appended.
// Pre-condition: The binary tree must be initialized.
// Post-condition: None
// Return: None
//========================================================
template<typename Data, typename Key>
void BST<Data, Key>::in_order_helper(Node* root, stringstream& result) const 
{
    if (root != nullptr) {
        // Recursively traverse the left subtree
        in_order_helper(root->left, result);
        
        // Append the key of the current node to the result string
        result << root->key << " ";
        
        // Recursively traverse the right subtree
        in_order_helper(root->right, result);
    }
}

//========================================================
// Inorder Method
// Return a string of keys in non-descending order
// Parameters: None
// Pre-condition: The binary tree must be initialized.
// Post-condition: None
// Return: A string representing the keys of the binary search tree in non-descending order.
//========================================================
template<typename Data, typename Key>
string          BST<Data, Key>::in_order        () const 
{
    stringstream result; 
    in_order_helper(root, result); // Call the helper function

    // Get the string representation
    string str = result.str();

    // Remove the last character if the string is not empty
    if (!str.empty()) {
        str.pop_back();
    }

    // Return the modified string representation
    return str;
}

//========================================================
// Trim Method
// Trim the BST within low and high interval
// Parameters: Low - The lower bound of the interval for trimming.
//             High - The upper bound of the interval for trimming.
// Pre-condition: The binary tree must be initialized.
// Post-condition: The binary search tree only contains the nodes within the specified interval [low, high].
// Return: None
//========================================================
template<typename Data, typename Key>
void BST<Data, Key>::trim(Key low, Key high) {
    root = trimHelper(root, low, high);
}

//========================================================
// Trim Helper
// Helper function to recursively trim the BST within the specified interval
// Parameters: Node - Pointer to the current node.
//             Low - The lower bound of the interval for trimming.
//             High - The upper bound of the interval for trimming.
// Pre-condition: The binary tree must be initialized.
// Post-condition: The binary search tree only contains the nodes within the specified interval [low, high].
// Return: Pointer to the root of the trimmed binary search tree.
//========================================================
template<typename Data, typename Key>
typename BST<Data, Key>::Node* BST<Data, Key>::trimHelper(Node* node, Key low, Key high) {
    // Base case: If the current node is null, return null
    if (node == nullptr) {
        return nullptr;
    }

    // Recursively trim left and right subtrees
    node->left = trimHelper(node->left, low, high);
    node->right = trimHelper(node->right, low, high);

    // If the current node's key is lower than low, remove node and connect subtree at right child
    if (node->key < low) {
        Node* rightChild = node->right;
        delete node;
        return rightChild;
    }
    // If the current node's key is higher than high, remove node and connect subtree at left child
    if (node->key > high) {
        Node* leftChild = node->left;
        delete node;
        return leftChild;
    }

    // Else, return node
    return node;
}

//========================================================
// To_string Method
// Get a string representation of the BST
// Parameters: None
// Pre-condition: The binary tree must be initialized.
// Post-condition: None
// Return: Returns a string representation of the binary search tree.
//========================================================
template<typename Data, typename Key>
string          BST<Data, Key>::to_string       (void) const
{
    if (root == nullptr)
        return ""; // Return empty string if BST is empty

    stringstream result; // Stream to build the string representation
    queue<Node*> nodeQueue; // Queue to perform level-order traversal

    // Enqueue the root node
    nodeQueue.push(root);

    // Perform level-order traversal
    while (!nodeQueue.empty()) {
        Node* current = nodeQueue.front(); // Get the front node in the queue
        nodeQueue.pop(); // Dequeue the front node

        // Enqueue the left child if it exists
        if (current->left != nullptr)
            nodeQueue.push(current->left);

        // Enqueue the right child if it exists
        if (current->right != nullptr)
            nodeQueue.push(current->right);

        // Append the key of the current node to the result string
        result << current->key;

        // Append a space if there are more nodes in the queue
        if (!nodeQueue.empty())
            result << " ";
    }
    return result.str(); // Return the string representation
}

//========================================================
// Clear Method
// Deletes all the nodes in the subtree rooted at node.
// Parameters: None
// Pre-condition: The binary tree must be initialized.
// Post-condition: The instance of the binary search tree is deleted.
// Return: None
//========================================================
template<typename Data, typename Key>
void            BST<Data, Key>::clear           (Node* node)
{
    // Recursively traverse all nodes
    if (node != nullptr)
    {
        clear(node->left);
        clear(node->right);
        delete node; // Delete current node
    }
}

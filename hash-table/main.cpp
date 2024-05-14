//=================================
// Lam Do and Aryah Rao
// main.cpp
// Feb 2024
// This file read Rush Hour board configurations and store them in a hash table
//=================================

#include "Board.h"
#include "hash_table.h"

int	main( int argc, char *argv[])
{
    // notice the hash table size is a command-line parameter
    if ( argc != 2 )
    {
        printf("Error: you must include the hash table size as a");
        printf(" command-line parameter.\n");
        exit(0);
    }
    int size = atoi(argv[1]);

    // Declare HashTable
    HashTable<Board>  table(size);

    // Now we attempt to read in boards until "EOF" is detected
    Board b; // used to store the boards being read
    cin >> b;
    while ( !cin.eof() )
    {
        // Insert board and its key
        int hashValue = b.getHashValue(size);
        table.insert(b, hashValue);

        // cout << "Read in board: \n"; // COMMENT OUT BEFORE SUBMITTING
        // cout << b;

        // cout << "Board's hashvalue: \n"; // COMMENT OUT BEFORE SUBMITTING
        // cout << hashValue << endl;

        // cout << endl << endl;
        cin >> b;
    };
    // hashing performance
    table.analyze();
    return 0;
}

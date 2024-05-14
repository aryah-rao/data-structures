//========================================================
// Aryah Rao
// Based on test_hashtable_example.cpp written by Dr. Stacey Truex
// test_hash_table.cpp
// Feb 2024
// This file tests methods from the Element and HashTable class
//========================================================

#include <iostream>
#include <chrono>
#include "hash_table.h"

using namespace std;

void test_get_key()
{
    try
    {
        // empty
        Element<int> empty_elem;
        if (empty_elem.get_key() != -1)
        {
            cout << "Incorrect result from get key. Expected -1 for an empty element but got : " << empty_elem.get_key() << endl;
        }

        // regular int
        Element<int> e(10, 6);
        if (e.get_key() != 6)
        {
            cout << "Incorrect result from get key. Expected 6 but got : " << e.get_key() << endl;
        }

        Element<int> e1(20, 20);
        if (e1.get_key() != 20)
        {
            cout << "Incorrect result from get key. Expected 7.5 but got : " << e1.get_key() << endl;
        }

        // negative int
        Element<int> e2(-5, -10);
        if (e2.get_key() != -10)
        {
            cout << "Incorrect result from get key. Expected -10 but got : " << e2.get_key() << endl;
        }

        // empty string
        Element<string> empty_elem_str;
        if (empty_elem_str.get_key() != -1)
        {
            cout << "Incorrect result from get data. Expected empty string for an empty element but got : " << empty_elem_str.get_data() << endl;
        }

        // regular string
        Element<string> e3("aryah", 4);
        if (e3.get_key() != 4)
        {
            cout << "Incorrect result from get key. Expected 4 but got : " << e3.get_key() << endl;
        }

        Element<string> e4("lam", 5);
        if (e4.get_key() != 5)
        {
            cout << "Incorrect result from get key. Expected 5 but got : " << e4.get_key() << endl;
        }

        // regular float
        Element<float> e5(7.5, 2);
        if (e5.get_key() != 2)
        {
            cout << "Incorrect result from get key. Expected 2 but got : " << e5.get_key() << endl;
        }

        Element<float> e6(-4.2, 13);
        if (e6.get_key() != 13)
        {
            cout << "Incorrect result from get key. Expected 13 but got : " << e6.get_key() << endl;
        }

    }
    catch (exception &e)
    {
        cerr << "Error getting key from element : " << e.what() << endl;
    }
}

void test_get_data()
{
    try
    {
        Element<int> empty_elem;
        if (empty_elem.get_data() != 0)
        {
            cout << "Incorrect result from get data. Expected 0 for an empty element but got : " << empty_elem.get_data() << endl;
        }

        // regular int
        Element<int> e(10, 6);
        if (e.get_data() != 10)
        {
            cout << "Incorrect result from get data. Expected 10 but got : " << e.get_data() << endl;
        }

        Element<int> e1(20, 20);
        if (e1.get_data() != 20)
        {
            cout << "Incorrect result from get data. Expected 7.5 but got : " << e1.get_data() << endl;
        }

        //negative int
        Element<int> e2(-5, -10);
        if (e2.get_data() != -5)
        {
            cout << "Incorrect result from get data. Expected -10 but got : " << e2.get_data() << endl;
        }

        // empty string
        Element<string> empty_elem_str;
        if (empty_elem_str.get_data() != "")
        {
            cout << "Incorrect result from get data. Expected empty string for an empty element but got : " << empty_elem_str.get_data() << endl;
        }

        // regular string
        Element<string> e3("aryah", 4);
        if (e3.get_data() != "aryah")
        {
            cout << "Incorrect result from get data. Expected aryah but got : " << e3.get_data() << endl;
        }

        Element<string> e4("lam", 5);
        if (e4.get_data() != "lam")
        {
            cout << "Incorrect result from get data. Expected lam but got : " << e4.get_data() << endl;
        }

        // regular float
        Element<float> e5(7.5, 2);
        if (e5.get_data() != 7.5)
        {
            cout << "Incorrect result from get data. Expected 2 but got : " << e5.get_data() << endl;
        }

        // imprecise negative float
        Element<float> e6(-4.2, 13);
        if (e6.get_data() == -4.2)
        {
            cout << "Incorrect result from get data. Expected -4.2 but got : " << e6.get_data() << endl;
        }
    }
    catch (exception &e)
    {
        cerr << "Error getting data from element : " << e.what() << endl;
    }
}

void test_insert()
{
    try
    {
        // empty hash table
        HashTable<int> empty_ht(0);
        empty_ht.insert(10, 6);
        if (empty_ht.to_string() != "")
        {
            cout << "Incorrect result of inserting into table. Expected and empty string But got\n\n"
                 << empty_ht.to_string() << endl;
        }
    }
    catch (exception &e)
    {
        cout << "Error caused by trying to insert into empty table : " << e.what() << endl;
    }
    try
    {
        // INTEGERS
        HashTable<int> ht2(10); 
        // Regular
        ht2.insert(50, 5);
        if (ht2.to_string() != "0: \n1: \n2: \n3: \n4: \n5: (50,5) \n6: \n7: \n8: \n9: \n")
        {
            cout << "Incorrect result of inserting into table. Expected\n\n0: \n1: \n2: \n3: \n4: \n5: (50,5) \n6: \n7: \n8: \n9: \n but got\n\n"
                 << ht2.to_string() << endl;
        }
        // Duplicates
        ht2.insert(32, 7);
        if (ht2.to_string() != "0: \n1: \n2: \n3: \n4: \n5: (50,5) \n6: \n7: (32,7) \n8: \n9: \n")
        {
            cout << "Incorrect result of inserting into table. Expected\n\n0: \n1: \n2: \n3: \n4: \n5: (50,15) \n6: \n7: (32,7) \n8: \n9: \n but got\n\n"
                 << ht2.to_string() << endl;
        }
        ht2.insert(32, 7);
        if (ht2.to_string() != "0: \n1: \n2: \n3: \n4: \n5: (50,5) \n6: \n7: (32,7) \n8: \n9: \n")
        {
            cout << "Incorrect result of inserting into table. Expected\n\n0: \n1: \n2: \n3: \n4: \n5: (50,15) \n6: \n7: (32,7) \n8: \n9: \n but got\n\n"
                 << ht2.to_string() << endl;
        }
        // Collision
        ht2.insert(60, 15); 
        if (ht2.to_string() != "0: \n1: \n2: \n3: \n4: \n5: (60,15) (50,5) \n6: \n7: (32,7) \n8: \n9: \n")
        {
            cout << "Incorrect result of inserting into table. Expected\n\n0: \n1: \n2: \n3: \n4: \n5: (60,15) (50,5) \n6: \n7: (32,7) \n8: \n9: \n but got\n\n"
                 << ht2.to_string() << endl;
        }
        // Negative Integer
        ht2.insert(14, -4); 
        if (ht2.to_string() != "0: \n1: \n2: \n3: \n4: (14,-4) \n5: (60,15) (50,5) \n6: \n7: (32,7) \n8: \n9: \n")
        {
            cout << "Incorrect result of inserting into table. Expected\n\n0: \n1: \n2: \n3: \n4: (14,-4) \n5: (60,15) (50,5) \n6: \n7: (32,7) \n8: \n9: \n but got\n\n"
                 << ht2.to_string() << endl;
        }

        // CHARS
        HashTable<char> ht3(10); 
        // Regular
        ht3.insert('a', 5);
        if (ht3.to_string() != "0: \n1: \n2: \n3: \n4: \n5: (a,5) \n6: \n7: \n8: \n9: \n")
        {
            cout << "Incorrect result of inserting into table. Expected\n\n0: \n1: \n2: \n3: \n4: \n5: (a,5) \n6: \n7: \n8: \n9: \n but got\n\n"
                 << ht3.to_string() << endl;
        }
        // Duplicates
        ht3.insert('b', 7);
        if (ht3.to_string() != "0: \n1: \n2: \n3: \n4: \n5: (a,5) \n6: \n7: (b,7) \n8: \n9: \n")
        {
            cout << "Incorrect result of inserting into table. Expected\n\n0: \n1: \n2: \n3: \n4: \n5: (a,15) \n6: \n7: (b,7) \n8: \n9: \n but got\n\n"
                 << ht3.to_string() << endl;
        }
        ht3.insert('b', 7);
        if (ht3.to_string() != "0: \n1: \n2: \n3: \n4: \n5: (a,5) \n6: \n7: (b,7) \n8: \n9: \n")
        {
            cout << "Incorrect result of inserting into table. Expected\n\n0: \n1: \n2: \n3: \n4: \n5: (a,15) \n6: \n7: (b,7) \n8: \n9: \n but got\n\n"
                 << ht3.to_string() << endl;
        }
        // Collision
        ht3.insert('c', 15); 
        if (ht3.to_string() != "0: \n1: \n2: \n3: \n4: \n5: (c,15) (a,5) \n6: \n7: (b,7) \n8: \n9: \n")
        {
            cout << "Incorrect result of inserting into table. Expected\n\n0: \n1: \n2: \n3: \n4: \n5: (c,15) (a,5) \n6: \n7: (b,7) \n8: \n9: \n but got\n\n"
                 << ht3.to_string() << endl;
        }

        // STRINGS
        HashTable<string> ht4(10); 
        // Regular
        ht4.insert("aryah", 5);
        if (ht4.to_string() != "0: \n1: \n2: \n3: \n4: \n5: (aryah,5) \n6: \n7: \n8: \n9: \n")
        {
            cout << "Incorrect result of inserting into table. Expected\n\n0: \n1: \n2: \n3: \n4: \n5: (aryah,5) \n6: \n7: \n8: \n9: \n but got\n\n"
                 << ht4.to_string() << endl;
        }
        // Duplicates
        ht4.insert("lam", 7);
        if (ht4.to_string() != "0: \n1: \n2: \n3: \n4: \n5: (aryah,5) \n6: \n7: (lam,7) \n8: \n9: \n")
        {
            cout << "Incorrect result of inserting into table. Expected\n\n0: \n1: \n2: \n3: \n4: \n5: (aryah,15) \n6: \n7: (lam,7) \n8: \n9: \n but got\n\n"
                 << ht4.to_string() << endl;
        }
        ht4.insert("lam", 7);
        if (ht4.to_string() != "0: \n1: \n2: \n3: \n4: \n5: (aryah,5) \n6: \n7: (lam,7) \n8: \n9: \n")
        {
            cout << "Incorrect result of inserting into table. Expected\n\n0: \n1: \n2: \n3: \n4: \n5: (aryah,15) \n6: \n7: (lam,7) \n8: \n9: \n but got\n\n"
                 << ht4.to_string() << endl;
        }
        // Collision
        ht4.insert("hash", 15); 
        if (ht4.to_string() != "0: \n1: \n2: \n3: \n4: \n5: (hash,15) (aryah,5) \n6: \n7: (lam,7) \n8: \n9: \n")
        {
            cout << "Incorrect result of inserting into table. Expected\n\n0: \n1: \n2: \n3: \n4: \n5: (hash,15) (aryah,5) \n6: \n7: (lam,7) \n8: \n9: \n but got\n\n"
                 << ht4.to_string() << endl;
        }

        // FLOATS
        HashTable<float> ht5(10); 
        // Regular
        ht5.insert(3.14, 5);
        if (ht5.to_string() != "0: \n1: \n2: \n3: \n4: \n5: (3.14,5) \n6: \n7: \n8: \n9: \n")
        {
            cout << "Incorrect result of inserting into table. Expected\n\n0: \n1: \n2: \n3: \n4: \n5: (3.14,5) \n6: \n7: \n8: \n9: \n but got\n\n"
                 << ht5.to_string() << endl;
        }
        // Duplicates
        ht5.insert(2.71, 7);
        if (ht5.to_string() != "0: \n1: \n2: \n3: \n4: \n5: (3.14,5) \n6: \n7: (2.71,7) \n8: \n9: \n")
        {
            cout << "Incorrect result of inserting into table. Expected\n\n0: \n1: \n2: \n3: \n4: \n5: (3.14,15) \n6: \n7: (2.71,7) \n8: \n9: \n but got\n\n"
                 << ht5.to_string() << endl;
        }
        ht5.insert(2.71, 7);
        if (ht5.to_string() != "0: \n1: \n2: \n3: \n4: \n5: (3.14,5) \n6: \n7: (2.71,7) \n8: \n9: \n")
        {
            cout << "Incorrect result of inserting into table. Expected\n\n0: \n1: \n2: \n3: \n4: \n5: (3.14,15) \n6: \n7: (2.71,7) \n8: \n9: \n but got\n\n"
                 << ht5.to_string() << endl;
        }
        // Collision
        ht5.insert(1.23, 15); 
        if (ht5.to_string() != "0: \n1: \n2: \n3: \n4: \n5: (1.23,15) (3.14,5) \n6: \n7: (2.71,7) \n8: \n9: \n")
        {
            cout << "Incorrect result of inserting into table. Expected\n\n0: \n1: \n2: \n3: \n4: \n5: (1.23,15) (3.14,5) \n6: \n7: (2.71,7) \n8: \n9: \n but got\n\n"
                 << ht5.to_string() << endl;
        }
    }
    catch (exception &e)
    {
        cerr << "Error inserting into non-empty table : " << e.what() << endl;
    }
}

void test_remove()
{
    try
    {
        // remove from empty table
        HashTable<int> empty_ht(0);
        empty_ht.remove(6);
        if (empty_ht.to_string() != "")
        {
            cout << "Incorrect result of removing from empty table. Expected and empty string But got\n\n"
                 << empty_ht.to_string() << endl;
        }
    }
    catch (exception &e)
    {
        cout << "Error caused by trying to remove from empty table : " << e.what() << endl;
    }
    try
    {
        // INTEGERS
        // Regular
        HashTable<int> ht1(5);
        ht1.insert(10, 6);
        ht1.remove(6);
        if (ht1.to_string() != "0: \n1: \n2: \n3: \n4: \n")
        {
            cout << "Incorrect result of removing member from table. Expected\n\n0: \n1: \n2: \n3: \n4: \n\nBut got\n\n"
                 << ht1.to_string() << endl;
        }
        // Non-member
        ht1.insert(10, 6);
        ht1.remove(5);
        if (ht1.to_string() != "0: \n1: (10,6) \n2: \n3: \n4: \n")
        {
            cout << "Incorrect result of removing non-member from table. Expected\n\n0: \n1: (10,6) \n2: \n3: \n4: \n\nBut got\n\n"
                 << ht1.to_string() << endl;
        }

        // STRINGS
        // Regular
        HashTable<string> ht2(5);
        ht2.insert("hash", 6);
        ht2.remove(6);
        if (ht2.to_string() != "0: \n1: \n2: \n3: \n4: \n")
        {
            cout << "Incorrect result of removing member from table. Expected\n\n0: \n1: \n2: \n3: \n4: \n\nBut got\n\n"
                 << ht2.to_string() << endl;
        }
        // Non-member
        ht2.insert("hash", 6);
        ht2.remove(5);
        if (ht2.to_string() != "0: \n1: (hash,6) \n2: \n3: \n4: \n")
        {
            cout << "Incorrect result of removing non-member from table. Expected\n\n0: \n1: (hash,6) \n2: \n3: \n4: \n\nBut got\n\n"
                 << ht2.to_string() << endl;
        }

        // CHARS
        // Regular
        HashTable<char> ht3(5);
        ht3.insert('a', 6);
        ht3.remove(6);
        if (ht3.to_string() != "0: \n1: \n2: \n3: \n4: \n")
        {
            cout << "Incorrect result of removing member from table. Expected\n\n0: \n1: \n2: \n3: \n4: \n\nBut got\n\n"
                 << ht3.to_string() << endl;
        }
        // Non-member
        ht3.insert('a', 6);
        ht3.remove(5);
        if (ht3.to_string() != "0: \n1: (a,6) \n2: \n3: \n4: \n")
        {
            cout << "Incorrect result of removing non-member from table. Expected\n\n0: \n1: (a,6) \n2: \n3: \n4: \n\nBut got\n\n"
                 << ht3.to_string() << endl;
        }

        // FLOATS
        // Regular
        HashTable<float> ht4(5);
        ht4.insert(3.14, 6);
        ht4.remove(6);
        if (ht4.to_string() != "0: \n1: \n2: \n3: \n4: \n")
        {
            cout << "Incorrect result of removing member from table. Expected\n\n0: \n1: \n2: \n3: \n4: \n\nBut got\n\n"
                 << ht4.to_string() << endl;
        }
        // Non-member
        ht4.insert(3.14, 6);
        ht4.remove(5);
        if (ht4.to_string() != "0: \n1: (3.14,6) \n2: \n3: \n4: \n")
        {
            cout << "Incorrect result of removing non-member from table. Expected\n\n0: \n1: (3.14,6) \n2: \n3: \n4: \n\nBut got\n\n"
                 << ht4.to_string() << endl;
        }
    }
    catch (exception &e)
    {
        cerr << "Error removing non-member from table : " << e.what() << endl;
    }
    try
    {
        HashTable<int> ht5(5);
        ht5.insert(10, 6);
        ht5.remove(6);
        if (ht5.to_string() != "0: \n1: \n2: \n3: \n4: \n")
        {
            cout << "Incorrect result removing member from table. Expected\n\n0: \n1: \n2: \n3: \n4: \n\nBut got\n\n"
                 << ht5.to_string() << endl;
        }
    }
    catch (exception &e)
    {
        cerr << "Error removing member from table : " << e.what() << endl;
    }
}

void test_member()
{
    try
    {
        //empty
        HashTable<int> empty_ht(0);
        if (empty_ht.member(10, 6))
        {
            cout << "Incorrect membership in empty table" << endl;
        }
    }
    catch (exception &e)
    {
        cout << "Error caused by trying to determine membership in empty table : " << e.what() << endl;
    }
    try
    {   
        // INTEGERS
        HashTable<int> ht1(5);
        ht1.insert(10, 6);
        if (!ht1.member(10, 6))  // Data and Key are same
        {
            cout << "Incorrect membership in table" << endl;
        }
        if (ht1.member(11, 6)) // Data is different, Key is same
        {
            cout << "Incorrect non-membership in table" << endl;
        }
        if (ht1.member(10, 7)) // Data is same, Key is different
        {
            cout << "Incorrect non-membership in table" << endl;
        }
        if (ht1.member(11, 7)) // Data and Key are different
        {
            cout << "Incorrect non-membership in table" << endl;
        }

        // CHARS
        HashTable<char> ht2(5);
        ht2.insert('a', 6);
        if (!ht2.member('a', 6))  // Data and Key are same
        {
            cout << "Incorrect membership in table" << endl;
        }
        if (ht2.member('b', 6)) // Data is different, Key is same
        {
            cout << "Incorrect non-membership in table" << endl;
        }
        if (ht2.member('a', 7)) // Data is same, Key is different
        {
            cout << "Incorrect non-membership in table" << endl;
        }
        if (ht2.member('b', 7)) // Data and Key are different
        {
            cout << "Incorrect non-membership in table" << endl;
        }

        // STRINGS
        HashTable<string> ht3(5);
        ht3.insert("aryah", 6);
        if (!ht3.member("aryah", 6))  // Data and Key are same
        {
            cout << "Incorrect membership in table" << endl;
        }
        if (ht3.member("lam", 6)) // Data is different, Key is same
        {
            cout << "Incorrect non-membership in table" << endl;
        }
        if (ht3.member("aryah", 7)) // Data is same, Key is different
        {
            cout << "Incorrect non-membership in table" << endl;
        }
        if (ht3.member("lam", 7)) // Data and Key are different
        {
            cout << "Incorrect non-membership in table" << endl;
        }

        // FLOATS
        HashTable<float> ht4(5);
        ht4.insert(3.14, 6);
        if (!ht4.member(3.14, 6))  // Data and Key are same
        {
            cout << "Incorrect membership in table" << endl;
        }
        if (ht4.member(2.71, 6)) // Data is different, Key is same
        {
            cout << "Incorrect non-membership in table" << endl;
        }
        if (ht4.member(3.14, 7)) // Data is same, Key is different
        {
            cout << "Incorrect non-membership in table" << endl;
        }
        if (ht4.member(2.71, 7)) // Data and Key are different
        {
            cout << "Incorrect non-membership in table" << endl;
        }
    }
    catch (exception &e)
    {
        cerr << "Error determining membership from table : " << e.what() << endl;
    }
}    
int main()
{
    test_get_key();
    test_get_data();
    test_insert();
    test_remove();
    test_member();

    cout << "Testing completed" << endl;

    return 0;
}

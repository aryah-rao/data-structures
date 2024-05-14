//========================================================
// Aryah Rao
// Based on test_bst_example.cpp written by Dr. Stacey Truex
// test_bst.cpp
// March 2024
// This file tests methods from the Binary Search Tree class
//========================================================

#include <stdlib.h>
#include <iostream>
#include <math.h>
#include "usecase.cpp"

using namespace std;

void test_empty() {
    try
    {
        // int empty bst for  
        BST<string, int> bst;
        if(!bst.empty()) {
            cout << "Incorrect empty result." << endl;
        }
        // int max_data on empty
        string empty_str = bst.max_data();
        if(empty_str != "") {
            cout << "Incorrect empty result. Got : " << empty_str << endl;
        }
        // int max_key on empty
        int empty_int = bst.max_key();
        if(empty_int != 0) {
            cout << "Incorrect empty result. Got : " << empty_int << endl;
        }
        // int min_data on empty
        empty_str = bst.min_data();
        if(empty_str != "") {
            cout << "Incorrect empty result. Got : " << empty_str << endl;
        }
        // int min_key on empty
        empty_int = bst.min_key();
        if(empty_int != 0) {
            cout << "Incorrect empty result. Got : " << empty_int << endl;
        }
        // int successor on empty
        empty_int = bst.successor(1);
        if(empty_int != 0) {
            cout << "Incorrect empty result. Got : " << empty_int << endl;
        }
        // int insert on empty
        bst.insert("one",1);
        if(bst.empty()) {
            cout << "Incorrect empty result." << endl;
        }


        // float empty bst for  
        BST<string, float> float_bst;
        if(!float_bst.empty()) {
            cout << "Incorrect float empty result." << endl;
        }
        // float max_data on empty
        string empty_float_str = float_bst.max_data();
        if(empty_float_str != "") {
            cout << "Incorrect  float empty result. Got : " << empty_float_str << endl;
        }
        // float max_key on empty
        float empty_float = float_bst.max_key();
        if(empty_float != 0) {
            cout << "Incorrect float empty result. Got : " << empty_float << endl;
        }
        // float min_data on empty
        empty_float_str = float_bst.min_data();
        if(empty_float_str != "") {
            cout << "Incorrect float empty result. Got : " << empty_float_str << endl;
        }
        // float min_key on empty
        empty_float = float_bst.min_key();
        if(empty_float != 0) {
            cout << "Incorrect float empty result. Got : " << empty_float << endl;
        }
        // float successor on empty
        empty_float = float_bst.successor(1.1);
        if(empty_float != 0) {
            cout << "Incorrect float empty result. Got : " << empty_float << endl;
        }
        // float insert on empty
        float_bst.insert("one",1.1f);
        if(float_bst.empty()) {
            cout << "Incorrect float empty result." << endl;
        }


        // char empty bst for  
        BST<string, char> char_bst;
        if(!char_bst.empty()) {
            cout << "Incorrect char empty result." << endl;
        }
        // char max_data on empty
        string empty_char_str = char_bst.max_data();
        if(empty_char_str != "") {
            cout << "Incorrect char empty result. Got : " << empty_char_str << endl;
        }
        // char max_key on empty
        char empty_char = char_bst.max_key();
        if(empty_char != 0) {
            cout << "Incorrect char empty result. Got : " << empty_char << endl;
        }
        // char min_data on empty
        empty_char_str = char_bst.min_data();
        if(empty_char_str != "") {
            cout << "Incorrect char empty result. Got : " << empty_char_str << endl;
        }
        // char min_key on empty
        empty_char = char_bst.min_key();
        if(empty_char != 0) {
            cout << "Incorrect char empty result. Got : " << empty_char << endl;
        }
        // char successor on empty
        empty_char = char_bst.successor('A');
        if(empty_char != '\0') {
            cout << "Incorrect char empty result. Got : " << empty_char << endl;
        }
        // char insert on empty
        char_bst.insert("one", 'A');
        if(char_bst.empty()) {
            cout << "Incorrect char empty result." << endl;
        }
    }
    catch(exception& e)
    {
        cerr << "Error in determining if BST is empty : " << e.what() << endl;
    }
}


void test_negative() {
    try {
        // negative int
        BST<string, int> neg_bst;
        int neg_vals[10] = {-5, -2, -7, -1, -3, -4, -6, -9, -8, -10};
        for(int i = 0; i < 10; i++) {
            neg_bst.insert("negative data " + to_string(neg_vals[i]), neg_vals[i]);
        }
        string neg_bst_str = neg_bst.to_string();
        if(neg_bst_str != "-5 -7 -2 -9 -6 -3 -1 -10 -8 -4") {
            cout << "Incorrect result of inserting negative keys {-5 -7 -2 -9 -6 -3 -1 -10 -8 -4}. Expected -5 -7 -2 -9 -6 -3 -1 -10 -8 -4 but got : " << neg_bst_str << endl;
        } 

        // test get
        string data = neg_bst.get(-4);
        if(data != "negative data -4") {
            cout << "Incorrect get result. Expected \"negative data -4\" but got: " << data << endl;
        }

        // test remove
        neg_bst.remove(-7);
        neg_bst_str = neg_bst.to_string();
        if(neg_bst_str != "-5 -6 -2 -9 -3 -1 -10 -8 -4") {
            cout << "Incorrect result of removing -7. Expected -5 -6 -2 -9 -3 -1 -10 -8 -4 but got : " << neg_bst_str << endl;
        }

        // est max_data
        data = neg_bst.max_data();
        if(data != "negative data -1") {
            cout << "Incorrect max_data result. Expected \"negative data -1\" but got: " << data << endl;
        }

        // test max_key
        int maxKey = neg_bst.max_key();
        if(maxKey != -1) {
            cout << "Incorrect max_key result. Expected -1 but got: " << maxKey << endl;
        }

        // test min_data
        data = neg_bst.min_data();
        if(data != "negative data -10") {
            cout << "Incorrect min_data result. Expected \"negative data -10\" but got: " << data << endl;
        }

        // test min_key
        int minKey = neg_bst.min_key();
        if(minKey != -10) {
            cout << "Incorrect min_key result. Expected -10 but got: " << minKey << endl;
        }

        // test successor
        int succ = neg_bst.successor(-6);
        if(succ != -5) {
            cout << "Incorrect successor result. Expected -5 but got: " << succ << endl;
        }

        // Test in_order
        neg_bst_str = neg_bst.in_order();
        if(neg_bst_str != "-10 -9 -8 -6 -5 -4 -3 -2 -1") {
            cout << "Incorrect in_order result. Expected -10 -9 -8 -6 -5 -4 -3 -2 -1 but got: " << neg_bst_str << endl;
        }

        neg_bst.trim(-8, -3);
        neg_bst_str = neg_bst.to_string();
        if(neg_bst_str != "-5 -6 -3 -8 -4") {
            cout << "Incorrect tree after trimming. Expected -5 -6 -3 -8 -4 but got: " << neg_bst_str << endl;
        }

    } catch(exception& e) {
        cerr << "Error testing negative keys in bst : " << e.what() << endl;
    }

}


void test_insert() {
    try {
        // int
        BST<string, int> bst;
        bst.insert("one", 1);
        string bst_str = bst.to_string();
        if(bst_str != "1") {
            cout << "Incorrect result of inserting (\"one\", 1). Expected 1 but got : " << bst_str << endl;
        }
        for(int i = 2; i <= 10; i++) {
            bst.insert("some data", i);
        }
        bst_str = bst.to_string();
        if(bst_str != "1 2 3 4 5 6 7 8 9 10") {
            cout << "Incorrect result of inserting keys 1-10 in order. Expected 1 2 3 4 5 6 7 8 9 10 but got : " << bst_str << endl;
        }
        int vals[10] = {5, 2, 7, 1, 3, 4, 6, 9, 8, 10};
        BST<string, int> balanced_bst;
        for(int i = 0; i < 10; i++) {
            balanced_bst.insert("some data", vals[i]);
        }
        bst_str = balanced_bst.to_string();
        if(bst_str != "5 2 7 1 3 6 9 4 8 10") {
            cout << "Incorrect result of inserting keys {5, 2, 7, 1, 3, 4, 6, 9, 8, 10}. Expected 5 2 7 1 3 6 9 4 8 10 but got : " << bst_str << endl;
        }

        // negative int
        BST<string, int> neg_bst;
        int neg_vals[10] = {-5, -2, -7, -1, -3, -4, -6, -9, -8, -10};
        for(int i = 0; i < 10; i++) {
            neg_bst.insert("negative data " + to_string(neg_vals[i]), neg_vals[i]);
        }
        string neg_bst_str = neg_bst.to_string();
        if(neg_bst_str != "-5 -7 -2 -9 -6 -3 -1 -10 -8 -4") {
            cout << "Incorrect result of inserting negative keys {-5 -7 -2 -9 -6 -3 -1 -10 -8 -4}. Expected -5 -7 -2 -9 -6 -3 -1 -10 -8 -4 but got : " << neg_bst_str << endl;
        } 


        // float 
        BST<string, float> float_bst;
        float_bst.insert("one", 1.1f);
        string float_bst_str = float_bst.to_string();
        if(float_bst_str != "1.1") {
            cout << "Incorrect result of inserting (\"one\", 1.1). Expected 1.1 but got : " << float_bst_str << endl;
        }
        for(float i = 2.1f; i <= 10.1f; i++) {
            float_bst.insert("some data", i);
        }
        float_bst_str = float_bst.to_string();
        if(float_bst_str != "1.1 2.1 3.1 4.1 5.1 6.1 7.1 8.1 9.1 10.1") {
            cout << "Incorrect result of inserting keys 1.1-10.1 in order. Expected 1.1 2.1 3.1 4.1 5.1 6.1 7.1 8.1 9.1 10.1 but got : " << float_bst_str << endl;
        }
        float float_vals[10] = {5.1f, 2.1f, 7.1f, 1.1f, 3.1f, 4.1f, 6.1f, 9.1f, 8.1f, 10.1f};
        BST<string, float> balanced_float_bst;
        for(int i = 0; i < 10; i++) {
            balanced_float_bst.insert("some data", float_vals[i]);
        }
        float_bst_str = balanced_float_bst.to_string();
        if(float_bst_str != "5.1 2.1 7.1 1.1 3.1 6.1 9.1 4.1 8.1 10.1") {
            cout << "Incorrect result of inserting keys {5.1, 2.1, 7.1, 1.1, 3.1, 4.1, 6.1, 9.1, 8.1, 10.1}. Expected 5.1 2.1 7.1 1.1 3.1 6.1 9.1 4.1 8.1 10.1 but got : " << float_bst_str << endl;
        }

        // char 
        BST<string, char> char_bst;
        char_bst.insert("one", 'A');
        string char_bst_str = char_bst.to_string();
        if(char_bst_str != "A") {
            cout << "Incorrect result of inserting (\"one\", 'A'). Expected A but got : " << char_bst_str << endl;
        }
        for(char i = 'B'; i <= 'J'; i++) {
            char_bst.insert("some data", i);
        }
        char_bst_str = char_bst.to_string();
        if(char_bst_str != "A B C D E F G H I J") {
            cout << "Incorrect result of inserting keys A-J in order. Expected A B C D E F G H I J but got : " << char_bst_str << endl;
        }
        char char_vals[10] = {'E', 'B', 'G', 'A', 'C', 'F', 'H', 'D', 'I', 'J'};
        BST<string, char> balanced_char_bst;
        for(int i = 0; i < 10; i++) {
            balanced_char_bst.insert("some data", char_vals[i]);
        }
        char_bst_str = balanced_char_bst.to_string();

        if(char_bst_str != "E B G A C F H D I J") {
            cout << "Incorrect result of inserting keys {E B G A C F H D I J}. Expected E B G A C F H D I J but got : " << char_bst_str << endl;
        }

        // string 
        BST<string, string> string_bst;
        string_bst.insert("A", "apple");
        string string_bst_str = string_bst.to_string();
    
        if(string_bst_str != "apple") {
            cout << "Incorrect result of inserting (\"A\", \"apple\"). Expected apple but got : " << string_bst_str << endl;
        }
        string keys[] = {"banana", "cherry", "date", "fig", "grape", "honeydew", "kiwi", "lemon", "mango"};
        for(int i = 0; i < 9; i++) {
            string_bst.insert("some data", keys[i]);
        }
        string_bst_str = string_bst.to_string();
        if(string_bst_str != "apple banana cherry date fig grape honeydew kiwi lemon mango") {
            cout << "Incorrect result of inserting multiple string keys. Expected ordered list but got : " << string_bst_str << endl;
        }

        BST<string, string> balanced_string_bst;
        string string_vals[10] = {"lemon", "banana", "mango", "apple", "cherry", "fig", "grape", "date", "kiwi", "honeydew"};
        for(int i = 0; i < 10; i++) {
            balanced_string_bst.insert("some data", string_vals[i]); 
        }
        string_bst_str = balanced_string_bst.to_string();
        if(string_bst_str != "lemon banana mango apple cherry fig date grape kiwi honeydew") {
            cout << "Incorrect result of inserting keys {lemon, banana, mango, apple, cherry, fig, grape, date, kiwi, honeydew}. Expected ordered list but got : " << string_bst_str << endl;
        }

    } catch(exception& e) {
        cerr << "Error inserting into bst : " << e.what() << endl;
    }
}

void test_get() {
    try {
        // empty
        BST<string, int> bst;
        string val = bst.get(0);
        if(val!="") {
            cout << "Incorrect get result from empty bst. Expected 0 but got " << val << endl;
        }

        // int
        bst.insert("one",1);
        val = bst.get(1);
        if(val != "one") {
            cout << "Incorrect get result. Expected \"one\" but got : " << val << endl;
        }
        
        // float
        BST<string, float> float_bst;
        float_bst.insert("one", 1.1f); 
        string float_data = float_bst.get(1.1f); 
        if(float_data != "one") { 
            cout << "Incorrect get result. Expected \"one\"but got : " << float_data << endl;
        }

        // char
        BST<string, char> char_bst;
        char_bst.insert("ten", 'X'); 
        string char_data = char_bst.get('X'); 
        if(char_data != "ten") { 
            cout << "Incorrect get result. Expected \"ten\" but got : " << char_data << endl;
        }

        // string
        BST<string, string> string_bst;
        string_bst.insert("one", "ONE"); 
        string string_data = string_bst.get("ONE"); 
        if(string_data != "one") { 
            cout << "Incorrect get result. Expected \"one\" but got : " << string_data << endl;
        }


    } catch(exception& e) {
        cerr << "Error in getting data from bst : " << e.what() << endl;
    }
}

void test_remove() {
    try {

        // remove out of an empty bst
        BST<string, int> empty_bst;
        empty_bst.remove(5); 
        string empty_bst_str = empty_bst.to_string();
        if(empty_bst_str != "") {
            cout << "Incorrect result of removing from an empty BST. Expected an empty string but got: '" << empty_bst_str << "'." << endl;
        } 

        // int
        int vals[10] = {5, 2, 7, 1, 3, 4, 6, 9, 8, 10};
        BST<string, int> balanced_bst;
        for(int i = 0; i < 10; i++) {
            balanced_bst.insert("some data", vals[i]);
        }
        // remove int 2 children
        balanced_bst.remove(7);
        string bst_str = balanced_bst.to_string();
        if(bst_str != "5 2 8 1 3 6 9 4 10") {
            cout << "Incorrect result of removing 7. Expected 5 2 8 1 3 6 9 4 10 but got : " << bst_str << endl;
        }
        // remove int root
        balanced_bst.remove(5);
        bst_str = balanced_bst.to_string();
        if(bst_str != "6 2 8 1 3 9 4 10") {
            cout << "Incorrect result of removing root node 5. Expected 6 2 8 1 3 9 4 10 but got : " << bst_str << endl;
        }
        // remove int 1 child
        balanced_bst.remove(8);
        bst_str = balanced_bst.to_string();
        if(bst_str != "6 2 9 1 3 10 4") {
            cout << "Incorrect result of removing 8. Expected 6 2 9 1 3 10 4 but got : " << bst_str << endl;
        }

    
        // float
        float float_vals[10] = {5.1f, 2.1f, 7.1f, 1.1f, 3.1f, 4.1f, 6.1f, 9.1f, 8.1f, 10.1f};
        BST<string, float> balanced_float_bst;
        for(int i = 0; i < 10; i++) {
            balanced_float_bst.insert("some data", float_vals[i]);
        }
        // remove float 2 children
        balanced_float_bst.remove(7.1f);
        string float_bst_str = balanced_float_bst.to_string();
        if(float_bst_str != "5.1 2.1 8.1 1.1 3.1 6.1 9.1 4.1 10.1") {
            cout << "Incorrect result of removing 7.1. Expected 5.1 2.1 8.1 1.1 3.1 6.1 9.1 4.1 10.1 but got : " << float_bst_str << endl;
        } 
        // remove float root
        balanced_float_bst.remove(5.1f);
        float_bst_str = balanced_float_bst.to_string();
        if(float_bst_str != "6.1 2.1 8.1 1.1 3.1 9.1 4.1 10.1") {
            cout << "Incorrect result of removing 5.1. Expected 6.1 2.1 8.1 1.1 3.1 9.1 4.1 10.1 but got : " << float_bst_str << endl;
        }
        // remove float 1 child
        balanced_float_bst.remove(8.1f);
        float_bst_str = balanced_float_bst.to_string();
        if(float_bst_str != "6.1 2.1 9.1 1.1 3.1 10.1 4.1") {
            cout << "Incorrect result of removing 8.1. Expected 6.1 2.1 9.1 1.1 3.1 10.1 4.1 but got : " << float_bst_str << endl;
        } 


        // string
        string string_vals[10] = {"egg", "banana", "gift", "apple", "cat", "denison", "fish", "ink", "hat", "joke"};
        BST<string, string> balanced_string_bst;
        for(int i = 0; i < 10; i++) {
            balanced_string_bst.insert("some data", string_vals[i]);
        }
        // remove string 2 children
        balanced_string_bst.remove("gift");
        string string_bst_str = balanced_string_bst.to_string();
        if(string_bst_str != "egg banana hat apple cat fish ink denison joke") {
            cout << "Incorrect result of removing gift. Expected egg banana apple cat denison fish ink hat joke but got : " << string_bst_str << endl;
        } 
        // remove string root
        balanced_string_bst.remove("egg");
        string_bst_str = balanced_string_bst.to_string();
        if(string_bst_str != "fish banana hat apple cat ink denison joke") {
            cout << "Incorrect result of removing egg. Expected fish banana hat apple cat ink denison joke but got : " << string_bst_str << endl;
        } 
        // remove string 1 child
        balanced_string_bst.remove("hat");
        string_bst_str = balanced_string_bst.to_string();
        if(string_bst_str != "fish banana ink apple cat joke denison") {
            cout << "Incorrect result of removing hat. Expected egg banana apple cat denison fish ink hat joke but got : " << string_bst_str << endl;
        } 


        // char
        char char_vals[10] = {'E', 'B', 'G', 'A', 'C', 'D', 'F', 'I', 'H', 'J'};
        BST<string, char> balanced_char_bst;
        for(int i = 0; i < 10; i++) {
            balanced_char_bst.insert("some data", char_vals[i]);
        }
        // remove char 2 children
        balanced_char_bst.remove('G');
        string char_bst_str = balanced_char_bst.to_string();
        if(char_bst_str != "E B H A C F I D J") {
            cout << "Incorrect result of removing 'G'. Expected E B H A C F I D J but got : " << char_bst_str << endl;
        }
        // remove char root
        balanced_char_bst.remove('E');
        char_bst_str = balanced_char_bst.to_string();
        if(char_bst_str != "F B H A C I D J") {
            cout << "Incorrect result of removing 'E'. Expected F B H A C I D J but got : " << char_bst_str << endl;
        }
        // remove char 1 child
        balanced_char_bst.remove('H');
        char_bst_str = balanced_char_bst.to_string();
        if(char_bst_str != "F B I A C J D") {
            cout << "Incorrect result of removing 'H'. Expected F B I A C J D but got : " << char_bst_str << endl;
        }


    } catch(exception& e) {
        cerr << "Error in removing node from bst : " << e.what() << endl;
    }
}

void test_max_data() {
    try {
        // int
        int vals[10] = {5, 2, 7, 1, 3, 4, 6, 9, 8, 10};
        BST<string, int> balanced_bst;
        for(int i = 0; i < 10; i++) {
            balanced_bst.insert(to_string(vals[i]) + " data", vals[i]);
        }
        string max_str = balanced_bst.max_data();
        if(max_str != "10 data") {
            cout << "Incorrect result of max_data. Expected \"10 data\" but got : " << max_str << endl;
        }

        // float
        float float_vals[10] = {5.1f, 2.1f, 7.1f, 1.1f, 3.1f, 4.1f, 6.1f, 9.1f, 8.1f, 10.1f};
        BST<string, float> balanced_float_bst;
        for(int i = 0; i < 10; i++) {
            balanced_float_bst.insert(to_string(float_vals[i]) + " data", float_vals[i]);
        }
        string float_max_str = balanced_float_bst.max_data();
        if(float_max_str != "10.100000 data") { 
            cout << "Incorrect result of max_data. Expected \"10.100000 data\" but got : " << float_max_str << endl;
        }

        // char
        char char_vals[10] = {'E', 'B', 'G', 'A', 'C', 'D', 'F', 'I', 'H', 'J'};
        BST<string, char> balanced_char_bst;
        for(int i = 0; i < 10; i++) {
            balanced_char_bst.insert(string(1, char_vals[i]) + " data", char_vals[i]);
        }
        string char_max_str = balanced_char_bst.max_data();
        if(char_max_str != "J data") {
            cout << "Incorrect result of max_data. Expected \"J data\" but got : " << char_max_str << endl;
        }

        // string
        string string_vals[10] = {"egg", "banana", "gift", "apple", "cat", "denison", "fish", "ink", "hat", "joke"};
        BST<string, string> balanced_string_bst;
        for(int i = 0; i < 10; i++) {
            balanced_string_bst.insert((string_vals[i]) + " data", string_vals[i]);
        }
        string string_max_str = balanced_string_bst.max_data();
        if(string_max_str != "joke data") {
            cout << "Incorrect result of max_data. Expected \"joke data\" but got : " << string_max_str << endl;
        }


    } catch(exception& e) {
        cerr << "Error in determining data of max node in bst : " << e.what() << endl;
    }
}

void test_max_key() {
    try {
        // int
        int vals[10] = {5, 2, 7, 1, 3, 4, 6, 9, 8, 10};
        BST<string, int> balanced_bst;
        for(int i = 0; i < 10; i++) {
            balanced_bst.insert(to_string(vals[i]) + " data", vals[i]);
        }
        int max_k = balanced_bst.max_key();
        if(max_k != 10) {
            cout << "Incorrect result of max_key. Expected 10 but got : " << max_k << endl;
        }

        // float 
        float float_vals[10] = {5.1f, 2.1f, 7.1f, 1.1f, 3.1f, 4.1f, 6.1f, 9.1f, 8.1f, 10.1f};
        BST<string, float> balanced_float_bst;
        for(int i = 0; i < 10; i++) {
            balanced_float_bst.insert(to_string(vals[i]) + " data", float_vals[i]);
        }
        float float_max_k = balanced_float_bst.max_key();
        if(float_max_k != 10.1f) {
            cout << "Incorrect result of max_key. Expected 10.1 but got : " << float_max_k << endl;
        }

        // char
        char char_vals[10] = {'E', 'B', 'G', 'A', 'C', 'D', 'F', 'I', 'H', 'J'};
        BST<string, char> balanced_char_bst;
        for(int i = 0; i < 10; i++) {
            balanced_char_bst.insert(string(1, vals[i]) + " data", char_vals[i]);
        }
        char char_max_k = balanced_char_bst.max_key();
        if(char_max_k != 'J') {
            cout << "Incorrect result of max_key. Expected 'J' but got : " << char_max_k << endl;
        }

        // string
        string string_vals[10] = {"egg", "banana", "gift", "apple", "cat", "denison", "fish", "ink", "hat", "joke"};
        BST<string, string> balanced_string_bst;
        for(int i = 0; i < 10; i++) {
            balanced_string_bst.insert((string_vals[i]) + " data", string_vals[i]);
        }
        string string_max_k = balanced_string_bst.max_key();
        if(string_max_k != "joke") {
            cout << "Incorrect result of max_key. Expected \"joke\" but got : " << string_max_k << endl;
        }

    } catch(exception& e) {
        cerr << "Error in determining key of max node in bst : " << e.what() << endl;
    }
}

void test_min_data() {
    try {
        // int 
        int vals[10] = {5, 2, 7, 1, 3, 4, 6, 9, 8, 10};
        BST<string, int> balanced_bst;
        for(int i = 0; i < 10; i++) {
            balanced_bst.insert(to_string(vals[i]) + " data", vals[i]);
        }
        string min_str = balanced_bst.min_data();
        if(min_str != "1 data") {
            cout << "Incorrect result of min_data. Expected \"1 data\" but got : " << min_str << endl;
        }

        // float
        float float_vals[10] = {5.1, 2.1, 7.1, 1.1, 3.1, 4.1, 6.1, 9.1, 8.1, 10.1};
        BST<string, float> balanced_float_bst;
        for(int i = 0; i < 10; i++) {
            balanced_float_bst.insert(to_string(float_vals[i]) + " data", float_vals[i]);
        }
        string float_min_str = balanced_float_bst.min_data();
        if(float_min_str != "1.100000 data") {
            cout << "Incorrect result of min_data. Expected \"1.100000 data\" but got : " << float_min_str << endl;
        }
        
        // char
        char char_vals[10] = {'E', 'B', 'G', 'A', 'C', 'D', 'F', 'I', 'H', 'J'};
        BST<string, char> balanced_char_bst;
        for(int i = 0; i < 10; i++) {
            balanced_char_bst.insert(string(1, char_vals[i]) + " data", char_vals[i]);
        }
        string char_min_str = balanced_char_bst.min_data();
        if(char_min_str != "A data") {
            cout << "Incorrect result of min_data. Expected \"A data\" but got : " << char_min_str << endl;
        }

        // string
        string string_vals[10] = {"egg", "banana", "gift", "apple", "cat", "denison", "fish", "ink", "hat", "joke"};
        BST<string, string> balanced_string_bst;
        for(int i = 0; i < 10; i++) {
            balanced_string_bst.insert((string_vals[i]) + " data", string_vals[i]);
        }
        string string_min_str = balanced_string_bst.min_data();
        if(string_min_str != "apple data") {
            cout << "Incorrect result of min_data. Expected \"apple data\" but got : " << string_min_str << endl;
        }

    } catch(exception& e) {
        cerr << "Error in determining data of min node in bst : " << e.what() << endl;
    }
}

void test_min_key() {
    try {
        // int 
        int vals[10] = {5, 2, 7, 1, 3, 4, 6, 9, 8, 10};
        BST<string, int> balanced_bst;
        for(int i = 0; i < 10; i++) {
            balanced_bst.insert(to_string(vals[i]) + " data", vals[i]);
        }
        int min_k = balanced_bst.min_key();
        if(min_k != 1) {
            cout << "Incorrect result of min_key. Expected 10 but got : " << min_k << endl;
        }

        // float

        float float_vals[10] = {5.1f, 2.1f, 7.1f, 1.1f, 3.1f, 4.1f, 6.1f, 9.1f, 8.1f, 10.1f};
        BST<string, float> balanced_float_bst;
        for(int i = 0; i < 10; i++) {
            balanced_float_bst.insert(to_string(vals[i]) + " data", float_vals[i]);
        }
        float float_min_k = balanced_float_bst.min_key();
        if(float_min_k != 1.1f) { 
            cout << "Incorrect result of min_key. Expected 1.1 but got : " << float_min_k << endl;
        }

        // char
        char char_vals[10] = {'E', 'B', 'G', 'A', 'C', 'D', 'F', 'I', 'H', 'J'};
        BST<string, char> balanced_char_bst;
        for(int i = 0; i < 10; i++) {
            balanced_char_bst.insert(string(1, vals[i]) + " data", char_vals[i]);
        }
        char char_min_k = balanced_char_bst.min_key();
        if(char_min_k != 'A') {
            cout << "Incorrect result of min_key. Expected 'A' but got : " << char_min_k << endl;
        }


        // string
        string string_vals[10] = {"egg", "banana", "gift", "apple", "cat", "denison", "fish", "ink", "hat", "joke"};
        BST<string, string> balanced_string_bst;
        for(int i = 0; i < 10; i++) {
            balanced_string_bst.insert((string_vals[i]) + " data", string_vals[i]);
        }
        string string_min_k = balanced_string_bst.min_key();
        if(string_min_k != "apple") {
            cout << "Incorrect result of min_key. Expected \"apple\" but got : " << char_min_k << endl;
        }

    } catch(exception& e) {
        cerr << "Error in determining key of min node in bst : " << e.what() << endl;
    }
}

void test_successor() {
    try {
        // int
        int vals[10] = {5, 2, 7, 1, 3, 4, 6, 9, 8, 10};
        BST<string, int> balanced_bst;
        for(int i = 0; i < 10; i++) {
            balanced_bst.insert(to_string(vals[i]) + " data", vals[i]);
        }
        int succ = balanced_bst.successor(4);
        if(succ != 5) {
            cout << "Incorrect result of successor of 4. Expected 5 but got : " << succ << endl;
        }
        succ = balanced_bst.successor(7);
        if(succ != 8) {
            cout << "Incorrect result of successor of 7. Expected 8 but got : " << succ << endl;
        }
        succ = balanced_bst.successor(10);
        if(succ != 0) {
            cout << "Incorrect result of successor of 10. Expected 0 but got : " << succ << endl;
        }

        // float
        float float_vals[10] = {5.1f, 2.1f, 7.1f, 1.1f, 3.1f, 4.1f, 6.1f, 9.1f, 8.1f, 10.1f};
        BST<string, float> balanced_float_bst;
        for(int i = 0; i < 10; i++) {
            balanced_float_bst.insert(to_string(float_vals[i]) + " data", float_vals[i]);
        }
        float float_succ = balanced_float_bst.successor(4.1f);
        if(float_succ != 5.1f) {
            cout << "Incorrect result of successor of 4.1. Expected 5.1 but got : " << float_succ << endl;
        }
        float_succ = balanced_float_bst.successor(7.1f);
        if(float_succ != 8.1f) {
            cout << "Incorrect result of successor of 7.1. Expected 8.1 but got : " << float_succ << endl;
        }
        float_succ = balanced_float_bst.successor(10.1f);
        if(float_succ != 0) {
            cout << "Incorrect result of successor of 10.1. Expected 0 but got : " << float_succ << endl;
        } 

        // char
        char char_vals[10] = {'E', 'B', 'G', 'A', 'C', 'D', 'F', 'I', 'H', 'J'};
        BST<string, char> balanced_char_bst;
        for(int i = 0; i < 10; i++) {
            balanced_char_bst.insert(string(1, char_vals[i]) + " data", char_vals[i]);
        }
        char char_succ = balanced_char_bst.successor('D');
        if(char_succ != 'E') {
            cout << "Incorrect result of successor of 'D'. Expected 'E' but got : " << char_succ << endl;
        }
        char_succ = balanced_char_bst.successor('G');
        if(char_succ != 'H') {
            cout << "Incorrect result of successor of 'G'. Expected 'H' but got : " << char_succ << endl;
        }
        char_succ = balanced_char_bst.successor('J');
        if(char_succ != '\0') { 
            cout << "Incorrect result of successor of 'J'. Expected "" but got : " << char_succ << endl;
        } 

        // string
        string string_vals[10] = {"egg", "banana", "gift", "apple", "cat", "denison", "fish", "ink", "hat", "joke"};
        BST<string, string> balanced_string_bst;
        for(int i = 0; i < 10; i++) {
            balanced_string_bst.insert((string_vals[i]) + " data", string_vals[i]);
        }
        string string_succ = balanced_string_bst.successor("denison");
        if(string_succ != "egg") {
            cout << "Incorrect result of successor of \"denison\". Expected \"egg\" but got : " << string_succ << endl;
        }
        string_succ = balanced_string_bst.successor("gift");
        if(string_succ != "hat") {
            cout << "Incorrect result of successor of \"gift\". Expected \"hat\" but got : " << string_succ << endl;
        }
        string_succ = balanced_string_bst.successor("joke");
        if(string_succ != "") { 
            cout << "Incorrect result of successor of \"joke\". Expected "" but got : " << string_succ << endl;
        } 


    } catch(exception& e) {
        cerr << "Error in determining successor in bst : " << e.what() << endl;
    }
}

void test_in_order() {
    try {
        // int
        BST<string, int> bst;
        for(int i = 1; i <= 10; i++) {
            bst.insert("some data", i);
        }
        string bst_str = bst.in_order();
        if(bst_str != "1 2 3 4 5 6 7 8 9 10") {
            cout << "Incorrect in_order result after inserting keys 1-10 in order. Expected 1 2 3 4 5 6 7 8 9 10 but got : " << bst_str << endl;
        }
        int vals[10] = {5, 2, 7, 1, 3, 4, 6, 9, 8, 10};
        BST<string, int> balanced_bst;
        for(int i = 0; i < 10; i++) {
            balanced_bst.insert("some data", vals[i]);
        }
        bst_str = balanced_bst.in_order();
        if(bst_str != "1 2 3 4 5 6 7 8 9 10") {
            cout << "Incorrect in_order result after inserting keys {5, 2, 7, 1, 3, 4, 6, 9, 8, 10}. Expected 1 2 3 4 5 6 7 8 9 10 but got : " << bst_str << endl;
        }

        // float
        BST<string, float> float_bst;
        for(float i = 1.1f; i <= 10.1f; i ++) {
            float_bst.insert("some data", i);
        }
        string float_bst_str = float_bst.in_order();
        if(float_bst_str != "1.1 2.1 3.1 4.1 5.1 6.1 7.1 8.1 9.1 10.1") {
            cout << "Incorrect in_order result after inserting keys 1.1-10.1 in order. Expected 1.1 2.1 3.1 4.1 5.1 6.1 7.1 8.1 9.1 10.1 but got : " << float_bst_str << endl;
        }

        float float_vals[10] = {5.1f, 2.1f, 7.1f, 1.1f, 3.1f, 4.1f, 6.1f, 9.1f, 8.1f, 10.1f};
        BST<string, float> balanced_float_bst;
        for(int i = 0; i < 10; i++) {
            balanced_float_bst.insert("some data", float_vals[i]);
        }
        float_bst_str = balanced_float_bst.in_order();
        if(float_bst_str != "1.1 2.1 3.1 4.1 5.1 6.1 7.1 8.1 9.1 10.1") {
            cout << "Incorrect in_order result after inserting keys {5.1, 2.1, 7.1, 1.1, 3.1, 4.1, 6.1, 9.1, 8.1, 10.1}. Expected 1.1 2.1 3.1 4.1 5.1 6.1 7.1 8.1 9.1 10.1 but got : " << float_bst_str << endl;
        }

        // char
        char char_vals[10] = {'E', 'B', 'G', 'A', 'C', 'D', 'F', 'I', 'H', 'J'};
        BST<string, char> balanced_char_bst;
        for(int i = 0; i < 10; i++) {
            balanced_char_bst.insert(string(1, char_vals[i]) + " data", char_vals[i]);
        }
        string char_bst_str = balanced_char_bst.in_order();
        if(char_bst_str != "A B C D E F G H I J") {
            cout << "Incorrect in_order result after inserting chars. Expected A B C D E F G H I J but got : " << char_bst_str << endl;
        }

        // string
        string string_vals[10] = {"egg", "banana", "gift", "apple", "cat", "denison", "fish", "ink", "hat", "joke"};
        BST<string, string> balanced_string_bst;
        for(int i = 0; i < 10; i++) {
            balanced_string_bst.insert((string_vals[i]) + " data", string_vals[i]);
        }
        string string_bst_str = balanced_string_bst.in_order();
        if(string_bst_str != "apple banana cat denison egg fish gift hat ink joke") {
            cout << "Incorrect in_order result after inserting chars. Expected apple banana cat denison egg fish gift hat ink joke but got : " << string_bst_str << endl;
        }


    } catch(exception& e) {
        cerr << "Error getting keys in_order from bst : " << e.what() << endl;
    }
}

void test_trim() {
    try {
        // int
        BST<string,int> bst;
        int vals[3] = {1, 0, 2};
        for(int i = 0; i < 3; i++) {
            bst.insert(to_string(vals[i])+" data", vals[i]);
        }
        bst.trim(1,2);
        string bst_str = bst.to_string();
        if(bst_str != "1 2") {
            cout << "Incorrect tree after trimming 1 0 2 with low=1, high=2. Expected 1 2 but got : " << bst_str << endl;
        }
        BST<string, int> bst2;
        int vals2[5] = {3, 0, 4, 2, 1};
        for(int i = 0; i < 5; i++) {
            bst2.insert(to_string(vals2[i])+" data", vals2[i]);
        }
        bst2.trim(1,3);
        bst_str = bst2.to_string();
        if(bst_str != "3 2 1") {
            cout << "Incorrect tree after trimming 3 0 4 2 1 with low=1, high=3. Expected 3 2 1 but got : " << bst_str << endl;
        }

        // float
        BST<string, float> float_bst;
        float float_vals[3] = {1.1f, 0.1f, 2.1f};
        for(int i = 0; i < 3; i++) {
            float_bst.insert(to_string(float_vals[i]) + " data", float_vals[i]);
        }
        float_bst.trim(1.1f, 2.1f);
        string float_bst_str = float_bst.to_string();
        if(float_bst_str != "1.1 2.1") {
            cout << "Incorrect tree after trimming 1.1 0.1 2.1 with low=1.1, high=2.1. Expected 1.1 2.1 but got : " << float_bst_str << endl;
        }

        BST<string, float> float_bst2;
        float float_vals2[5] = {3.1f, 0.1f, 4.1f, 2.1f, 1.1f};
        for(int i = 0; i < 5; i++) {
            float_bst2.insert(to_string(float_vals2[i]) + " data", float_vals2[i]);
        }
        float_bst2.trim(1.1f, 3.1f);
        float_bst_str = float_bst2.to_string();
        if(float_bst_str != "3.1 2.1 1.1") {
            cout << "Incorrect tree after trimming 3.1 0.1 4.1 2.1 1.1 with low=1.1, high=3.1. Expected 3.1 2.1 1.1 but got : " << float_bst_str << endl;
        }


        // char

        BST<string,char> char_bst;
        char char_vals[3] = {'B', 'A', 'C'};
        for(int i = 0; i < 3; i++) {
            char_bst.insert(to_string(char_vals[i])+" data", char_vals[i]);
        }
        char_bst.trim('B', 'C');
        string char_bst_str = char_bst.to_string();
        if(char_bst_str != "B C") {
            cout << "Incorrect tree after trimming A B C with low=B, high=C. Expected B C but got : " << char_bst_str << endl;
        }

        BST<string, char> char_bst2;
        char char_vals2[5] = {'D', 'E', 'A', 'B', 'C'};
        for(int i = 0; i < 5; i++) {
            char_bst2.insert(to_string(char_vals2[i]) + " data", char_vals2[i]);
        }
        char_bst2.trim('B', 'D');
        char_bst_str = char_bst2.to_string();
        if(char_bst_str != "D B C") {
            cout << "Incorrect tree after trimming D A E B C with low=B, high=D. Expected D B C but got : " << char_bst_str << endl;
        }

        // string

        BST<string,string> string_bst;
        string string_vals[3] = {"banana", "apple", "cat"};
        for(int i = 0; i < 3; i++) {
            string_bst.insert((string_vals[i])+" data", string_vals[i]);
        }
        string_bst.trim("banana", "cat");
        string string_bst_str = string_bst.to_string();
        if(string_bst_str != "banana cat") {
            cout << "Incorrect tree after trimming apple banana cat with low=banana, high=cat. Expected banana cat but got : " << string_bst_str << endl;
        }

        BST<string, string> string_bst2;
        string string_vals2[5] = {"dog", "egg", "apple", "banana", "cat"};
        for(int i = 0; i < 5; i++) {
            string_bst2.insert((string_vals2[i]) + " data", string_vals2[i]);
        }
        string_bst2.trim("apple", "dog");
        string_bst_str = string_bst2.to_string();
        if(string_bst_str != "dog apple banana cat") {
            cout << "Incorrect tree after trimming dog egg apple banana cat with low=apple, high=dog. Expected dog apple banana cat but got : " << string_bst_str << endl;
        }

    } catch(exception& e) {
        cerr << "Error in trimming the bst : " << e.what() << endl;
    }
}

void test_binhex(){
    try {
        // letters then numbers
        BST<string,string>* bst1 = create_bst<string,string>("binhex.txt");
        string bin1 = "111010100101";
        string expected_hex1 = "EA5";

        string hex1 = convert<string,string>(bst1, bin1);
        delete bst1;

        if(hex1!=expected_hex1) {
            cout << "Incorrect result converting " << bin1 << " to hex. Expected : " << expected_hex1 << ", but got : " << hex1 << endl;
        }

    } catch(exception& e) {
        cerr << "Error converting binary to hex : " << e.what() << endl;
    }

    try {
        // numbers only
        BST<string,string>* bst2 = create_bst<string,string>("binhex.txt");
        string bin2 = "110101";
        string expected_hex2 = "35";

        string hex2 = convert<string,string>(bst2, bin2);
        delete bst2;

        if(hex2!=expected_hex2) {
            cout << "Incorrect result converting " << bin2 << " to hex. Expected : " << expected_hex2 << ", but got : " << hex2 << endl;
        }

    } catch(exception& e) {
        cerr << "Error converting binary to hex : " << e.what() << endl;
    }

    try {
        // leading zeros
        BST<string,string>* bst3 = create_bst<string,string>("binhex.txt");
        string bin3 = "0000000001";
        string expected_hex3 = "001";

        string hex3 = convert<string,string>(bst3, bin3);
        delete bst3;

        if(hex3!=expected_hex3) {
            cout << "Incorrect result converting " << bin3 << " to hex. Expected : " << expected_hex3 << ", but got : " << hex3 << endl;
        }

    } catch(exception& e) {
        cerr << "Error converting binary to hex : " << e.what() << endl;
    }
    try {
        // letter in between numbers
        BST<string,string>* bst4 = create_bst<string,string>("binhex.txt");
        string bin4 = "100110111001";
        string expected_hex4 = "9B9";

        string hex4 = convert<string,string>(bst4, bin4);
        delete bst4;

        if(hex4!=expected_hex4) {
            cout << "Incorrect result converting " << bin4 << " to hex. Expected : " << expected_hex4 << ", but got : " << hex4 << endl;
        }

    } catch(exception& e) {
        cerr << "Error converting binary to hex : " << e.what() << endl;
    }

    try {
        // non-binary
        BST<string,string>* bst5 = create_bst<string,string>("binhex.txt");
        string bin5 = "1234567890";
        string expected_hex5 = "Error in binary string.";

        string hex5 = convert<string,string>(bst5, bin5);
        delete bst5;

        if(hex5!=expected_hex5) {
            cout << "Incorrect result converting " << bin5 << " to hex. Expected : " << expected_hex5 << ", but got : " << hex5 << endl;
        }

    } catch(exception& e) {
        cerr << "Error converting binary to hex : " << e.what() << endl;
    }
}

int main() {
    
    test_empty();
    test_negative();
    test_insert();
    test_get();
    test_remove();
    test_max_data();
    test_max_key();
    test_min_data();
    test_min_key();
    test_successor();
    test_in_order();
    test_trim();
    test_binhex();

    cout << "Testing completed" << endl;
    
    return 0;
}

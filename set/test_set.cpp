//
//  test_set.cpp
//  CS 271 Set Project: Test File
//
// Aryah Rao
//
#include <iostream>
#include <chrono>
#include "set.cpp"

using namespace std;

void test_insert() {
    try {
        Set<int> s;
        s.insert(0);
        string set_str = s.to_string();
        if (s.to_string() != "0") {
            cout << "Incorrect insert result. Expected 0 but got : " << set_str << endl;
        }
        s.insert(0); // Duplicate element
        set_str = s.to_string();
        if (s.to_string() != "0") {
            cout << "Incorrect insert result. Expected 0 but got : " << set_str << endl;
        }
        s.insert(2);
        s.insert(-1);
        set_str = s.to_string();
        if (s.to_string() != "-1 2 0") {
            cout << "Incorrect insert result. Expected -1 2 0 but got : " << set_str << endl;
        }
        // Test with characters
        Set<char> charSet;
        charSet.insert('a');
        charSet.insert('b');
        charSet.insert('a'); // Duplicate element
        charSet.insert('c');
        if (charSet.to_string() != "c b a") {
            cout << "Incorrect insert result for characters. Expected c b a but got : " << charSet.to_string() << endl;
        }
        // Test with strings
        Set<string> stringSet;
        stringSet.insert("apple");
        stringSet.insert("banana");
        stringSet.insert("orange");
        stringSet.insert("apple"); // Duplicate element
        // Inserting wrong input type
        /*
        s.insert("c");
        set_str = s.to_string();
        if (s.to_string() != "c -1 2 0") {
            cout << "Incorrect insert result. Expected c -1 2 0 but got : " << set_str << endl;
        }
        */
        if (stringSet.to_string() != "orange banana apple") {
            cout << "Incorrect to_string result for strings. Expected 'orange banana apple' but got : " << stringSet.to_string() << endl;
        }

    } catch (exception& e) {
        cerr << "Error inserting into set : " << e.what() << endl;
    }
}

void test_remove() {
    try {
        Set<int> s;
        s.remove(1); // Empty set, Should not throw an exception
        s.insert(1);
        s.insert(2);
        s.insert(3);
        s.insert(4);
        s.remove(5);
        string set_str = s.to_string();
        if (s.to_string() != "4 3 2 1") {
            cout << "Incorrect remove result. Expected 4 3 2 1 but got : " << set_str << endl;
        }
        s.remove(3);
        set_str = s.to_string();
        if(s.to_string() != "4 2 1") {
            cout << "Incorrect remove result. Expected 4 2 1 but got : " << set_str << endl;
        }
        // Test with characters
        Set<char> charSet;
        charSet.remove('a'); // Empty set, Should not throw an exception
        charSet.insert('a');
        charSet.insert('b');
        charSet.insert('c');
        charSet.remove('b');
        if (charSet.to_string() != "c a") {
            cout << "Incorrect result after removing element for characters. Expected 'c a' but got : " << charSet.to_string() << endl;
        }
        // Test with strings
        Set<string> stringSet;
        stringSet.remove("apple"); // Empty set, Should not throw an exception
        stringSet.insert("apple");
        stringSet.insert("banana");
        stringSet.insert("orange");
        stringSet.remove("banana"); // Duplicate element
        if (stringSet.to_string() != "orange apple") {
            cout << "Incorrect to_string result for strings. Expected 'orange apple' but got : " << stringSet.to_string() << endl;
        }
        // Removing wrong input type
        /*
        s.remove("c"); // Should not give excepion
        */
    } catch (exception &e) {
        cerr << "Error removing from set : " << e.what() << endl;
    }
}

void test_cardinality() {
    try {
        Set<int> s;
        int c = s.cardinality();
        if(c != 0) {
            cout << "Incorrect cardinality. Expected 0 but got : " << c << endl;
        }
        s.insert(6);
        s.insert(5);
        s.insert(4);
        s.insert(3);
        s.insert(2);
        c = s.cardinality();
        if(c != 5) {
            cout << "Incorrect cardinality. Expected 5 but got : " << c << endl;
        }
        s.remove(4);
        s.remove(2);
        c = s.cardinality();
        if(c != 3) {
            cout << "Incorrect cardinality. Expected 3 but got : " << c << endl;
        }
        s.insert(6); // Duplicate element
        s.insert(5); // Duplicate element
        c = s.cardinality();
        if(c != 3) {
            cout << "Incorrect cardinality. Expected 3 but got : " << c << endl;
        }
        // Test with characters
        Set<char> charSet;
        charSet.insert('a');
        charSet.insert('b');
        charSet.insert('a'); // Duplicate element
        charSet.insert('c');

        if (charSet.cardinality() != 3) {
            cout << "Incorrect cardinality result for characters. Expected 3 but got : " << charSet.cardinality() << endl;
        }
        charSet.remove('b');
        if (charSet.cardinality() !=2) {
            cout << "Incorrect cardinality result for characters. Expected 2 but got : " << charSet.cardinality() << endl;
        }
        // Test with strings
        Set<string> stringSet;
        stringSet.insert("apple");
        stringSet.insert("banana");
        stringSet.insert("orange");
        stringSet.insert("apple"); // Duplicate element
        if (stringSet.cardinality() != 3) {
            cout << "Incorrect cardinality result for strings. Expected 3 but got : " << stringSet.cardinality() << endl;
        }
        charSet.remove('b');
        if (charSet.cardinality() !=2) {
            cout << "Incorrect cardinality result for characters. Expected 2 but got : " << charSet.cardinality() << endl;
        }
    } catch (exception &e) {
        cerr << "Error in determining set cardinality : " << e.what() << endl;
    }
}

void test_empty() {
    try {
        Set<int> s;
        if(!s.empty()){
            cout << "Empty set identified as non-empty" << endl;
        }
        s.insert(1);
        s.insert(2);
        if(s.empty()) {
            cout << "Non-empty set identified as empty" << endl;
        }
        s.remove(2);
        if(s.empty()) {
            cout << "Non-empty set identified as empty" << endl;
        }
        s.remove(1);
        if(!s.empty()) {
            cout << "Empty set identified as non-empty" << endl;
        }
        // Test with characters
        Set<char> charSet;
        if (!charSet.empty()) {
            cout << "Empty set identified as non-empty" << endl;
        }
        charSet.insert('a');
        if (charSet.empty()) {
            cout << "Non-empty set identified as empty" << endl;
        }
        charSet.remove('a');
        if (!charSet.empty()) {
            cout << "Empty set identified as non-empty" << endl;
        }
        // Test with strings
        Set<string> stringSet;
        if (!stringSet.empty()) {
            cout << "Empty set identified as non-empty" << endl;
        }
        stringSet.insert("apple");
        if (stringSet.empty()) {
            cout << "Non-empty set identified as empty" << endl;
        }
        stringSet.remove("apple");
        if (!stringSet.empty()) {
            cout << "Empty set identified as non-empty" << endl;
        }
    } catch (exception &e) {
        cerr << "Error in determining if set is the empty set : " << e.what() << endl;
    }
}

void test_contains() {
    try {
        Set<int> s;
        if(s.contains(5)) {
            cout << "Incorrectly identified 5 as in the set " << s.to_string() << endl;
        }
        s.insert(1);
        s.insert(2);
        s.insert(3);
        if(s.contains(5)) {
            cout << "Incorrectly identified 5 as in the set " << s.to_string() << endl;
        }
        if(!s.contains(2)) {
            cout << "Incorrectly identified 2 as NOT in the set " << s.to_string() << endl;
        }
        // Test with characters
        Set<char> charSet;
        if(charSet.contains('a')) {
            cout << "Incorrectly identified a as in the set " << s.to_string() << endl;
        }
        charSet.insert('a');
        charSet.insert('b');
        charSet.insert('c');
        if(charSet.contains('z')) {
            cout << "Incorrectly identified z as in the set " << s.to_string() << endl;
        }
        if(!charSet.contains('a')) {
            cout << "Incorrectly identified a as NOT in the set " << s.to_string() << endl;
        }
        // Test with strings
        Set<string> stringSet;
        if(stringSet.contains("apple")) {
            cout << "Incorrectly identified apple as in the set " << s.to_string() << endl;
        }
        stringSet.insert("apple");
        stringSet.insert("banana");
        stringSet.insert("orange");
        if(stringSet.contains("watermelon")) {
            cout << "Incorrectly identified watermelon as in the set " << s.to_string() << endl;
        }
        if(!stringSet.contains("apple")) {
            cout << "Incorrectly identified apple as NOT in the set " << s.to_string() << endl;
        }
    } catch (exception &e) {
        cerr << "Error in determining if value contained in se : " << e.what() << endl;
    }
}

void test_equality() {
    try {
        Set<int> s;
        Set<int> t;
        if(!(s==t)) {
            cout << "Empty sets should be considered equal" << endl;
        }
        s.insert(1);
        s.insert(2);
        s.insert(3);
        if(s==t) {
            cout << "Incorrectly identified set " << s.to_string() << " as equivalent to " << t.to_string() << endl;
        }
        t.insert(1);
        t.insert(2);
        t.insert(3);
        if(!(s==t)) {
            cout << "Sets " << s.to_string() << " and " << t.to_string() << " should be considered equal." << endl;
        }
        s.remove(3);
        if(s==t) {
            cout << "Incorrectly identified set " << s.to_string() << " as equivalent to " << t.to_string() << endl;
        }
        // Test with characters
        Set<char> charSet1;
        Set<char> charSet2;
        if(!(charSet1==charSet2)) {
            cout << "Empty sets should be considered equal" << endl;
        }
        charSet1.insert('a');
        charSet1.insert('b');
        charSet1.insert('c');
        if(charSet1==charSet2) {
            cout << "Incorrectly identified set " << charSet1.to_string() << " as equivalent to " << charSet2.to_string() << endl;
        }
        charSet2.insert('a');
        charSet2.insert('b');
        charSet2.insert('c');
        if(!(charSet1==charSet2)) {
            cout << "Sets " << charSet1.to_string() << " and " << t.to_string() << " should be considered equal." << endl;
        }
        charSet1.remove('b');
        if(charSet1==charSet2) {
            cout << "Incorrectly identified set " << charSet1.to_string() << " as equivalent to " << charSet2.to_string() << endl;
        }
        // Test with strings
        Set<string> stringSet1;
        Set<string> stringSet2;
        if(!(stringSet1==stringSet2)) {
            cout << "Empty sets should be considered equal" << endl;
        }
        stringSet1.insert("apple");
        stringSet1.insert("banana");
        stringSet1.insert("orange");
        if(stringSet1==stringSet2) {
            cout << "Incorrectly identified set " << stringSet1.to_string() << " as equivalent to " << stringSet2.to_string() << endl;
        }
        stringSet2.insert("apple");
        stringSet2.insert("banana");
        stringSet2.insert("orange");
        if(!(stringSet1==stringSet2)) {
            cout << "Sets " << stringSet1.to_string() << " and " << t.to_string() << " should be considered equal." << endl;
        }
        stringSet1.remove("banana");
        if(stringSet1==stringSet2) {
            cout << "Incorrectly identified set " << stringSet1.to_string() << " as equivalent to " << stringSet2.to_string() << endl;
        }
        /*
        // Different data type test 1
        Set<int> sdt1;
        Set<char> tdt1;
                if(!(sdt1==tdt1)) {
            cout << "Empty sets should be considered equal" << endl;
        }
        sdt1.insert(1);
        tdt1.insert('z');
        if(sdt1==tdt1) {
            cout << "Incorrectly identified set " << sdt1.to_string() << " as equivalent to " << tdt1.to_string() << endl;
        }
        // Different data type test 2
        Set<int> sdt2;
        Set<char> tdt2;
        sdt2.insert(1);
        sdt2.insert(2);
        sdt2.insert(3);
        if(sdt2==tdt2) {
            cout << "Incorrectly identified set " << s.to_string() << " as equivalent to " << tdt2.to_string() << endl;
        }
        tdt2.insert('1');
        tdt2.insert('2');
        tdt2.insert('3');
        if(sdt2==tdt2) {
            cout << "Incorrectly identified set " << s.to_string() << " as equivalent to " << tdt2.to_string() << endl;
        }
        // Different data type test 3
        Set<int> sdt3;
        Set<char> tdt3;
        sdt3.insert(97);
        sdt3.insert(98);
        sdt3.insert(99);
        if(sdt3==tdt3) {
            cout << "Incorrectly identified set " << sdt3.to_string() << " as equivalent to " << tdt3.to_string() << endl;
        }
        tdt3.insert('a');
        tdt3.insert('b');
        tdt3.insert('c');
        if(sdt3==tdt3) {
            cout << "Incorrectly identified set " << sdt3.to_string() << " as equivalent to " << tdt3.to_string() << endl;
        }
        */
    } catch (exception &e) {
        cerr << "Error in determining set equality : " << e.what() << endl;
    }
}

void test_subset() {
    try {
        Set<int> s;
        Set<int> t;
        if(!(s<=t)) {
            cout << "Set " << s.to_string() << " should be considered a subset of the set " << t.to_string() << endl;
        }
        t.insert(3);
        t.insert(7);
        if(!(s<=t)) {
            cout << "Set " << s.to_string() << " should be considered a subset of the set " << t.to_string() << endl;
        }
        s.insert(7);
        s.insert(3);
        if(!(s<=t)) {
            cout << "Set " << s.to_string() << " should be considered a subset of the set " << t.to_string() << endl;
        }
        t.insert(10);
        if(!(s<=t)) {
            cout << "Set " << s.to_string() << " should be considered a subset of the set " << t.to_string() << endl;
        }
        s.insert(11);
        if(s<=t) {
            cout << "Set " << s.to_string() << " should NOT be considered a subset of the set " << t.to_string() << endl;
        }
        // Test with char
        Set<char> charSet1;
        Set<char> charSet2;
        if(!(charSet1<=charSet2)) {
            cout << "Set " << charSet1.to_string() << " should be considered a subset of the set " << charSet2.to_string() << endl;
        }
        if(!(charSet2<=charSet1)) {
            cout << "Set " << charSet2.to_string() << " should be considered a subset of the set " << charSet1.to_string() << endl;
        }
        charSet2.insert('a');
        charSet2.insert('b');
        if(!(charSet1<=charSet2)) {
            cout << "Set " << charSet1.to_string() << " should be considered a subset of the set " << charSet2.to_string() << endl;
        }
        if((charSet2<=charSet1)) {
            cout << "Set " << charSet2.to_string() << " should NOT be considered a subset of the set " << charSet1.to_string() << endl;
        }
        charSet1.insert('b');
        charSet1.insert('a');
        if(!(charSet1<=charSet2)) {
            cout << "Set " << charSet1.to_string() << " should be considered a subset of the set " << charSet2.to_string() << endl;
        }
        if(!(charSet2<=charSet1)) {
            cout << "Set " << charSet2.to_string() << " should be considered a subset of the set " << charSet1.to_string() << endl;
        }
        charSet2.insert('c');
        if(!(charSet1<=charSet2)) {
            cout << "Set " << charSet1.to_string() << " should be considered a subset of the set " << charSet2.to_string() << endl;
        }
        if((charSet2<=charSet1)) {
            cout << "Set " << charSet2.to_string() << " should NOT be considered a subset of the set " << charSet1.to_string() << endl;
        }
        charSet1.insert('d');
        if(charSet1<=charSet2) {
            cout << "Set " << charSet1.to_string() << " should NOT be considered a subset of the set " << charSet2.to_string() << endl;
        }
        if((charSet2<=charSet1)) {
            cout << "Set " << charSet2.to_string() << " should NOT be considered a subset of the set " << charSet1.to_string() << endl;
        }
        // Test with string
        Set<string> stringSet1;
        Set<string> stringSet2;
        if(!(stringSet1<=stringSet2)) {
            cout << "Set " << stringSet1.to_string() << " should be considered a subset of the set " << stringSet2.to_string() << endl;
        }
        if(!(stringSet2<=stringSet1)) {
            cout << "Set " << stringSet2.to_string() << " should be considered a subset of the set " << stringSet1.to_string() << endl;
        }
        stringSet2.insert("apple");
        stringSet2.insert("banana");
        if(!(stringSet1<=stringSet2)) {
            cout << "Set " << stringSet1.to_string() << " should be considered a subset of the set " << stringSet2.to_string() << endl;
        }
        if((stringSet2<=stringSet1)) {
            cout << "Set " << stringSet2.to_string() << " should NOT be considered a subset of the set " << stringSet1.to_string() << endl;
        }
        stringSet1.insert("banana");
        stringSet1.insert("apple");
        if(!(stringSet1<=stringSet2)) {
            cout << "Set " << stringSet1.to_string() << " should be considered a subset of the set " << stringSet2.to_string() << endl;
        }
        if(!(stringSet2<=stringSet1)) {
            cout << "Set " << stringSet2.to_string() << " should be considered a subset of the set " << stringSet1.to_string() << endl;
        }
        stringSet2.insert("orange");
        if(!(stringSet1<=stringSet2)) {
            cout << "Set " << stringSet1.to_string() << " should be considered a subset of the set " << stringSet2.to_string() << endl;
        }
        if((stringSet2<=stringSet1)) {
            cout << "Set " << stringSet2.to_string() << " should NOT be considered a subset of the set " << stringSet1.to_string() << endl;
        }
        stringSet1.insert("watermelon");
        if(stringSet1<=stringSet2) {
            cout << "Set " << stringSet1.to_string() << " should NOT be considered a subset of the set " << stringSet2.to_string() << endl;
        }
        if((stringSet2<=stringSet1)) {
            cout << "Set " << stringSet2.to_string() << " should NOT be considered a subset of the set " << stringSet1.to_string() << endl;
        }
    } catch (exception& e) {
        cerr << "Error in determining subset : " << e.what() << endl;
    }
}

void test_union() {
    try {
        Set<int> s;
        Set<int> t;
        string set_str = (s+t).to_string();
        if(set_str != "") {
            cout << "Union of the empty sets should be the empty set. Instead got : " << set_str << endl;
        }
        s.insert(1);
        s.insert(2);
        t.insert(2);
        t.insert(1);
        set_str = (s+t).to_string();
        if(set_str != "2 1") {
            cout << "Union of " << s.to_string() << " and " << t.to_string() << " was expected to be 2 1 but instead got : " << set_str << endl;
        }
        t.insert(6);
        set_str = (s+t).to_string();
        if(set_str != "2 1 6") {
            cout << "Union of " << s.to_string() << " and " << t.to_string() << " was expected to be 2 1 6 but instead got : " << set_str << endl;
        }
        set_str = (t+s).to_string();
        if(set_str != "6 1 2") {
            cout << "Union of " << s.to_string() << " and " << t.to_string() << " was expected to be 6 1 2 but instead got : " << set_str << endl;
        }
        // Test with char
        Set<char> charSet1;
        Set<char> charSet2;
        string set_char = (charSet1+charSet2).to_string();
        if(set_char != "") {
            cout << "Union of the empty sets should be the empty set. Instead got : " << set_char << endl;
        }
        charSet1.insert('a');
        charSet1.insert('b');
        charSet2.insert('b');
        charSet2.insert('a');
        set_char = (charSet1+charSet2).to_string();
        if(set_char != "b a") {
            cout << "Union of " << charSet1.to_string() << " and " << charSet2.to_string() << " was expected to be b a but instead got : " << set_char << endl;
        }
        charSet2.insert('z');
        set_char = (charSet1+charSet2).to_string();
        if(set_char != "b a z") {
            cout << "Union of " << charSet1.to_string() << " and " << charSet2.to_string() << " was expected to be b a z but instead got : " << set_char << endl;
        }
        set_char = (charSet2+charSet1).to_string();
        if(set_char != "z a b") {
            cout << "Union of " << charSet2.to_string() << " and " << charSet1.to_string() << " was expected to be z a b but instead got : " << set_char << endl;
        }
        // Test with string
        Set<string> stringSet1;
        Set<string> stringSet2;
        string set_string = (stringSet1+stringSet2).to_string();
        if(set_string != "") {
            cout << "Union of the empty sets should be the empty set. Instead got : " << set_char << endl;
        }
        stringSet1.insert("apple");
        stringSet1.insert("banana");
        stringSet2.insert("banana");
        stringSet2.insert("apple");
        set_string = (stringSet1+stringSet2).to_string();
        if(set_string != "banana apple") {
            cout << "Union of " << stringSet1.to_string() << " and " << stringSet2.to_string() << " was expected to be banana apple but instead got : " << set_string << endl;
        }
        stringSet2.insert("orange");
        set_string = (stringSet1+stringSet2).to_string();
        if(set_string != "banana apple orange") {
            cout << "Union of " << stringSet1.to_string() << " and " << stringSet2.to_string() << " was expected to be banana apple orange but instead got : " << set_string << endl;
        }
        set_string = (stringSet2+stringSet1).to_string();
        if(set_string != "orange apple banana") {
            cout << "Union of " << stringSet2.to_string() << " and " << stringSet1.to_string() << " was expected to be orange apple banana but instead got : " << set_string << endl;
        }
    } catch (exception& e) {
        cerr << "Error in generating the union set : " << e.what() << endl;
    }
}

void test_intersection() {
    try {
        Set<int> s;
        Set<int> t;
        string set_str = (s&t).to_string();
        if(set_str != "") {
            cout << "Intersection of the empty sets should be the empty set. Instead got : " << set_str << endl;
        }
        s.insert(1);
        s.insert(2);
        t.insert(6);
        set_str = (s&t).to_string();
        if(set_str != "") {
            cout << "Intersection of " << s.to_string() << " and " << t.to_string() << " was expected to be the empty set but instead got : " << set_str << endl;
        }
        t.insert(2);
        t.insert(1);
        set_str = (s&t).to_string();
        if(set_str != "1 2") {
            cout << "Intersection of " << s.to_string() << " and " << t.to_string() << " was expected to be 1 2 but instead got : " << set_str << endl;
        }
        set_str = (t&s).to_string();
        if(set_str != "2 1") {
            cout << "Intersection of " << s.to_string() << " and " << t.to_string() << " was expected to be 2 1 but instead got : " << set_str << endl;
        }
        // Test with char
        Set<char> charSet1;
        Set<char> charSet2;
        string set_char = (charSet1&charSet2).to_string();
        if(set_char != "") {
            cout << "Intersection of the empty sets should be the empty set. Instead got : " << set_char << endl;
        }
        charSet1.insert('a');
        charSet1.insert('b');
        charSet2.insert('z');
        set_char = (charSet1&charSet2).to_string();
        if(set_char != "") {
            cout << "Intersection of " << charSet1.to_string() << " and " << charSet2.to_string() << " was expected to be the empty set but instead got : " << set_char << endl;
        }
        charSet2.insert('b');
        charSet2.insert('a');
        set_char = (charSet1&charSet2).to_string();
        if(set_char != "a b") {
            cout << "Intersection of " << charSet1.to_string() << " and " << charSet2.to_string() << " was expected to be a b but instead got : " << set_char << endl;
        }
        set_char = (charSet2&charSet1).to_string();
        if(set_char != "b a") {
            cout << "Intersection of " << charSet1.to_string() << " and " << charSet2.to_string() << " was expected to be b a but instead got : " << set_char << endl;
        }
        // Test with string
        Set<string> stringSet1;
        Set<string> stringSet2;
        string set_string = (stringSet1&stringSet2).to_string();
        if(set_string != "") {
            cout << "Intersection of the empty sets should be the empty set. Instead got : " << set_string << endl;
        }
        stringSet1.insert("apple");
        stringSet1.insert("banana");
        stringSet2.insert("orange");
        set_string = (stringSet1&stringSet2).to_string();
        if(set_string != "") {
            cout << "Intersection of " << stringSet1.to_string() << " and " << stringSet2.to_string() << " was expected to be the empty set but instead got : " << set_string << endl;
        }
        stringSet2.insert("banana");
        stringSet2.insert("apple");
        set_string = (stringSet1&stringSet2).to_string();
        if(set_string != "apple banana") {
            cout << "Intersection of " << stringSet1.to_string() << " and " << stringSet2.to_string() << " was expected to be apple banana but instead got : " << set_string << endl;
        }
        set_string = (stringSet2&stringSet1).to_string();
        if(set_string != "banana apple") {
            cout << "Intersection of " << stringSet1.to_string() << " and " << stringSet2.to_string() << " was expected to be banana apple but instead got : " << set_string << endl;
        }
    } catch (exception& e) {
        cerr << "Error in generating the intersection set : " << e.what() << endl;
    }
}

void test_diff() {
    try {
        Set<int> s;
        Set<int> t;
        string set_str = (s-t).to_string();
        if(set_str != "") {
            cout << "Difference of the empty sets should be the empty set. Instead got : " << set_str << endl;
        }
        s.insert(1);
        s.insert(2);
        t.insert(6);
        set_str = (s-t).to_string();
        if(set_str != "1 2") {
            cout << "Set " << s.to_string() << " \\ Set " << t.to_string() << " was expected to be 1 2 set but instead got : " << set_str << endl;
        }
        set_str = (t-s).to_string();
        if(set_str != "6") {
            cout << "Set " << t.to_string() << " \\ Set " << s.to_string() << " was expected to be 6 set but instead got : " << set_str << endl;
        }
        t.insert(2);
        t.insert(1);
        set_str = (s-t).to_string();
        if(set_str != "") {
            cout << "Set " << s.to_string() << " \\ Set " << t.to_string() << " was expected to be the empty set set but instead got : " << set_str << endl;
        }
        // Test with char
        Set<char> charSet1;
        Set<char> charSet2;
        string set_char = (charSet1-charSet2).to_string();
        if(set_char != "") {
            cout << "Difference of the empty sets should be the empty set. Instead got : " << set_char << endl;
        }
        charSet1.insert('a');
        charSet1.insert('b');
        charSet2.insert('z');
        set_char = (charSet1-charSet2).to_string();
        if(set_char != "a b") {
            cout << "Set " << charSet1.to_string() << " \\ Set " << charSet2.to_string() << " was expected to be a b set but instead got : " << set_char << endl;
        }
        set_char = (charSet2-charSet1).to_string();
        if(set_char != "z") {
            cout << "Set " << charSet2.to_string() << " \\ Set " << charSet1.to_string() << " was expected to be z set but instead got : " << set_char << endl;
        }
        charSet2.insert('b');
        charSet2.insert('a');
        set_char = (charSet1-charSet2).to_string();
        if(set_char != "") {
            cout << "Set " << charSet1.to_string() << " \\ Set " << charSet2.to_string() << " was expected to be the empty set set but instead got : " << set_char << endl;
        }
        // Test with string
        Set<string> stringSet1;
        Set<string> stringSet2;
        string set_string = (stringSet1-stringSet2).to_string();
        if(set_string != "") {
            cout << "Difference of the empty sets should be the empty set. Instead got : " << set_string << endl;
        }
        stringSet1.insert("apple");
        stringSet1.insert("banana");
        stringSet2.insert("orange");
        set_string = (stringSet1-stringSet2).to_string();
        if(set_string != "apple banana") {
            cout << "Set " << stringSet1.to_string() << " \\ Set " << stringSet2.to_string() << " was expected to be apple banana set but instead got : " << set_string << endl;
        }
        set_string = (stringSet2-stringSet1).to_string();
        if(set_string != "orange") {
            cout << "Set " << stringSet2.to_string() << " \\ Set " << stringSet1.to_string() << " was expected to be orange set but instead got : " << set_string << endl;
        }
        stringSet2.insert("banana");
        stringSet2.insert("apple");
        set_string = (stringSet1-stringSet2).to_string();
        if(set_string != "") {
            cout << "Set " << stringSet1.to_string() << " \\ Set " << stringSet2.to_string() << " was expected to be the empty set set but instead got : " << set_string << endl;
        }
    } catch (exception& e) {
        cerr << "Error in generating the intersection set : " << e.what() << endl;
    }
}

void time_test() {
    Set<int> S;
    // TO-DO: generate large set
    Set<int> T;
    // TO-DO: generate large set
    int total = 0;

    int val = rand()%100000;
    auto begin = std::chrono::high_resolution_clock::now();
    S.insert(val);
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cout << "insert time test took " << elapsed.count() << " nanoseconds" << endl;
    total+=elapsed.count();

    begin = std::chrono::high_resolution_clock::now();
    S.remove(val);
    end = std::chrono::high_resolution_clock::now();
    elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cout << "remove time test took " << elapsed.count() << " nanoseconds" << endl;
    total+=elapsed.count();

    begin = std::chrono::high_resolution_clock::now();
    S.cardinality();
    end = std::chrono::high_resolution_clock::now();
    elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cout << "cardinality time test took " << elapsed.count() << " nanoseconds" << endl;
    total+=elapsed.count();


    begin = std::chrono::high_resolution_clock::now();
    S.empty();
    end = std::chrono::high_resolution_clock::now();
    elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cout << "empty time test took " << elapsed.count() << " nanoseconds" << endl;
    total+=elapsed.count();

    val = rand()%100000;
    begin = std::chrono::high_resolution_clock::now();
    bool r = S.contains(val);
    end = std::chrono::high_resolution_clock::now();
    elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cout << "contains time test took " << elapsed.count() << " nanoseconds" << endl;
    total+=elapsed.count();


    begin = std::chrono::high_resolution_clock::now();
    r = (S==T);
    end = std::chrono::high_resolution_clock::now();
    elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cout << "equality time test took " << elapsed.count() << " nanoseconds" << endl;
    total+=elapsed.count();


    begin = std::chrono::high_resolution_clock::now();
    r = (S<=T);
    end = std::chrono::high_resolution_clock::now();
    elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cout << "subset time test took " << elapsed.count() << " nanoseconds" << endl;
    total+=elapsed.count();


    begin = std::chrono::high_resolution_clock::now();
    Set<int> U = (S+T);
    end = std::chrono::high_resolution_clock::now();
    elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cout << "union time test took " << elapsed.count() << " nanoseconds" << endl;
    total+=elapsed.count();


    begin = std::chrono::high_resolution_clock::now();
    U = (S&T);
    end = std::chrono::high_resolution_clock::now();
    elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cout << "intersection time test took " << elapsed.count() << " nanoseconds" << endl;
    total+=elapsed.count();


    begin = std::chrono::high_resolution_clock::now();
    U = (S-T);
    end = std::chrono::high_resolution_clock::now();
    elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cout << "difference time test took " << elapsed.count() << " nanoseconds" << endl;
    total+=elapsed.count();
    cout << "Total time: " << total << endl;
}

int main() {
    test_insert();
    test_remove();
    test_cardinality();
    test_empty();
    test_contains();
    test_equality();
    test_subset();
    test_union();
    test_intersection();
    test_diff();

    time_test();
    
    cout << "Testing completed" << endl;
    
    return 0;
}




//=================================
// Andrew Angulo, Ethan Tecson and Aryah Rao
// test_minqueue.cpp
// Feb 2024
// This file contains the test cases for priory queue, based on Dr. Truex's test_minqueue_example.cpp file.
//=================================

#include <iostream>
#include <chrono>
#include <climits>
#include "usecase.cpp"

using namespace std;

void test_minqueue()
// Testing empty minqueue (int, string, long, floats)
// Testing copy constructor (int, string, long, floats)
// Testing constructors with big data
{

    int *int_data = new int[10];
    for (int i = 0; i < 10; i++)
    {
        int_data[i] = 10 - i;
    }

    try
    {
        // int
        MinQueue<int> empty;
        string mq_str = empty.to_string();

        if (mq_str != "")
        {
            cout << "Incorrect result from empty constructor. Expected an empty string but got : " << mq_str << endl;
        }

        // int: copy constructor
        MinQueue<int> mq(int_data, 10);
        mq_str = mq.to_string();

        if (mq_str != "1 2 4 3 6 5 8 10 7 9")
        {
            cout << "Incorrect result from empty constructor. Expected 1 2 4 3 6 5 8 10 7 9 but got : " << mq_str << endl;
        }


        // string
        MinQueue<string> string_empty;

        if (string_empty.to_string() != "")
        {
            cout << "Incorrect result from string_empty constructor. Expected an empty string but got : " << string_empty.to_string() << endl;
        }

        // string: copy constructor
        string test_string[] = {"hello", "world"};
        MinQueue<string> string_mq(test_string, 2);

        if (string_mq.to_string() != "hello world")
        {
            cout << "Incorrect result from string_empty constructor. Expected 'hello world' but got : " << string_mq.to_string() << endl;
        }

                // int: copy constructor
        //MinQueue<int> mq(int_data, 10);
        mq_str = mq.to_string();

        if (mq_str != "1 2 4 3 6 5 8 10 7 9")
        {
            cout << "Incorrect result from empty constructor. Expected 1 2 4 3 6 5 8 10 7 9 but got : " << mq_str << endl;
        }


        // long
        MinQueue<long> long_empty;

        if (long_empty.to_string() != "")
        {
            cout << "Incorrect result from long_empty constructor. Expected an empty string but got : " << long_empty.to_string() << endl;
        }

        // long: copy constructor
        long test_long[] = {10000000000, 20000000000, 30000000000};
        MinQueue<long> long_mq(test_long, 3);

        if (long_mq.to_string() != "10000000000 20000000000 30000000000")
        {
            cout << "Incorrect result from long_mq constructor. Expected '10000000000 20000000000 30000000000' but got : " << long_mq.to_string() << endl;
        }

        // float
        MinQueue<float> float_empty;

        if (long_empty.to_string() != "")
        {
            cout << "Incorrect result from float_empty constructor. Expected an empty string but got : " << float_empty.to_string() << endl;
        }

        // float: copy constructor
        float test_float[] = {1.1, 2.2, 3.3};
        MinQueue<float> float_mq(test_float, 3);

        if (float_mq.to_string() != "1.1 2.2 3.3")
        {
            cout << "Incorrect result from float_mq constructor. Expected '1.1 2.2 3.3' but got : " << float_mq.to_string() << endl;
        }

    }
    catch (exception &e)
    {
        cerr << "Error creating the priority queue : " << e.what() << endl;
    }

    delete[] int_data;
}

void test_insert()
{

    int *int_data = new int[10];
    for (int i = 0; i < 10; i++)
    {
        int_data[i] = 10 - i;
    }

    int *neg_int_data = new int[10];
    for (int i = 0; i < 10; i++)
    {
        neg_int_data[i] =  -i;
    }

    try
    {

        MinQueue<int> empty;
        empty.insert(0);
        string mq_str = empty.to_string();

        if (mq_str != "0")
        {
            cout << "Incorrect insert result. Epected 0 but got : " << mq_str << endl;
        }

        MinQueue<int> mq(int_data, 10);
        mq.insert(25);
        mq.insert(0);
        mq_str = mq.to_string();

        if (mq_str != "0 2 1 3 6 4 8 10 7 9 25 5")
        {
            cout << "Incorrect insert result. Expected 0 2 1 3 6 4 8 10 7 9 25 5 but got : " << mq_str << endl;
        }

        // Negatives
        MinQueue<int> neg_mq(neg_int_data, 10);
        neg_mq.insert(-5);
        neg_mq.insert(-7);
        string neg_mq_str = neg_mq.to_string();
        if(neg_mq_str != "-9 -8 -7 -7 -5 -6 -2 0 -3 -1 -4 -5")
        {
            cout << "Incorrect insert result for negatives. Expected -9 -8 -7 -7 -5 -6 -2 0 -3 -1 -4 -5 but got : " << neg_mq_str << endl;
        }

        // Strings
        MinQueue<string> str_mq;
        str_mq.insert("apple");
        str_mq.insert("banana");
        str_mq.insert("orange");
        string str_mq_str = str_mq.to_string();
        if(str_mq_str != "apple banana orange")
        {
            cout << "Incorrect insert result for negatives. Expected apple banana orange but got : " << str_mq_str << endl;
        }

        // Extracting and then inserting
        mq.extract_min();
        mq.insert(0);
        if (mq.to_string() != "0 2 1 3 6 4 8 10 7 9 25 5")
        {
            cout << "Incorrect insert result. Expected 0 2 1 3 6 4 8 10 7 9 25 5 but got : " << mq.to_string() << endl;
        }

        mq.extract_min();
        mq.extract_min();
        mq.extract_min();
        mq.extract_min();
        
        mq.insert(2);

        if (mq.to_string() != "2 4 5 6 9 25 8 10 7")
        {
            cout << "Incorrect insert result. Expected 2 4 5 6 9 25 8 10 7 but got : " << mq.to_string() << endl;
        }

        // Inserting repeating values
        mq.insert(2);
        mq.insert(4);
        mq.insert(5);

        if (mq.to_string() != "2 2 5 6 4 5 8 10 7 9 4 25")
        {
            cout << "Incorrect insert result. Expected 2 2 5 6 4 5 8 10 7 9 4 25 but got : " << mq.to_string() << endl;
        }

    }
    catch (exception &e)
    {
        cerr << "Error inserting into the priority queue : " << e.what() << endl;
    }

    delete[] int_data;
}

void test_min()
{

    int *int_data = new int[10];
    for (int i = 0; i < 10; i++)
    {
        int_data[i] = 10 - i;
    }

    try
    {

        MinQueue<int> empty;
        int min = empty.min();
        if (min != 0)
        {
            cout << "Incorrect min result. Expect 0 but got : " << min << endl;
        }

        MinQueue<int> mq(int_data, 10);
        min = mq.min();
        if (min != 1)
        {
            cout << "Incorrect min result. Expect 0 but got : " << min << endl;
        }
        // Test case: Check min after removing elements
        mq.extract_min();
        min = mq.min();
        if (min != 2)
        {
            cout << "Incorrect min result after extract_min. Expect 2 but got : " << min << endl;
        }

        mq.extract_min();
        min = mq.min();
        if (min != 3)
        {
            cout << "Incorrect min result after extract_min. Expect 3 but got : " << min << endl;
        }

        // Test case: Check min after adding elements
        mq.insert(10);
        min = mq.min();
        if (min != 3)
        {
            cout << "Incorrect min result after insert. Expect 3 but got : " << min << endl;
        }

        mq.insert(11);
        min = mq.min();
        if (min != 3)
        {
            cout << "Incorrect min result after insert. Expect 3 but got : " << min << endl;
        }

        // Test case: Check min with negative numbers
        int *int_data2 = new int[10];
        for(int i = 0; i<10; i++){
            int_data2[i] = 0 - i;
        }

        MinQueue<int> mq2(int_data2, 10);
        min = mq2.min();
        if (min != -9)
        {
            cout << "Incorrect min result. Expect -9 but got : " << min << endl;
        }
        delete[] int_data2;    
        // Test case: Single Element in heap
        MinQueue<int> single;
        single.insert(5);
        min = single.min();
        if (min != 5)
        {
            cout << "Incorrect min result for single element queue. Expect 5 but got : " << min << endl;
        }

        //Test case: Duplicate Elements
        int *int_data3 = new int[10];
        for (int i = 0; i < 10; i++)
        {
            int_data3[i] = 5;
        }

        MinQueue<int> mq3(int_data3, 10);
        min = mq3.min();
        if (min != 5)
        {
            cout << "Incorrect min result for queue with duplicate elements. Expect 5 but got : " << min << endl;
        }
        delete[] int_data3;

        //Test Case: LARGE NUMBERS
        MinQueue<int> large;
        large.insert(INT_MAX);
        large.insert(INT_MAX - 1);
        min = large.min();
        if (min != INT_MAX - 1)
        {
            cout << "Incorrect min result for queue with large numbers. Expect " << INT_MAX - 1 << " but got : " << min << endl;
        }

        }
        catch (exception &e)
        {
            cerr << "Error in determining min of the priority queue : " << e.what() << endl;
        }

        delete[] int_data;

        // Strings
        MinQueue<string> str_mq;
        str_mq.insert("apple");
        str_mq.insert("banana");
        str_mq.insert("orange");
        string str_min = str_mq.min();
        string str_min_str = str_min;
        if(str_min_str != "apple")
        {
            cout << "Incorrect insert result for strings. Expected apple but got : " << str_min_str << endl;
        }

        // Empty Float
        MinQueue<float> empty_float;
        float min_float = empty_float.min();
        if (min_float != 0.0)
        {
            cout << "Incorrect min result. Expect 0.0 but got : " << min_float << endl;
        }

        // Empty String
        MinQueue<string> empty_string;
        string min_string = empty_string.min();
        if (min_string != "")
        {
            cout << "Incorrect min result. Expect 0.0 but got : " << min_string << endl;
        }
}

void test_extract_min()
{

    int *int_data = new int[10];
    for (int i = 0; i < 10; i++)
    {
        int_data[i] = 10 - i;
    }

    try
    {

        MinQueue<int> empty;
        int min = empty.extract_min();
        string mq_str = empty.to_string();

        if (min != 0 || mq_str != "")
        {
            cout << "Incorrect extract min result. Expected 0 and an empty queue but got : " << min << " and a queue of : " << mq_str << endl;
        }

        MinQueue<int> mq(int_data, 10);
        min = mq.extract_min();
        mq_str = mq.to_string();

        if (min != 1 || mq_str != "2 3 4 7 6 5 8 10 9")
        {
            cout << "Incorrect extract min result. Expected 0 and the queue 2 3 4 7 6 5 8 10 9 but got : " << min << " and a queue of : " << mq_str << endl;
        }

        //-----
        //Test Case: Duplicate Elements
        int *int_data2 = new int[10];
        for (int i = 0; i < 10; i++)
        {
            int_data2[i] = 5;
        }

        MinQueue<int> mq2(int_data2, 10);
        int min2 = mq2.extract_min();
        string mq_str2 = mq2.to_string();

        if (min2 != 5 || mq_str2 != "5 5 5 5 5 5 5 5 5")
        {
            cout << "Incorrect extract min result for queue with duplicate elements. Expect 5 and the queue 5 5 5 5 5 5 5 5 5 but got : " << min2 << " and a queue of : " << mq_str2 << endl;
        }

        delete[] int_data2;

        //Test Case: Large Numbers
        MinQueue<int> large;
        large.insert(INT_MAX);
        large.insert(INT_MAX - 1);
        int min_large = large.extract_min();
        string mq_str_large = large.to_string();

        if (min_large != INT_MAX - 1 || mq_str_large != to_string(INT_MAX))
        {
            cout << "Incorrect extract min result for queue with large numbers. Expect " << INT_MAX - 1 << " and the queue " << INT_MAX << " but got : " << min_large << " and a queue of : " << mq_str_large << endl;
        }

        //Test Case: Negative Numbers //Possible Issue Here
        int *int_data3 = new int[10];
        for (int i = 0; i < 10; i++)
        {
            int_data3[i] = -i;
        }
        MinQueue<int> mq3(int_data3, 10);
        int min3 = mq3.extract_min();
        string mq_str3 = mq3.to_string();
        
        if (min3 != -9 || mq_str3 != "-8 -7 -6 -3 -4 -5 -2 0 -1")
        {
            cout << "Incorrect extract min result for queue with negative numbers. Expect -9 and the queue -8 -7 -6 -3 -4 -5 -2 0 -1 but got : " << min3 << " and a queue of : " << mq_str3 << endl;
        }

        delete[] int_data3;

        //Test Case: Both Negative and Positive //Possible Issue Here
        int *int_data4 = new int[10];
        for (int i = 0; i < 5; i++)
        {
            int_data4[i] = i;
        }
        for (int i = 5; i < 10; i++)
        {
            int_data4[i] = -i;
        }

        MinQueue<int> mq4(int_data4, 10);
        int min4 = mq4.extract_min();
        string mq_str4 = mq4.to_string();

        if (min4 != -9 || mq_str4 != "-8 -7 -6 0 1 -5 2 4 3")
        {
            cout << "Incorrect extract min result for queue with mixed positive and negative numbers. Expect -9 and the queue -8 -7 -6 0 1 -5 2 4 3 but got : " << min4 << " and a queue of : " << mq_str4 << endl;
        }

        delete[] int_data4;

        // Strings
        MinQueue<string> str_mq;
        str_mq.insert("apple");
        str_mq.insert("banana");
        str_mq.insert("orange");
        string str_min = str_mq.extract_min();
        string str_mq_str = str_mq.to_string();
        if (str_min != "apple" || str_mq_str != "banana orange") {
            cout << "Incorrect extract min result. Expected apple and banana orange but got : " << str_min << " and a queue of : " << str_mq_str << endl;
        }

        // Empty String
        MinQueue<string> empty_string;
        string min_string = empty_string.extract_min();
        string empty_string_mq_str = empty_string.to_string();
        if (min_string != "" || empty_string_mq_str != "") {
            cout << "Incorrect extract min result. Expected an empty queue but got : " << min_string << " and a queue of : " << empty_string_mq_str << endl;
        }
    }
    catch (exception &e)
    {
        cerr << "Error in determining min of the priority queue : " << e.what() << endl;
    }

    delete[] int_data;
}

void test_decrease_key()
{

    int *int_data = new int[10];
    for (int i = 0; i < 10; i++)
    {
        int_data[i] = 10 - i;
    }

    try
    {

        MinQueue<int> empty;
        empty.decrease_key(0, 0);
        string mq_str = empty.to_string();

        if (mq_str != "")
        {
            cout << "Incorrect decrease key result. Expected empty queue but got : " << mq_str << endl;
        }

        MinQueue<int> mq(int_data, 10);
        mq.decrease_key(0, -6);
        mq.decrease_key(9, -1);
        mq_str = mq.to_string();

        if (mq_str != "-6 -1 4 3 2 5 8 10 7 6")
        {
            cout << "Incorrect decrease key result. Expected empty queue but got : " << mq_str << endl;
        }

        // Strings
        MinQueue<string> str_mq;
        str_mq.insert("apple");
        str_mq.insert("banana");
        str_mq.insert("orange");
        str_mq.decrease_key(0, "a");
        string str_mq_str = str_mq.to_string();
        if (str_mq_str != "a banana orange") {
            cout << "Incorrect decrease key result. Expected a banana orange but got : " << str_mq_str << endl;
        }

    }
    catch (exception &e)
    {
        cerr << "Error in decreasing key : " << e.what() << endl;
    }

    delete[] int_data;
}

void test_heapify()
{

    int *empty_data = new int[0];

    int *int_data = new int[10];
    for (int i = 0; i < 10; i++)
    {
        int_data[i] = 10 - i;
    }

    try
    {

        MinQueue<int> empty;
        empty.min_heapify(1);
        string mq_str = empty.to_string();

        if (mq_str != "")
        {
            cout << "Incorrect heapify result. Expected empty string but got : " << mq_str << endl;
        }

        MinQueue<int> mq(int_data, 10);
        string o_mq_str = mq.to_string();
        mq.set(1, 11);
        mq.min_heapify(1);

        mq_str = mq.to_string();

        if (mq_str != "1 3 4 7 6 5 8 10 11 9")
        {
            cout << "Incorrect heapify result in heapifying index 1 in the minqueue " << o_mq_str << " after setting to 11. Expected 1 3 4 7 6 5 8 10 11 9 but got : " << mq_str << endl;
        }

        // Strings
        MinQueue<string> str_mq;
        str_mq.insert("apple");
        str_mq.insert("banana");
        str_mq.insert("orange");
        str_mq.set(0, "z");
        str_mq.min_heapify(0);
        string str_mq_str = str_mq.to_string();
        if (str_mq_str != "banana z orange") {
            cout << "Incorrect decrease key result. Expected banana z orange but got : " << str_mq_str << endl;
        }

    }
    catch (exception &e)
    {
        cerr << "Error in heapify : " << e.what() << endl;
    }

    delete[] empty_data;
    delete[] int_data;
}

void test_build_min_heap()
{

    int *int_data = new int[10];
    for (int i = 0; i < 10; i++)
    {
        int_data[i] = 10 - i;
    }

    try
    {

        MinQueue<int> mq;
        mq.allocate(10);
        for (int i = 0; i < 10; i++)
        {
            mq.set(i, int_data[i]);
        }

        string o_mq_str = mq.to_string();

        mq.build_heap();
        string mq_str = mq.to_string();

        if (mq_str != "1 2 4 3 6 5 8 10 7 9")
        {
            cout << "Incorrect build_heap result from " << o_mq_str << ". Expected 1 2 4 3 6 5 8 10 7 9 but got : " << mq_str << endl;
        }

        // Strings
        MinQueue<string> str_mq;
        str_mq.set(0, "banana");
        str_mq.set(1, "apple");
        str_mq.set(2, "orange");

        string str_mq_str = str_mq.to_string();
        str_mq.build_heap();
        string str_mq_str2 = str_mq.to_string();
        if(str_mq_str2 != "apple banana orange") {
            cout << "Incorrect build_heap result from " << str_mq_str << ". Expected apple banana orange but got : " << str_mq_str2 << endl;
        }
    }
    catch (exception &e)
    {
        cerr << "Error in building min heap : " << e.what() << endl;
    }

    delete[] int_data;
}

void test_heapsort()
{

    int *empty_data = new int[0];

    int *int_data = new int[10];
    for (int i = 0; i < 10; i++)
    {
        int_data[i] = 10 - i;
    }

    try
    {

        MinQueue<int> empty;
        empty.sort(empty_data);

        MinQueue<int> heap(int_data, 10);
        heap.sort(int_data);

        string sorted_str = to_string(int_data[0]);

        for (int i = 1; i < 10; i++)
        {
            sorted_str += (" " + to_string(int_data[i]));
        }

        if (sorted_str != "1 2 3 4 5 6 7 8 9 10")
        {
            cout << "Incorrect heapsort result. Expected 1 2 3 4 5 6 7 8 9 10 but got : " << sorted_str << endl;
        }

        // Strings
        MinQueue<string> str_mq;
        string ss[3] = {"banana", "apple", "orange"};
        MinQueue<string> str_mq2(ss, 3);
        str_mq2.sort(ss);
        string str_mq_str = ss[0] + " " + ss[1] + " " + ss[2];
        if (str_mq_str != "apple banana orange") {
            cout << "Incorrect decrease key result. Expected apple banana orange but got : " << str_mq_str << endl;
        }

    }
    catch (exception &e)
    {
        cerr << "Error in sorting : " << e.what() << endl;
    }

    delete[] empty_data;
    delete[] int_data;
}

void test_sliding_window()
{

    int *empty = new int[0];
    int nums[8] = {1, 3, -1, -3, 5, 3, 6, 7};

    try
    {

        string window_result = sliding_window(empty, 0, 0);

        if (window_result != "")
        {
            cout << "Incorrect sliding window result. Expected and empty string but got : " << window_result << endl;
        }

        window_result = sliding_window(nums, 8, 3);

        if (window_result != "-1 -3 -3 -3 3 3")
        {
            cout << "Incorrect sliding window result. Expected -1 -3 -3 -3 3 3 but got : " << window_result << endl;
        }

        window_result = sliding_window(nums, 1, 1);

        if (window_result != "1")
        {
            cout << "Incorrect sliding window result. Expected 1 but got : " << window_result << endl;
        }

        // Test case 1: Test with a larger window size than the array size
        int nums1[3] = {1, 2, 3};
        string window_result2 = sliding_window(nums1, 3, 5);
        if (window_result2 != "")
        {
            cout << "Incorrect sliding window result. Expected "" but got : " << window_result2 << endl;
        }

        // Test case 2: Test with negative numbers
        int nums2[5] = {-1, -2, -3, -4, -5};
        window_result = sliding_window(nums2, 5, 3);
        if (window_result != "-3 -4 -5")
        {
            cout << "Incorrect sliding window result. Expected -3 -4 -5 but got : " << window_result << endl;
        }

        // Test case 3: Test with all elements being the same
        int nums3[5] = {5, 5, 5, 5, 5};
        window_result = sliding_window(nums3, 5, 3);
        if (window_result != "5 5 5")
        {
            cout << "Incorrect sliding window result. Expected 5 5 5 but got : " << window_result << endl;
        }

        // Test case 4: Test with window size of 0
        int nums4[5] = {1, 2, 3, 4, 5};
        window_result = sliding_window(nums4, 5, 0);
        if (window_result != "")
        {
            cout << "Incorrect sliding window result. Expected an empty string but got : " << window_result << endl;
        }

        // Test case 5: Test with window size of 2
        int nums5[6] = {1, 2, 3, 4, 5, 6};
        window_result = sliding_window(nums5, 6, 2);
        if (window_result != "1 2 3 4 5")
        {
            cout << "Incorrect sliding window result. Expected 1 2 3 4 5 but got : " << window_result << endl;
        }

    }
    catch (exception &e)
    {
        cerr << "Error in generating sliding window result : " << e.what() << endl;
    }

    delete[] empty;
}

void time_test()
{
    MinQueue<int> mq;
    // TO-DO: generate large minqueue
    int size = -1; // TO-DO: set size of large minqueue
    int total = 0;

    int val = rand() % 100000;
    auto begin = std::chrono::high_resolution_clock::now();
    mq.insert(val);
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cout << "insert time test took " << elapsed.count() << " nanoseconds" << endl;
    total += elapsed.count();

    begin = std::chrono::high_resolution_clock::now();
    int _ = mq.min();
    end = std::chrono::high_resolution_clock::now();
    elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cout << "min time test took " << elapsed.count() << " nanoseconds" << endl;
    total += elapsed.count();

    begin = std::chrono::high_resolution_clock::now();
    _ = mq.extract_min();
    end = std::chrono::high_resolution_clock::now();
    elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cout << "extract min time test took " << elapsed.count() << " nanoseconds" << endl;
    total += elapsed.count();

    int last_index = size - 1;  // indexing starts at 0
    int new_val = mq.min() - 1; // ensure we're decreasing the key
    begin = std::chrono::high_resolution_clock::now();
    mq.decrease_key(last_index, new_val);
    end = std::chrono::high_resolution_clock::now();
    elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cout << "decrease key time test took " << elapsed.count() << " nanoseconds" << endl;
    total += elapsed.count();
    cout << "Total time: " << total << endl;
}

int main()
{

    test_minqueue();
    test_insert();
    test_min();
    test_extract_min();
    test_decrease_key();
    test_heapify();
    test_build_min_heap();
    test_heapsort();

    test_sliding_window();

    time_test();

    cout << "Custom Testing completed" << endl;

    return 0;
}

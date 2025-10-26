// *******************************************
//  test_bst_example.cpp
//  CS 271 BST Project: Example Test File
// *******************************************

#include <stdlib.h>
#include <iostream>
#include <math.h>
#include "BST.h"
using namespace std;

void test_empty()
{
    try
    {
        BST<string, int> bst;
        if (!bst.empty())
        {
            cout << "Incorrect empty result." << endl;
        }
        bst.insert("one", 1);
        if (bst.empty())
        {
            cout << "Incorrect empty result." << endl;
        }
    }
    catch (exception &e)
    {
        cerr << "Error in determining if BST is empty : " << e.what() << endl;
    }
}

void test_insert()
{
    try
    {
        BST<string, int> bst;
        bst.insert("one", 1);
        string bst_str = bst.to_string();
        if (bst_str != "1")
        {
            cout << "Incorrect result of inserting (\"one\", 1). Expected 1 but got : " << bst_str << endl;
        }
        for (int i = 2; i <= 10; i++)
        {
            bst.insert("some data", i);
        }
        bst_str = bst.to_string();
        if (bst_str != "1 2 3 4 5 6 7 8 9 10")
        {
            cout << "Incorrect result of inserting keys 1-10 in order. Expected 1 2 3 4 5 6 7 8 9 10 but got : " << bst_str << endl;
        }
        int vals[10] = {5, 2, 7, 1, 3, 4, 6, 9, 8, 10};
        BST<string, int> balanced_bst;
        for (int i = 0; i < 10; i++)
        {
            balanced_bst.insert("some data", vals[i]);
        }
        bst_str = balanced_bst.to_string();
        if (bst_str != "5 2 7 1 3 6 9 4 8 10")
        {
            cout << "Incorrect result of inserting keys {5, 2, 7, 1, 3, 4, 6, 9, 8, 10}. Expected 5 2 7 1 3 6 9 4 8 10 but got : " << bst_str << endl;
        }
    }
    catch (exception &e)
    {
        cerr << "Error inserting into bst : " << e.what() << endl;
    }
}

void test_get()
{
    try
    {
        BST<string, int> bst;
        string val = bst.get(0);
        if (val != "")
        {
            cout << "Incorrect get result from empty bst. Expected 0 but got " << val << endl;
        }
        bst.insert("one", 1);
        val = bst.get(1);
        if (val != "one")
        {
            cout << "Incorrect get result. Expected \"one\" but got : " << val << endl;
        }
    }
    catch (exception &e)
    {
        cerr << "Error in getting data from bst : " << e.what() << endl;
    }
}

void test_remove()
{
    try
    {
        int vals[10] = {5, 2, 7, 1, 3, 4, 6, 9, 8, 10};
        BST<string, int> balanced_bst;
        for (int i = 0; i < 10; i++)
        {
            balanced_bst.insert("some data", vals[i]);
        }
        balanced_bst.remove(7);
        string bst_str = balanced_bst.to_string();
        if (bst_str != "5 2 8 1 3 6 9 4 10")
        {
            cout << "Incorrect result of removing 7. Expected 5 2 8 1 3 6 9 4 10 but got : " << bst_str << endl;
        }
    }
    catch (exception &e)
    {
        cerr << "Error in removing node from bst : " << e.what() << endl;
    }
}

void test_max_data()
{
    try
    {
        int vals[10] = {5, 2, 7, 1, 3, 4, 6, 9, 8, 10};
        BST<string, int> balanced_bst;
        for (int i = 0; i < 10; i++)
        {
            balanced_bst.insert(to_string(vals[i]) + " data", vals[i]);
        }
        string max_str = balanced_bst.max_data();
        if (max_str != "10 data")
        {
            cout << "Incorrect result of max_data. Expected \"10 data\" but got : " << max_str << endl;
        }
    }
    catch (exception &e)
    {
        cerr << "Error in determining data of max node in bst : " << e.what() << endl;
    }
}

void test_max_key()
{
    try
    {
        int vals[10] = {5, 2, 7, 1, 3, 4, 6, 9, 8, 10};
        BST<string, int> balanced_bst;
        for (int i = 0; i < 10; i++)
        {
            balanced_bst.insert(to_string(vals[i]) + " data", vals[i]);
        }
        int max_k = balanced_bst.max_key();
        if (max_k != 10)
        {
            cout << "Incorrect result of max_key. Expected 10 but got : " << max_k << endl;
        }
    }
    catch (exception &e)
    {
        cerr << "Error in determining key of max node in bst : " << e.what() << endl;
    }
}

void test_min_data()
{
    try
    {
        int vals[10] = {5, 2, 7, 1, 3, 4, 6, 9, 8, 10};
        BST<string, int> balanced_bst;
        for (int i = 0; i < 10; i++)
        {
            balanced_bst.insert(to_string(vals[i]) + " data", vals[i]);
        }
        string min_str = balanced_bst.min_data();
        if (min_str != "1 data")
        {
            cout << "Incorrect result of min_data. Expected \"1 data\" but got : " << min_str << endl;
        }
    }
    catch (exception &e)
    {
        cerr << "Error in determining data of min node in bst : " << e.what() << endl;
    }
}

void test_min_key()
{
    try
    {
        int vals[10] = {5, 2, 7, 1, 3, 4, 6, 9, 8, 10};
        BST<string, int> balanced_bst;
        for (int i = 0; i < 10; i++)
        {
            balanced_bst.insert(to_string(vals[i]) + " data", vals[i]);
        }
        int min_k = balanced_bst.min_key();
        if (min_k != 1)
        {
            cout << "Incorrect result of min_key. Expected 10 but got : " << min_k << endl;
        }
    }
    catch (exception &e)
    {
        cerr << "Error in determining key of min node in bst : " << e.what() << endl;
    }
}

void test_successor()
{
    try
    {
        int vals[10] = {5, 2, 7, 1, 3, 4, 6, 9, 8, 10};
        BST<string, int> balanced_bst;
        for (int i = 0; i < 10; i++)
        {
            balanced_bst.insert(to_string(vals[i]) + " data", vals[i]);
        }
        int succ = balanced_bst.successor(4);
        if (succ != 5)
        {
            cout << "Incorrect result of successor of 4. Expected 5 but got : " << succ << endl;
        }
        succ = balanced_bst.successor(7);
        if (succ != 8)
        {
            cout << "Incorrect result of successor of 7. Expected 8 but got : " << succ << endl;
        }
        succ = balanced_bst.successor(10);
        if (succ != 0)
        {
            cout << "Incorrect result of successor of 10. Expected 0 but got : " << succ << endl;
        }
    }
    catch (exception &e)
    {
        cerr << "Error in determining successor in bst : " << e.what() << endl;
    }
}

void test_in_order()
{
    try
    {
        BST<string, int> bst;
        for (int i = 1; i <= 10; i++)
        {
            bst.insert("some data", i);
        }
        string bst_str = bst.in_order();
        if (bst_str != "1 2 3 4 5 6 7 8 9 10")
        {
            cout << "Incorrect in_order result after inserting keys 1-10 in order. Expected 1 2 3 4 5 6 7 8 9 10 but got : " << bst_str << endl;
        }
        int vals[10] = {5, 2, 7, 1, 3, 4, 6, 9, 8, 10};
        BST<string, int> balanced_bst;
        for (int i = 0; i < 10; i++)
        {
            balanced_bst.insert("some data", vals[i]);
        }
        bst_str = balanced_bst.in_order();
        if (bst_str != "1 2 3 4 5 6 7 8 9 10")
        {
            cout << "Incorrect in_order result after inserting keys {5, 2, 7, 1, 3, 4, 6, 9, 8, 10}. Expected 1 2 3 4 5 6 7 8 9 10 but got : " << bst_str << endl;
        }
    }
    catch (exception &e)
    {
        cerr << "Error getting keys in_order from bst : " << e.what() << endl;
    }
}

void test_trim()
{
    try
    {
        BST<string, int> bst;
        int vals[3] = {1, 0, 2};
        for (int i = 0; i < 3; i++)
        {
            bst.insert(to_string(vals[i]) + " data", vals[i]);
        }
        bst.trim(1, 2);
        string bst_str = bst.to_string();
        if (bst_str != "1 2")
        {
            cout << "Incorrect tree after trimming 1 0 2 with low=1, high=2. Expected 1 2 but got : " << bst_str << endl;
        }
        BST<string, int> bst2;
        int vals2[5] = {3, 0, 4, 2, 1};
        for (int i = 0; i < 5; i++)
        {
            bst2.insert(to_string(vals2[i]) + " data", vals2[i]);
        }
        bst2.trim(1, 3);
        bst_str = bst2.to_string();
        if (bst_str != "3 2 1")
        {
            cout << "Incorrect tree after trimming 3 0 4 2 1 with low=1, high=3. Expected 3 2 1 but got : " << bst_str << endl;
        }
    }
    catch (exception &e)
    {
        cerr << "Error in trimming the bst : " << e.what() << endl;
    }
}

// void test_binhex()
// {
//     try
//     {
//         BST<string, string> *bst1 = create_bst<string, string>("binhex.txt");
//         string bin1 = "111010100101";
//         string expected_hex1 = "EA5";

//         string hex1 = convert<string, string>(bst1, bin1);
//         delete bst1;

//         if (hex1 != expected_hex1)
//         {
//             cout << "Incorrect result converting " << bin1 << " to hex. Expected : " << expected_hex1 << ", but got : " << hex1 << endl;
//         }
//     }
//     catch (exception &e)
//     {
//         cerr << "Error converting binary to hex : " << e.what() << endl;
//     }

//     try
//     {
//         BST<string, string> *bst2 = create_bst<string, string>("binhex.txt");
//         string bin2 = "110101";
//         string expected_hex2 = "35";

//         string hex2 = convert<string, string>(bst2, bin2);
//         delete bst2;

//         if (hex2 != expected_hex2)
//         {
//             cout << "Incorrect result converting " << bin2 << " to hex. Expected : " << expected_hex2 << ", but got : " << hex2 << endl;
//         }
//     }
//     catch (exception &e)
//     {
//         cerr << "Error converting binary to hex : " << e.what() << endl;
//     }
// }
void test_insert_char_keys()
{
    try
    {
        BST<string, char> bst;
        bst.insert("apple", 'a');
        bst.insert("cat", 'c');
        bst.insert("banana", 'b');
        
        string bst_str = bst.to_string();
        if (bst_str != "a c b")
        {
            cout << "Incorrect result of inserting char keys. Expected 'a b c' but got : " << bst_str << endl;
        }
    }
    catch (exception &e)
    {
        cerr << "Error inserting char keys into bst : " << e.what() << endl;
    }
}

void test_insert_double_keys()
{
    try
    {
        BST<int, double> bst;
        bst.insert(100, 1.5);
        bst.insert(200, 3.7);
        bst.insert(150, 2.1);
        
        string bst_str = bst.to_string();
        if (bst_str != "1.5 3.7 2.1")
        {
            cout << "Incorrect result of inserting double keys. Expected '1.5 2.1 3.7' but got : " << bst_str << endl;
        }
    }
    catch (exception &e)
    {
        cerr << "Error inserting double keys into bst : " << e.what() << endl;
    }
}

// Test edge case: removing from single-node tree
void test_remove_single_node()
{
    try
    {
        BST<string, int> bst;
        bst.insert("only", 5);
        bst.remove(5);
        
        if (!bst.empty())
        {
            cout << "Incorrect result: BST should be empty after removing the only node" << endl;
        }
    }
    catch (exception &e)
    {
        cerr << "Error removing single node from bst : " << e.what() << endl;
    }
}

// Test case: removing node with two children
void test_remove_two_children()
{
    try
    {
        int vals[7] = {10, 5, 15, 3, 7, 12, 20};
        BST<string, int> bst;
        for (int i = 0; i < 7; i++)
        {
            bst.insert("data", vals[i]);
        }
        
        bst.remove(10);  // Remove root with two children
        //check level-order 
        string bst_str = bst.to_string();
        string expected_str = "12 5 15 3 7 20";
        if (bst_str != expected_str)
        {
            cout << "Incorrect result of removing node with two children. Expected " << expected_str << " but got : " << bst_str << endl;
        }
        //check the in-order
        string in_order_str = bst.in_order();
        string expected_in_order = "3 5 7 12 15 20";
        if (in_order_str != expected_in_order)
        {
             cout << "Incorrect in-order result after removing 10. Expected " << expected_in_order << " but got : " << in_order_str << endl;
        }
    }
    catch (exception &e)
    {
        cerr << "Error removing node with two children : " << e.what() << endl;
    }
}

// Test edge case: removing non-existent key
void test_remove_nonexistent()
{
    try
    {
        BST<string, int> bst;
        bst.insert("one", 1);
        bst.insert("two", 2);
        
        bst.remove(99);  // Key doesn't exist
        
        // Tree should remain unchanged
        string bst_str = bst.to_string();
        if (bst_str != "1 2")
        {
            cout << "Tree should be unchanged after removing non-existent key. Expected '1 2' but got : " << bst_str << endl;
        }
    }
    catch (exception &e)
    {
        cerr << "Error removing non-existent key : " << e.what() << endl;
    }
}

// Test get with non-existent key
void test_get_nonexistent()
{
    try
    {
        BST<string, int> bst;
        bst.insert("exists", 10);
        
        string result = bst.get(999);  // Key doesn't exist
        if (result != "")
        {
            cout << "Expected empty string for non-existent key, but got : " << result << endl;
        }
    }
    catch (exception &e)
    {
        cerr << "Error getting non-existent key : " << e.what() << endl;
    }
}

// Test max/min on empty tree
void test_max_min_empty()
{
    try
    {
        BST<string, int> bst;
        
        // These should handle empty tree gracefully (return default values)
        string max_d = bst.max_data();
        int max_k = bst.max_key();
        string min_d = bst.min_data();
        int min_k = bst.min_key();
        
        if (max_d != "" || max_k != 0 || min_d != "" || min_k != 0)
        {
            cout << "Empty tree should return default values for max/min operations" << endl;
        }
    }
    catch (exception &e)
    {
        cerr << "Error testing max/min on empty tree : " << e.what() << endl;
    }
}

// Test successor edge cases
void test_successor_edge_cases()
{
    try
    {
        int vals[5] = {5, 3, 7, 2, 4};
        BST<string, int> bst;
        for (int i = 0; i < 5; i++)
        {
            bst.insert("data", vals[i]);
        }
        
        // Test successor of max key
        int succ_max = bst.successor(7);
        if (succ_max != 0)
        {
            cout << "Successor of max key should be 0 (default int value), but got : " << succ_max << endl;
        }
        
        // Test successor of non-existent key
        int succ_none = bst.successor(100);
        if (succ_none != 0)
        {
            cout << "Successor of non-existent key should be 0 (default int value), but got : " << succ_none << endl;
        }
    }
    catch (exception &e)
    {
        cerr << "Error testing successor edge cases : " << e.what() << endl;
    }
}

// Test trim edge cases
void test_trim_all_outside_range()
{
    try
    {
        BST<string, int> bst;
        int vals[5] = {5, 3, 7, 2, 8};
        for (int i = 0; i < 5; i++)
        {
            bst.insert("data", vals[i]);
        }
        
        bst.trim(10, 20);  // All nodes outside range
        
        if (!bst.empty())
        {
            cout << "Tree should be empty after trimming all nodes outside range" << endl;
        }
    }
    catch (exception &e)
    {
        cerr << "Error trimming all nodes outside range : " << e.what() << endl;
    }
}

void test_trim_all_inside_range()
{
    try
    {
        BST<string, int> bst;
        int vals[5] = {5, 3, 7, 2, 6};
        for (int i = 0; i < 5; i++)
        {
            bst.insert("data", vals[i]);
        }
        
        string before = bst.to_string();
        bst.trim(1, 10);  // All nodes inside range
        string after = bst.to_string();
        
        if (before != after)
        {
            cout << "Tree should be unchanged when all nodes are in range" << endl;
        }
    }
    catch (exception &e)
    {
        cerr << "Error trimming with all nodes in range : " << e.what() << endl;
    }
}

// Test in_order with single node
void test_in_order_single()
{
    try
    {
        BST<string, int> bst;
        bst.insert("single", 42);
        
        string result = bst.in_order();
        if (result != "42")
        {
            cout << "Single node in_order should be '42', but got : " << result << endl;
        }
    }
    catch (exception &e)
    {
        cerr << "Error testing in_order with single node : " << e.what() << endl;
    }
}

// Test to_string with empty tree
void test_to_string_empty()
{
    try
    {
        BST<string, int> bst;
        string result = bst.to_string();
        
        if (result != "")
        {
            cout << "Empty tree to_string should be empty, but got : " << result << endl;
        }
    }
    catch (exception &e)
    {
        cerr << "Error testing to_string with empty tree : " << e.what() << endl;
    }
}
int main()
{

    string file_name = "usecase.cpp";
    cout << endl
         << "Running tests for " << file_name << endl
         << endl;

    test_empty();
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

    test_insert_char_keys();
    test_insert_double_keys();
    test_remove_single_node();
    test_remove_two_children();
    test_remove_nonexistent();
    test_get_nonexistent();
    test_max_min_empty();
    test_successor_edge_cases();
    test_trim_all_outside_range();
    test_trim_all_inside_range();
    test_in_order_single();
    test_to_string_empty();


    cout << "Testing completed" << endl;

    return 0;
}

//========================================================
// CS 271
// Fall 2025
// BST.h
// This file contains the BST class declaration.  
//========================================================

#ifndef BST_H
#define BST_H

#include <string>
using namespace std;

template <typename D, typename K>
class BST {
private:
    struct Node {
        D data;
        K key;
        Node* left;
        Node* right;
        Node* parent;   
        Node(D d, K k);  
    };

    Node* root;

    void transplant(Node* u, Node* v); //remove helper
    Node* search(K key) const; 
    Node* treeMinimum(Node* x) const;
    Node* treeMaximum(Node* x) const;
public:
    BST();                   
    ~BST();                  
    bool empty() const;
    void insert(D d, K k);
    D get(K k) const;
    void remove(K k);
    D max_data() const;
    K max_key() const;
    D min_data() const;
    K min_key() const;
    K successor(K k) const;
    string to_string() const;
    string in_order() const;
    void trim(K low, K high);
    void clear(Node* node);
};

#include "BST.cpp" 

#endif

#include "BST.h"
#include <string>
#include <sstream>
#include <iostream>
#include <queue>        // for std::queue
#include <stack>        // for std::stack
#include <functional>   // for std::function
#include <stdexcept> 
using namespace std;

//=================================================
// Node (Constructor)
// Initializes a new Node for the BST.
// Parameters:
//  d: The data of type D to be stored in the node.
//  k: The key of type K to be stored in the node.
// Return Value:
//  (none)
//=================================================
template <typename D, typename K>
BST<D, K>::Node::Node(D d, K k) {
    data = d;
    key = k;
    left = nullptr;
    right = nullptr;
    parent = nullptr;
}

//=================================================
// transplant
// A private helper function that replaces one subtree
// as a child of its parent with another subtree.
// helper for the remove operation.
// Parameters:
//  u: A pointer to the node to be replaced.
//  v: A pointer to the node that will replace u.
// Return Value:
//  (none)
//=================================================
template <typename D, typename K>
void BST<D,K>::transplant(Node* u, Node* v) {
    if (u->parent == nullptr)
        root = v;
    else if (u == u->parent->left)
        u->parent->left = v;
    else
        u->parent->right = v;

    if (v != nullptr)
        v->parent = u->parent;
}

//=================================================
// search
// Searches the tree for a node with a given key.
// Parameters:
//  key: The key of type K to search for.
// Return Value:
//  A pointer to the Node containing the key, or
//  nullptr if the key is not found.
//=================================================
template <typename D, typename K>
typename BST<D, K>::Node* BST<D, K>::search(K key) const {
    Node* target = root; 
    while(target && target->key != key){
        if(target->key>key){
            target = target->left;
        } else { target = target->right;}
    }
    // If key not found, return nullptr
    if (target == nullptr) {
        return nullptr;
    }
    return target;
}

//=================================================
// treeMinimum
// Finds the node with the minimum key in a subtree.
// Parameters:
//  x: A pointer to the root of the subtree to search.
// Return Value:
//  A pointer to the Node with the minimum key.
//=================================================
template <typename D, typename K>
typename BST<D, K>::Node* BST<D, K>::treeMinimum(Node* x) const {
    while(x->left != nullptr){
        x = x->left;
    }
    return x;
}

//=================================================
// treeMaximum
// Finds the node with the maximum key in a subtree.
// Parameters:
//  x: A pointer to the root of the subtree to search.
// Return Value:
//  A pointer to the Node with the maximum key.
//=================================================
template <typename D, typename K>
typename BST<D, K>::Node* BST<D, K>::treeMaximum(Node* x) const {
    while(x->right != nullptr){
        x = x->right;
    }
    return x;
}

//=================================================
// BST (Default Constructor)
// Initializes an empty Binary Search Tree by setting
// the root pointer to nullptr.
// Parameters:
//  (none)
// Return Value:
//  (none)
//=================================================
template <typename D, typename K>
BST<D, K>::BST() {
    root = nullptr;
}

//=================================================
// ~BST (Destructor)
// Deallocates all memory used by the BST by calling
// the private clear helper function on the root.
// Parameters:
//  (none)
// Return Value:
//  (none)
//=================================================
template <typename D, typename K>
BST<D, K>::~BST() {
    clear(root);
    root = nullptr;
}

//=================================================
// empty
// Checks if the BST is empty.
// Parameters:
//  (none)
// Return Value:
//  True if the tree's root is nullptr, false otherwise.
//=================================================
template <typename D, typename K>
bool BST<D, K>::empty() const {
    return root == nullptr;
}

//=================================================
// insert
// Creates and inserts a new node with data `d` and
// key `k` into the BST, maintaining the BST property.
// Parameters:
//  d: The data of type D for the new node.
//  k: The key of type K for the new node.
// Return Value:
//  (none)
//=================================================
template <typename D, typename K>
void BST<D, K>::insert(D d, K k) {
    Node* z = new Node(d, k);
    Node* y = nullptr;
    Node* x = root;
    while (x) {
        y = x;
        if (k < x->key){
            x = x->left;
        } else {x = x->right;} // equal keys go right
    }
    z->parent = y;
    if (y == nullptr) root = z;
    else if (k < y->key) y->left = z;
    else y->right = z;
}

//=================================================
// get
// Retrieves the data associated with a given key.
// Parameters:
//  k: The key of type K to search for.
// Return Value:
//  The data of type D associated with the key, or a
//  default-constructed object of type D if not found.
//=================================================
template <typename D, typename K>
D BST<D, K>::get(K k) const {
    Node* x = search(k);
    if (x != nullptr) {
        return x->data;  // return the data stored at that node
    }
    // while (x) {
    //     if (k == x->key) return x->data;
    //     x = (k < x->key) {
    //         x->left;
    //     } else {x->right;}
    // }
    return D{}; // not found -> default
}

//=================================================
// remove
// Removes the first node found with the given key `k`
// from the tree, maintaining the BST property.
// Parameters:
//  k: The key of type K to remove.
// Return Value:
//  (none)
//=================================================
template <typename D, typename K>
void BST<D, K>::remove(K k){
    Node* z = search(k);
    if(!z) return; //k is not in the tree
    if (z->left== nullptr){
        transplant(z, z->right);
    }
    else if (z->right == nullptr)
    {
        transplant(z, z->left);
    }
    else { //case where both child exist
        Node* y = treeMinimum(z->right);
        // z->right;
        // while(y->left){
        //     y = y->left;
        // }
        if(y != z->right){
            transplant(y, y->right);
            y->right = z->right;
            y->right->parent = y; //link y with right node of z in both direction
        }
        transplant(z,y);
        y->left = z->left;
        y->left->parent = y;
    }   
}  

//=================================================
// max_data
// Finds and returns the data of the node with the
// largest key in the tree.
// Parameters:
//  (none)
// Return Value:
//  The data of type D from the maximum node, or a
//  default-constructed D if the tree is empty.
//=================================================
template <typename D, typename K>
D BST<D, K>::max_data() const{
    if(!root) {
        //throw run time would break the program 
        //so safely return default value if empty
        return D{}; 
    }
    Node* x = root;
    while(x->right){
        x = x->right;
    }
    return x->data;

}

//=================================================
// max_key
// Finds and returns the largest key in the tree.
// Parameters:
//  (none)
// Return Value:
//  The key of type K from the maximum node, or a
//  default-constructed K if the tree is empty.
//=================================================
template <typename D, typename K>
K BST<D, K>::max_key() const{
    if(!root) {
        return K{};
    }
    Node* x = root;
    while(x->right){
        x = x->right;
    }
    return x->key;

}

//=================================================
// min_data
// Finds and returns the data of the node with the
// smallest key in the tree.
// Parameters:
//  (none)
// Return Value:
//  The data of type D from the minimum node, or a
//  default-constructed D if the tree is empty.
//=================================================
template <typename D, typename K>
D BST<D, K>::min_data() const{
    if(!root) {
        return D{}; 
    }
    Node* x = root;
    while(x->left){
        x = x->left;
    }
    return x->data;

}

//=================================================
// min_key
// Finds and returns the smallest key in the tree.
// Parameters:
//  (none)
// Return Value:
//  The key of type K from the minimum node, or a
//  default-constructed K if the tree is empty.
//=================================================
template <typename D, typename K>
K BST<D, K>::min_key() const{
    if(!root) {
        return K{}; 
    }
    Node* x = root;
    while(x->left){
        x = x->left;
    }
    return x->key;
}

//=================================================
// successor
// Finds the in-order successor of a given key `k`.
// The successor is the node with the smallest key
// that is larger than `k`.
// Parameters:
//  k: The key of type K to find the successor of.
// Return Value:
//  The key of the successor node, or a default-
//  constructed K if no successor exists.
//=================================================
template <typename D, typename K>
K BST<D, K>::successor(K k) const{
    Node* x = search(k);
    if (!x) return K{}; // key not in tree
    if(x->right != nullptr){
        return treeMinimum(x->right)->key;
    } else {
        Node* y = x->parent;
        while(y!= nullptr && x== y->right){
            x = y;
            y = y->parent;
        }
        return y ? y->key : K{}; // in case y not found
    }
}

//=================================================
// to_string
// Generates a string representation of the tree's keys
// in level-order (breadth-first traversal).
// Parameters:
//  (none)
// Return Value:
//  A space-separated string of keys.
//=================================================
template <typename D, typename K>
string BST<D, K>::to_string() const{
    std::stringstream s;
    if (root == nullptr)
        return s.str();

    std::queue<Node*> q;       // queue for BFS
    q.push(root);              // start from root node

    s << root->key;           
    q.pop();              

    // Add its children to queue
    if (root->left) q.push(root->left);
    if (root->right) q.push(root->right);

    // Process rest of nodes
    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();

        s << " " << curr->key;  // print key with space before it

        // Add children to queue (keeps order level by level)
        if (curr->left) q.push(curr->left);
        if (curr->right) q.push(curr->right);
    }

    return s.str();
}

//=================================================
// in_order
// Generates a string representation of the tree's keys
// in sorted (in-order) traversal.
// Parameters:
//  (none)
// Return Value:
//  A space-separated string of keys in ascending order.
//=================================================
template <typename D, typename K>
string BST<D, K>::in_order() const{
    stringstream ss;
    bool first = true; //no space before first node
    // recursive lambda
    function<void(Node*)> inorder = [&](Node* x) {
        if (x == nullptr) return;
        inorder(x->left);
        if (!first) ss << " ";
        ss << x->key;
        first = false;
        inorder(x->right);
    };
    inorder(root);
    return ss.str();
}

//=================================================
// trim
// Removes all nodes from the tree whose keys are
// outside the inclusive range [low, high].
// Parameters:
//  low: The lower bound of the key range to keep.
//  high: The upper bound of the key range to keep.
// Return Value:
//  (none)
//=================================================
template <typename D, typename K>
void BST<D, K>::trim(K low, K high){
    if(!root) return;
    function<Node*(Node*)> trimRec = [&](Node* node) -> Node*{
        if (!node) return nullptr;
        if(node->key <low){
            Node* rightTrim = trimRec(node->right);
            clear(node->left);
            delete node;
            return rightTrim;
        }
        if(node->key >high){
            Node* leftTrim = trimRec(node->left);
            clear(node->right);
            delete node;
            return leftTrim;
        }
        node->left = trimRec(node->left);
        node->right = trimRec(node->right);
        return node;
    };
    //call the recursive lambda function
    root = trimRec(root);
    if (root) root->parent = nullptr;
}

//=================================================
// clear
// A private helper function that recursively deletes
// all nodes in a subtree to deallocate memory.
// Parameters:
//  node: A pointer to the root of the subtree to clear.
// Return Value:
//  (none)
//=================================================
template <typename D, typename K>
void BST<D, K>::clear(Node* node){
    if (!node) return;
    clear(node->left);
    clear(node->right);
    delete node;
}
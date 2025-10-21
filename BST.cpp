#include "BST.h"
#include <string>
#include <sstream>
#include <iostream>
#include <queue>        // for std::queue
#include <stack>        // for std::stack
#include <functional>   // for std::function
#include <stdexcept> 
using namespace std;
template <typename D, typename K>
BST<D, K>::Node::Node(D d, K k) {
    data = d;
    key = k;
    left = nullptr;
    right = nullptr;
    parent = nullptr;
}
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
template <typename D, typename K>
typename BST<D, K>::Node* BST<D, K>::treeMinimum(Node* x) const {
    while(x->left != nullptr){
        x = x->left;
    }
    return x;
}
template <typename D, typename K>
typename BST<D, K>::Node* BST<D, K>::treeMaximum(Node* x) const {
    while(x->right != nullptr){
        x = x->right;
    }
    return x;
}
template <typename D, typename K>
BST<D, K>::BST() {
    root = nullptr;
}
template <typename D, typename K>
BST<D, K>::~BST() {
    clear(root);
    root = nullptr;
}
template <typename D, typename K>
bool BST<D, K>::empty() const {
    return root == nullptr;
}

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
template <typename D, typename K>
D BST<D, K>::max_data() const{
    if(!root) {
        throw runtime_error("tree is empty");
    }
    Node* x = root;
    while(x->right){
        x = x->right;
    }
    return x->data;

}
template <typename D, typename K>
K BST<D, K>::max_key() const{
    if(!root) {
        throw runtime_error("tree is empty");
    }
    Node* x = root;
    while(x->right){
        x = x->right;
    }
    return x->key;

}
template <typename D, typename K>
D BST<D, K>::min_data() const{
    if(!root) {
        throw runtime_error("tree is empty");
    }
    Node* x = root;
    while(x->left){
        x = x->left;
    }
    return x->data;

}
template <typename D, typename K>
K BST<D, K>::min_key() const{
    if(!root) {
        throw runtime_error("tree is empty");
    }
    Node* x = root;
    while(x->left){
        x = x->left;
    }
    return x->key;
}
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
template <typename D, typename K>
string BST<D, K>::in_order() const{
    string result;
    // recursive lambda
    function<void(Node*)> inorder = [&](Node* x) {
        if (x == nullptr) return;
        inorder(x->left);
        if (!result.empty()) result += " ";
        result += std::to_string(x->key);
        inorder(x->right);
    };
    inorder(root);
    return result;
}
template <typename D, typename K>
void BST<D, K>::trim(K low, K high){
    function<void(Node*)> destroy = [&](Node* t) {
        if (!t) return;
        destroy(t->left);
        destroy(t->right);
        delete t;
    };

    function<Node*(Node*)> trimRec = [&](Node* node) -> Node* {
        if (!node) return nullptr;

        if (node->key < low) {
            Node* rightTrim = trimRec(node->right);
            destroy(node->left);
            // delete current node (since it's out of range and not returned)
            node->left = node->right = nullptr;
            delete node;
            if (rightTrim) rightTrim->parent = nullptr; // parent fixed at caller
            return rightTrim;
        }
        if (node->key > high) {
            Node* leftTrim = trimRec(node->left);
            destroy(node->right);
            node->left = node->right = nullptr;
            delete node;
            if (leftTrim) leftTrim->parent = nullptr;
            return leftTrim;
        }

        Node* L = trimRec(node->left);
        if (L) { L->parent = node; }
        node->left = L;

        Node* R = trimRec(node->right);
        if (R) { R->parent = node; }
        node->right = R;

        return node;
    };

    root = trimRec(root);
    if (root) root->parent = nullptr;
}
template <typename D, typename K>
void BST<D, K>::clear(Node* node){
    if (!node) return;
    clear(node->left);
    clear(node->right);
    delete node;
}
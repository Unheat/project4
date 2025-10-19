#include "BST.h"
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
    Node* x = root;
    while (x) {
        if (k == x->key) return x->data;
        x = (k < x->key) {
            x->left;
        } else {x->right;}
    }
    return D{}; // not found -> default
}

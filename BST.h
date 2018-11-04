//
// Created by Alex on 11/2/2018.
//

#ifndef BINARYSEARCHTREE_BST_H
#define BINARYSEARCHTREE_BST_H
using namespace std;

#include <iostream>

template<class T>
struct node {
    T data;
    node<T> *left;
    node<T> *right;
};

template<class T>
class BST {
    node<T> *root;

public:
    //constructor
    BST() { root = NULL; }

    void insert(T &item);

    void deleteNode(T &);

    bool search(T &);

    int height;

    T findMax(T&);

    T findMin();

    void printPreOrder();

    void printPostOrder();

    void printInOrder();

private:
    void insert(node<T> *&, T &);

    void deleteNode(node<T> *&, T &);

    void search(node<T> *&, T &);

    void printPreOrder(node<T> *);

    void printPostOrder(node<T> *);

    void printInOrder(node<T> *);

    T findMax(node<T>*, T&);

};

template<class T>
void BST<T>::insert(T &item) {//needs another method which has to be private
    insert(root, item); // passes the root so that you can find the right location for the node
};

//insert(node<T>*& p, T& item) needs to be a reference becuase you're not updating your data, this will be used for a recusive call
//you are now passing the nodes pointer, not creating a new pointer, pointing to a node
// if item is less recusively try the left child, if p is null, create node and insert
template<class T>
void BST<T>::insert(node<T> *&p, T &item) {
    if (p == NULL) {//checks if the tree isn't populated yet
        p = new node<T>;
        p->data = item;
        p->left = p->right = NULL; // sets children pointers to null, no leaf nodes.
    } else if (item < p->data) {
        insert(p->left, item);
    } else {
        insert(p->right, item);
    }

};

template<class T>
void BST<T>::printPreOrder() {
    printPreOrder(root);
};

template<class T>
void BST<T>::printPreOrder(node<T> *p) {
    if (p != NULL) {
        cout << p->data << endl;
        printPreOrder(p->left);
        printPreOrder(p->right);
    }
};
template<class T>
void BST<T>::printInOrder() {
    printPostOrder(root);
};
template<class T>
void BST<T>::printInOrder(node<T> *p) {
    if (p != NULL) {

        printPreOrder(p->left);
        cout << p->data << endl;
        printPreOrder(p->right);
    }
};
template<class T>
void BST<T>::printPostOrder() {
    printPostOrder(root);
};
template<class T>
void BST<T>::printPostOrder(node<T> *p) {
    if (p != NULL) {
        printPreOrder(p->left);
        printPreOrder(p->right);
        cout << p->data << endl;
    }
};
template<class T>
T BST<T>::findMax(T& e) {
    return findMax(root, e);
}
template <class T>
T BST<T>::findMax(node<T> * p, T& e) {
    if(p == NULL){
        return e;
        //cerr << "Tree is empty" << endl;
    } else if (p->right == NULL){
        return p->data;
    } else {
        findMax(p->right, e);
    }

}

#endif //BINARYSEARCHTREE_BST_H

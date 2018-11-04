#include <iostream>
#include "BST.h"
using namespace std;

int main() {
    BST<int> bst;
    int y =4, x =12, z=2;
    bst.insert(y);
    bst.insert(x);
    bst.insert(z);

//    bst.printInOrder();
//    bst.printPostOrder();
//    bst.printPreOrder();
    int e = -1;
    cout << bst.findMax(e) <<endl;
    return 0;
};
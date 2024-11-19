//
// Created by ateeb on 09/11/2024.
//

#include "BinarySearchTree.h"
#include <stdio.h>
#include <iostream>

using namespace std;

int main(){
    BinarySearchTree T;
    // T.insert(10);
    // T.insert(7);
    // T.insert(5);
    // T.insert(9);
    // T.insert(8);
    // T.insert(16);
    // T.insert(13);
    // T.insert(20);
    // T.insert(25);
    //
    // T.preOrder();
    // T.postOrder();
    // T.inOrder();
    // T.levelOrder();

    T.insert(12);
    T.insert(5);
    T.insert(3);
    T.insert(1);
    T.insert(7);
    T.insert(9);
    T.insert(8);
    T.insert(11);
    T.insert(15);
    T.insert(13);
    T.insert(14);
    T.insert(17);
    T.insert(20);
    T.insert(18);

    T.printTree();

    // cout << "Delete 9 \n";
    // T.deleteNode(9);
    // T.printTree();
    //
    // cout << "Delete 15 \n";
    // T.deleteNode(15);
    // T.printTree();

    T.printLeaves();


}

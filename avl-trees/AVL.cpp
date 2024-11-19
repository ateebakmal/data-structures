//
// Created by ateeb on 19/11/2024.
//

#include "AVL.h"
#include <stdio.h>
#include <iostream>

using namespace std;

int main(){
    AVL a;

    a.insert(30);
    a.printTree();

    a.insert(20);
    a.printTree();

    a.insert(10);
    a.printTree();

    a.insert(40);
    a.printTree();

    a.insert(45);
    a.printTree();

    a.insert(50);
    a.printTree();

    a.insert(60);
    a.printTree();

    a.insert(75);
    a.printTree();

    return 0;
}

//
// Created by ateeb on 24/10/2024.
//

#include "DequeueWithDoublyLinkedList.h"
#include <stdio.h>
#include <iostream>
using namespace std;


int main()
{
    DequeueWithDoublyLinkedList q;
    cout << "Push 10" << endl;
    q.push(10);
    q.display();

    cout << "Push 20" << endl;
    q.push(20);
    q.display();


    cout << "Inject 20" << endl;
    q.inject(20);
    q.display();

    cout << "Pop" << endl;
    q.pop();
    q.display();

    cout << "Eject" << endl;
    q.eject();
    q.display();

    cout << "Pop" << endl;
    q.pop();
    q.display();



    return 0;
}
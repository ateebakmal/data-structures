//
// Created by ateeb on 10/11/2024.
//

#include "DoublyEndedCircularQueue.h"

#include <stdio.h>
#include <iostream>

using namespace std;

int main(){

    DoublyEndedCircularQueue q;

    q.insertAtFront(1);
    q.display();
    q.insertAtFront(2);
    q.display();
    q.insertAtFront(2);
    q.insertAtFront(2);
    q.insertAtFront(2);
    q.insertAtFront(2);

    return 0;
}

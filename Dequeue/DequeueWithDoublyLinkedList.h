//
// Created by ateeb on 24/10/2024.
//

#ifndef DEQUEUEWITHDOUBLYLINKEDLIST_H
#define DEQUEUEWITHDOUBLYLINKEDLIST_H
#include <iostream>
using namespace std;

class DoubleNode
{
public:
    DoubleNode* prev;

    int data;

    DoubleNode* next;

    DoubleNode(int data)
    {
        this->prev = nullptr;
        this->data = data;
        this->next = nullptr;
    }
};


class DequeueWithDoublyLinkedList
{
private:
    DoubleNode* front;
    DoubleNode* rear;
    int size;

    //This function only use is to create the first node whenever our linked list is empty
    void addFirstNode(int data)
    {
        DoubleNode* newNode = new DoubleNode(data);
        this->front = newNode;
        this->rear = newNode;
        this->size++;
    }

public:
    DequeueWithDoublyLinkedList()
    {
        this->front = nullptr;
        this->rear = nullptr;
        this->size = 0;
    }

    void push(int data)
    {
        //Check if our list is empty.
        if(this->size == 0)
        {
            addFirstNode(data);
            return;
        }

        //Add this new data in a node before the front
        DoubleNode* newNode = new DoubleNode(data);
        this->front->prev = newNode;
        newNode->next = this->front;

        //Update the front
        this->front = newNode;
        this->size++;
    }

    int pop()
    {
        if(this->size == 0)
        {
            throw "Empty Queue";
        }

        DoubleNode* temp = this->front;

        //If the node we are popping is the only node in the linked list
        if(this->front == this->rear)
        {
            this->front = this->rear = nullptr;
        }else
        {
            this->front = this->front->next;
        }

        int returnData =  temp->data;
        delete temp;
        this->size--;

        return returnData;
    }

    void inject(int data)
    {
        //Check if our list is empty
        if(this->size == 0)
        {
            addFirstNode(data);
            return;
        }

        DoubleNode* newNode = new DoubleNode(data);
        //We have to add this node at the end
        this->rear->next = newNode;
        newNode->prev = this->rear;
        this->rear = newNode;

        //Update the size
        this->size++;
    }

    int eject()
    {
        if(this->size == 0)
        {
            cout << "Empty Queue";
            return -1;
        }

        DoubleNode* temp = this->rear;
        //Check if there is only one node
        if(this->front == this->rear)
        {
            this->front = this->rear = nullptr;
        }else
        {
            this->rear = this->rear->prev;
            this->rear->next = nullptr;
        }

        int returnData = temp->data;
        this->size--;
        delete temp;

        return returnData;

    }

    void display()
    {
        if(this->size == 0)
        {
            cout << "Empty Queue";
            return;
        }
        DoubleNode* temp = this->front;

        while(temp != nullptr)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }

        cout << "nullptr" << endl;
        cout << endl;
    }
};





#endif //DEQUEUEWITHDOUBLYLINKEDLIST_H

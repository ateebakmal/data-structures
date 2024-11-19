//
// Created by ateeb on 10/11/2024.
//

#ifndef DOUBLYENDEDCIRCULARQUEUE_H
#define DOUBLYENDEDCIRCULARQUEUE_H
#include <iostream>
using namespace std;


class DoublyEndedCircularQueue {
private:
    int front , rear;
    int* array;
    int size;
    int capacity;


public:
    DoublyEndedCircularQueue(){
        front = -1;
        rear = -1;
        capacity = 8;
        array = new int[capacity];
        size = 0;
    }

    bool isEmpty(){
        return size == 0;
    }

    bool isFull(){
        return size == capacity;
    }

    void insertAtFront(int n){
        if(this->isEmpty()){
            rear = front = 0;
        }else if(this->isFull()){
            cout << "Queue is full" << endl;
            return;
        }else if(front == 0){
            front = capacity - 1;
        }else{
            front--;
        }


        this->array[front] = n;
        this->size++;
    }

    void insertAtRear(int n){
        if(this->isEmpty()){
            front = rear = 0;
        }else if(this->isFull()){
            cout << "Queue is full" << endl;
            return;
        }else{
            rear = (rear + 1) % capacity;
        }

        this->array[rear] = n;
        size++;
    }

    void deleteAtFront(){
        if(this->front == this->rear){
            this->front = this->rear = -1;
        }else{
            this->front = (this->front + 1) % capacity;
        }
    }

    void dequeueAtRear(){
        if(this->front == this->rear){
            this->front = this->rear = -1;
        }else if (rear == 0) {
            rear = capacity - 1;
        }else{
            rear = rear -1;
        }
    }

    void display(){
        int i = front;
        while(i != rear){
            cout << "| " << array[i] << "| ";
            i = (i + 1) % capacity;
        }

        cout << "| " << array[rear] << "| ";

        cout << endl;
    }
};



#endif //DOUBLYENDEDCIRCULARQUEUE_H

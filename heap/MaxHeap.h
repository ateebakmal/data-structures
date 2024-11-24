//
// Created by ateeb on 24/11/2024.
//

#ifndef MAXHEAP_H
#define MAXHEAP_H
#include <forward_list>
#include <iostream>

class MaxHeap
{
private:
    int* array;
    int size;
    int capacity;
    int current;

    void resize(){
        this->capacity *= 2;
        int* temp = new int[capacity];

        for (int i = 0; i < this->size; i++){
            temp[i] = this->array[i];
        }
        delete[] this->array;
        this->array = temp;
    }

    void heapifyUp(int index){
        while(index > 0){
            int parent = (index - 1) / 2;
            if(this->array[parent] < this->array[index]){
                std::swap(array[index], array[parent]);
                index = parent;
            }else{
                break;
            }
        }
    }

    void heapifyDown(int index){
        int leftChild = (index * 2) + 1;
        int rightChild = (index * 2) + 2;

        while(leftChild < this->size){
            int largest = index;

            //Check if left child is greater
            if(this->array[leftChild] > this->array[largest]){
                largest = leftChild;
            }

            //Check if right child is greater
            if(this->array[rightChild] > this->array[largest]){
                largest = rightChild;
            }


            if(largest != index){
                std::swap(array[index], array[largest]);
            }else{
                return;
            }

            index = largest;
            leftChild = (index * 2) + 1;
            rightChild = (index * 2) + 2;

        }
    }
public:
    MaxHeap(){
        this->array = new int[8];
        this->current = -1;
        this->size = 0;
        this->capacity = 8;
    }

    void insert(int data){
        if(this->size == this->capacity){
            this->resize();
        }

        this->array[++this->current] = data;
        this->size++;
        this->heapifyUp(this->current);
    }


    int remove(){
        if(this->size == 0){
            throw std::runtime_error("The heap is empty.");
        }

        int maxValue = this->array[0];
        array[0] = array[this->current];
        this->size--;
        this->current--;
        this->heapifyDown(0);
        return this->array[0];
    }
    void display(){
        for(int i = 0; i <= this->current; i++){
            std::cout << this->array[i] << " ";
        }
        std::cout << std::endl;
    }


};
#endif //MAXHEAP_H

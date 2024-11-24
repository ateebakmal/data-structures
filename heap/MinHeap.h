//
// Created by ateeb on 24/11/2024.
//

#ifndef MINHEAP_H
#define MINHEAP_H
#include <iostream>
#include <vector>

using namespace std;

class MinHeap
{
private:
    vector<int> array;

    void heapifyUp(int index){
        while(index > 0){
            int parent = (index - 1) / 2;

            if(array[parent] > array[index]){
                swap(array[index], array[parent]);
            }

            index = parent;
        }
    }

    void heapifyDown(int index){
        int leftChild = (index * 2) + 1;
        int rightChild = (index * 2) + 2;

        int smallest = index;

        if(leftChild < array.size() && array[leftChild] < array[smallest]){
            smallest = leftChild;
        }

        if(rightChild < array.size() && array[rightChild] < array[smallest]){
            smallest = rightChild;
        }

        //Edge case
        if(smallest == index){
            return;
        }

        swap(array[index], array[smallest]);
        heapifyDown(smallest);
    }
public:

    MinHeap(){
        array = vector<int>();
    }

    void insert(int value){

        //Adds the element at the end of the array
        array.push_back(value);
        this->heapifyUp(this->array.size() - 1);
    }

    void remove(){
        //Replace first element with last element
        array[0] = array[array.size() - 1]; // Done in O(1)

        //Delete the last element
        array.pop_back(); // Done in O(1)

        //Make sure the heap property is maintained
        this->heapifyDown(0);
    }
    int getMin(){
        return array[0];
    }

    void display(){
        for(int i = 0; i < array.size(); i++){
            cout << "| " << array[i] << " | ";
        }
        cout << endl;
    }
};
#endif //MINHEAP_H

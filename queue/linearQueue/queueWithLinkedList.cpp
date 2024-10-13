#include <iostream>

using namespace std;

class Node{
   public:
      int data;
      Node* next;

      Node(int data){
         this->data = data;
         this->next = nullptr;
      }
};

class Queue{
   private:
      Node* front;
      Node* rear;
      int size;

   public: 
      Queue(){
         this->front = nullptr;
         this->rear = nullptr;
         this->size = 0;
      }
      
      //Writing a destructotor to free up the dynamically allocated memory
      ¬Queue(){
         Node* temp = this->front;
         while(temp != nullptr){
            Node* next = temp->next;
            delete temp;
            temp = next;
         }
      }
      //There will be no isFull function. Since we are implementing it using linked list which makes
      //it dynamic. Meaning there is no memory limit. We can always add more nodes. (unless we run out of RAM :) ) 

      bool isEmpty(){
         return this->size == 0;
      }


      void enqueue(int data){
         //Make a new Node
         Node* newNode = new Node(data);

         if(this->isEmpty()){
            this->front = newNode;
            this->rear = newNode;
            ++this->size;
            return;            
         }

         //Connect the last node with the newNode
         this->rear->next = newNode;
         this->rear = newNode;
         ++this->size;
      }

      void dequeue(){
         //Check if our list is empty
         if(this->size == 0){
            cout << "Queue is empty" << endl;
            return;
         }
         //Check if thier is only one element in our queue
         if(this->size == 1){
            this->rear = nullptr;
         }

         //Move the first to next
         Node* temp = this->front;
         this->front = this->front->next;
         delete temp;
         --this->size;

      }

      int peek(){
         //If queue is empty it will give an error. You can handle it howwver you want
         return this->front->data;
      }

      void display(){
         if(this->size == 0){
            cout << "Queue is empty" <<endl;
            return;
         }
         Node* temp = this->front;

         while(temp != nullptr){
            printf(" %d | ", temp->data);
            temp = temp->next;
         }

         cout << endl;
      }

      int getSize(){
         return this->size;
      }

};
int main(){
   Queue q;

   q.enqueue(1);
   q.enqueue(2);
   q.enqueue(3);
   q.enqueue(4);
   q.display();

   printf("Deleting the top \n");
   q.dequeue();
   q.display();

   q.enqueue(6);
   q.display();
   printf("Size : %d\n", q.getSize());
   q.dequeue();
   q.dequeue();
   q.dequeue();
   q.dequeue();
   q.display();
   
   printf("Size : %d\n", q.getSize());

   q.enqueue(4);
   q.display();

   q.enqueue(3);
   q.display();

   q.enqueue(1);
   q.display();

   q.enqueue(5);
   q.display();

   q.enqueue(3);
   q.display();
   printf("Size : %d\n", q.getSize());
   return 0;
}
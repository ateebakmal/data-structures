#include <iostream>
using namespace std;

class Queue{
   private:
      int front;
      int rear;
      int capacity;
      int size;
      int* arr;
   
   public:
      //constructor
      Queue(int size){
         this->front = 0;
         this->rear = -1;
         this->capacity = size;
         this->size = 0;
         this->arr = new int[size];
      }


      bool isEmpty(){
         return this->size == 0;
      }

      bool isFull(){
         return this->size == capacity;
      }

      void enqueue(int n){
         if(this->isFull()){
            cout << "Queue is full. Can't add anymore" << endl;
            return;
         }

         arr[++this->rear] = n;
         ++this->size;
      }

      void dequeue(){
         //Edge case: if queue is empty
         if(this->size == 0){
            cout << "Queue is empty" << endl;
            return;
         }


         //Shift all the elements towards left
         for(int i = front; i < this->size -1 ; i++){
            arr[i] = arr[i+1];
         }

         //decrement the rear
         --this->rear;
         --this->size;
      }

      int peek(){
         return arr[front];
      }

      void display(){
         if(this->size == 0){
            cout << "Queue is empty" <<endl;
            return;
         }

         for(int i = this->front; i <= this->rear; i++){
            printf(" %d <-- ", arr[i]);
         }

         cout << endl;
      }

};

int main(){
   Queue q(4);

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

   q.dequeue();
   q.dequeue();
   q.dequeue();
   q.dequeue();
   q.display();

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

   return 0;
}
#include <iostream>

using namespace std;

class Queue{
   private:
      int front;
      int rear;
      int* arr;
      int length;

      void resize(){
         //Make a new array of twice the size
         int* newArray = new int[this->length * 2];
         int i = 0;
         int j = this->front;
         do{
            newArray[i++] = this->arr[j];
            j = (j + 1) % this->length;
         }while(j != front);

         //re arrange front and rear and length according to this new array
         this->front = 0;
         this->rear = this->length - 1;
         this->length = this->length * 2;

         //delete the old array to clear up some space
         delete this->arr;

         //Make our array pointer point to this new array
         this->arr = newArray;
      }
      
   public:
      //Constructor that takes some initial size
      Queue(int size){
         this->front = -1;
         this->rear = -1;
         this->arr = new int[size];
         this->length = size;
      }

      //Constructor that makes an array with predefined initial size (20)
      Queue(){
         this->front = -1;
         this->rear = -1;
         this->arr = new int[20];
         this->length = 20;
      }

      //Helper methods
      bool isFull(){
         return (rear + 1) % this->length ==  this->front; v
      }

      bool isEmpty(){
         return this->rear == -1;
      }


      //Enqueue - dequeue - top
      void enqueue(int n){
         //Check if array is full , then either resize or display some error message and return
         if(this->isFull()){
            this->resize();
         }

         //IF array is empty. Point first to the start
         if(this->isEmpty()){
            this->front = 0;
         }

         this->rear = (this->rear + 1) % this->length;
         this->arr[this->rear] = n;
      }

      void dequeue(){
         //Check if it is empty. Then either throw some exception or diplay some error message and return
         if(this->isEmpty()){
            cout << "Queue is empty" << endl;
            return;
         }

         if( this->front == this->rear){
            this->front = this->rear = -1;
         }else{
            this->front = (this->front + 1) % this->length;
         }
      }

      void display(){
         if(this->isEmpty()){
            cout << "Queue is empty" << endl;
            return;
         }
         int i = this->front;
         
         //This loop will print until rear. But wont print rear
         while(i != this->rear){
            cout << this->arr[i] << " | ";
            i = (i + 1) % this->length;
         }

         //Print rear
         cout << arr[i] << endl;
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
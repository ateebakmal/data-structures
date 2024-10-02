#include <iostream>

using namespace std;

class Stack{
   private:
      int current;
      int stackSize;
      int* arr;
   
   public:

      //Constructor
      Stack(int size){
         this->stackSize = size;
         this->current = -1;
         this->arr = new int[size];
      }
      
      bool isFull(){
         return current == stackSize - 1;
      }

      bool isEmpty(){
         return current == -1;
      }


      void push(int element){
         if(this->isFull()){
            cout << "Stack is over flown. Can't push" << endl;
            return;
         }
         this->arr[++current] = element;
      }

      void pop(){
         if(this->isEmpty()){
            cout << "Stack is already empty. Can't pop" << endl;
            return;
         }
         current--;
      }

      int top(){
         if(this->isEmpty()){
            cout << "Stack is empty" << endl;
            return -1;
         }

         return arr[current];
      }

      int getSize(){
         return (current + 1);
      }

      void print(){
         //check if stack is empty
         if(current == -1){
            cout << "Stack is empty" << endl;
            return;
         }
         for(int i = this->size() - 1; i >= 0; i--){
            cout << "| ";
            cout << arr[i] << " |" << endl;
         }
      }
};

int main(){
   Stack stack(10);

   cout << "Size : " << stack.getSize() << endl;


   stack.push(1);
   stack.push(2);
   stack.push(3);

   cout << "Printing the stack" << endl;
   stack.print();

   cout << "Getting top" << endl;
   cout << "Top : " << stack.top() << endl;

   stack.pop();
   
   cout << "Printing the stack" << endl;
   stack.print();

   cout << "Getting top" << endl;
   cout << "Top : " << stack.top() << endl;

   stack.pop();
   stack.pop();
   stack.pop();
   cout << "Size : " << stack.getSize() << endl;


   return 0;
}  
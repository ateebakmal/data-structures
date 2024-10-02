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

class Stack{
   private:
      Node* current;
      int size;

   public:
      Stack(){
         this->current = nullptr;
         this->size = 0;
      }

      // there is no isFull function cuz this is dynamic stack. /
      //Meaning we can always add new value using a node

      bool isEmpty(){
         return current == nullptr;

         // or you can also do this instead.
         //return size == 0;
      }

      int getSize(){
         return this->size;
      }

      // When you call push function it will always insert node at head.
      //Head in this case is current. It will add node before current and make it current
      void push(int data){
         Node* newNode = new Node(data);

         newNode->next = current;
         this->current = newNode;
         ++this->size;
      }


      void pop(){
         //Check if the size is zero then return
         if(this->size == 0){
            cout << "Stack is empty" << endl;
            return;
         }

         //Move current to next and delete the current node
         Node* temp = current;
         this->current = current->next;
         delete temp;
         --this->size;
      }

      int top(){
         if(this->isEmpty()){
            cout << "Stack is empty" << endl;
            return -1;
         }

         return current->data;
      }

      void print(){
         Node* temp = this->current;

         while(temp != nullptr){
            cout << "| ";
            cout << temp->data << " |" << endl;
            temp = temp->next;
         }
      }
};
int main(){
   Stack stack;

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
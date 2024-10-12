#include <iostream>

using namespace std;

//Make class node
class Node{
   public:
      Node* prev;
      int data;
      Node* next;

      Node(int data){
         this->prev = nullptr;
         this->data = data;
         this->next = nullptr;
      }
};


//implementing this using only head. You can also use tail pointer for more efficieny and ease. but this is for the implementation
class DoublyCircularLinkedList{

   private:
      Node* head;
   
   DoublyCircularLinkedList(){
      this-> head = nullptr;
   }

   //---------------------Insetion methods
   void insertAtHead(int data){
      Node* newNode = new Node(data);
      //If head is nullptr
      if(!head){
         this->head = newNode;
         newNode->next = newNode;
         newNode->prev = newNode;
         return;
      }

      
   }

   //---------------------Display methods
   void display(){
      //If list is empty
      if(this->head == nullptr){
         cout << "List is empty" << endl;
         return;
      }

      Node* current = this->head;
      while(current->next != nullptr){
         cout << current->data << " -> ";
         current = current->next;
      }

      //Print the last node
      cout << current->data << " -> " << "end" << endl;
   }
}

int main(){

   return 0;
}
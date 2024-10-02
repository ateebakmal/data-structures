#include <iostream>

using namespace std;

class Node{
   public:
      int data;
      Node* next;

      //constuctor
      Node(int data){
         this->data = data;
         this->next = nullptr;
      }  
};


class Circular{
   private:
      Node* head;
      Node* tail;

   public: 
      //constructor
      Circular(){
         this->head = nullptr;
      }


      //Insertion methods
      void insertAtHead(int data){
         Node* newNode = new Node(data);
         //Check if head is empty
         if(this->head == nullptr){
            this->head = newNode;
            newNode->next = newNode;
            return;
         }

         //find the last node
         Node* current = this->head;
         while(current->next != this->head){
            current = current->next;
         }

         newNode->next = head;
         current->next = newNode;
         head = newNode;
      }

      void insertAtTail(int data){
         Node* newNode = new Node(data);

         //check is list is empty
         if(this->head == nullptr){
            this->head = newNode;
            newNode->next = newNode;
            return;
         }

         //find the last node
         Node* current = this->head;
         while(current->next != this->head){
            current = current->next;
         }

         newNode->next = head;
         current->next = newNode;
      }

      void insertBefore(int data, int key){
         //Edge case. If list is empty
         if(this->head == nullptr){
            cout << "Linked List is empty\n";
            return;
         }

         //Case 2. If key is head
         if(this->head->data == key){
            this->insertAtHead(data);
            return;
         }

         //find the previous node of node with given key
         Node* newNode = new Node(data);
         Node* current = this->head;

         while(current->next != head && current->next->data != key){
            current = current->next;
         }

         //check if current->next == head. That means we have reached the end of nodes and havent found the key
         if(current->next == head){
            cout << "Node with value '" << key << "' not found in the list\n";
            return;
         }

         //link the nodes
         newNode->next = current->next;
         current->next = newNode;
      }

      int find(int key){
         int index = 0;
         Node* current = head;
         while(current->next != head){
            if(current->data == key){
               return index;
            }else{
               index++;
               current = current->next;
            }
         }

         //at last node. check if it has key
         if(current->data == key){
            return index++;
         }

         return -1;

      }

      void remove(int key){
         //check if the key is at head


         //check if the key is at head
         if(this->head->data == key){
            if(this->head->next == this->head){
               Node* temp = this->head;
               delete temp;
               this->head = nullptr;
               return;
            }
            Node* tail = this->head;
            //finding the head;
            while(tail->next != this->head){
               tail = tail->next;
            }
            Node* temp = this->head;
            this->head = this->head->next;
            tail->next = head;
            delete temp;
            return;
         }


         //find the node to delete until the last node.
         Node* current = this->head;
         while(current->next->next != this->head ){
            if(current->next->data == key){
               current->next = current->next->next;
               delete current->next;
               return;
            }

            current = current->next;
         }
         
         // if reached here, we at are at second last
         if(current->next->data == key){
            Node* temp = current->next;
            current->next = this->head;
            delete temp;
            return;
         }

         cout << "Given "<< key << " is not in the list";
      }     
      //-------------------------------------------------
      
      
      //travsersal functions
      void display(){
         if(this->head == nullptr){
            cout << "Linked list is empty " << endl;
         }
         Node* current = this->head;
         while(current->next != this->head){
            cout << current->data << " -> ";
            current = current->next;
         }

         cout << current->data << " -> nullptr" << endl;
      }
};

int main(){
   Circular list;

   list.insertAtHead(5);
   list.insertAtHead(1);
   list.insertAtTail(2);
   list.insertAtTail(3);
   list.display();
   list.remove(1);
   list.display();
   list.remove(3);
   list.display();
   list.remove(2);
   list.display();
   list.remove(5);
   list.display();
   // list.insertBefore(1,3);
   // list.insertBefore(6,5);
   // list.insertBefore(3,4);
   // list.insertBefore(100,100);
   // list.display();

   // Circular list2;
   // list2.insertAtTail(1);
   // list2.insertBefore(2,1);
   // list2.display();
   return 0;
}
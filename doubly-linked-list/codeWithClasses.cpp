#include <iostream>

using namespace std;

//Make a class of node
class Node{
   public: 
   Node* prev;
   int data;
   Node* next;

   //constructor
   Node(int data){
      this->data = data;
      this->next = nullptr;
      this->prev = nullptr;
   }
};


//Make a class of doubly linked list
class DoublyLinkedList{
   private:
      Node* head;
      Node* tail;
   
   public:
      DoublyLinkedList(){
         head = nullptr;
         tail = nullptr;
      }

      void insertAtStart(int data){
         //If our list is empty
         Node* newNode = new Node(data);
         if(this->head == nullptr){
            head = tail = newNode;
            return;
         }
         newNode->next = head;
         head->prev = newNode;
         head = newNode;
      }


      void insertAtEnd(int data){
         Node* newNode = new Node(data);

         //If our list is empty
         if(this->head == nullptr){
            head = tail = newNode;
            return;
         }

         //If our list contains some data
         Node* current = head;
         while(current->next != nullptr){
            current = current->next;
         }

         current->next = newNode;
         newNode->prev = current;
         tail = newNode;

      }

      void insertAfter(int key, int data){

         Node* newNode = new Node(data);

         //If list is empty
         if(head == nullptr){
            cout << "List is empty\n";
            return;
         }

         //find the Node with given key
         Node* current = this->head;
         while(current != nullptr && current -> data != key){
            current = current->next;
         }

         //if current is nullptr. given key isnt in list
         if(current == nullptr){
            cout << "Key '" << key << "' is not in the list\n";
            return;
         }

         if(current->next == nullptr){
            current->next = newNode;
            newNode->prev = current;
            tail = newNode;
         }else{
            newNode->next = current->next;
            newNode->prev = current;
            current->next->prev = newNode;
            current->next = newNode;
         }
      }

      void deleteHead(){
         if(this->head == nullptr){
            cout << "Linked list is empty\n";
            return;
         }

         if(head == tail){
            Node* temp = tail;
            head = tail = nullptr;
            delete temp;
            return;
            
         }

         Node* temp = this->head;
         head = head->next;
         head->prev = nullptr;
         delete temp;
      }

      void deleteTail(){
         if(this->head == nullptr){
            cout << "Linked List is empty\n";
            return;
         }

         //check if tail is the only node in list
         if(head == tail){
            Node* temp = tail;
            head = tail = nullptr;
            delete temp;
            return;
            
         }
         Node* temp = this->tail;
         tail = tail->prev;
         tail->next = nullptr;
         delete temp;
      }

      void deleteNode(int value){
         if(head->data == value){
            deleteHead();
            return;
         }

         if(tail->data == value){
            deleteTail();
            return;
         }


         //find the node with the value
         Node* current = this->head;
         while(current->next != nullptr && current->data != value){
            current = current->next;
         }

         if(current == nullptr){
            cout << "Value " << value << " is not in the list";
            return;
         }

         current->prev->next = current->next;
         current->next->prev = current->prev;
         delete current;
      }
      void display(){
         Node* current = this->head;
         while(current != nullptr){
            cout << current->data << " -> ";
            current = current -> next;
         }
         cout << "nullptr\n";
      }

      void displayInReverse(){
         Node* current = this->tail;
         while(current != nullptr){
            cout << current->data << " -> ";
            current = current -> prev;
         }
         cout << "nullptr\n";
      }

      int length(){
         int x = 0;
         Node* start = head;
         Node* end = tail;
         while(start != tail){
            ++x;
            start=start->next;
            end = end->prev;
         }

         return ++x;
      }

      void swapFirstWithLast(){
         int mid = this->length() / 2;
         int i = 0;
         Node* start = head;
         Node* end = tail;

         while(i != mid){
            //swap the data of tail and node
            int temp = start->data;
            start->data = end->data;
            end->data = temp;

            // update the nodes
            start = start->next;
            end = end->prev;
            ++i;
         }
      }
};

int main(){

   DoublyLinkedList list;

   list.insertAtStart(1);
   list.insertAtStart(2);
   list.insertAtEnd(3);
   list.insertAtEnd(4);
   list.insertAfter(4,2);
   list.insertAfter(2,5);
   list.insertAfter(3,7);
   list.deleteNode(2);

   cout << "Forward traversal:\n";
   list.display();
   
   // cout << "Backward traversal:\n";
   // list.displayInReverse();

   cout << "Swapping the nodes: \n";
   list.swapFirstWithLast();
   list.display();


   // cout << list.findLength();
   // DoublyLinkedList list2;
   // list2.insertAtStart(1);
   // list2.display();
   // list2.deleteTail();
   // list2.display();
   return 0;
}
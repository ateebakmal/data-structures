#include <iostream>
using namespace std;

//defining the structure of double linked list
struct Node{
   Node* prev;
   int data;
   Node* next;
};

Node* createNode(int data){
   Node* newNode = new Node;
   newNode->prev = nullptr;
   newNode->data = data;
   newNode->next = nullptr;
   return newNode;
}

//------------------------------------------
//methods for insertion
void insertAtBeginning(Node*& head, Node*& tail, int data){
   Node* newNode = createNode(data);

   if(head == nullptr){
      head = tail = newNode;
   }else{
      newNode->next = head;
      head->prev = newNode;
      head = newNode;
   }
   
}


void insertAtEnd(Node*& head,Node*& tail , int data){
   Node* newNode = createNode(data);
   //Edge case- WHat if there is not list?
   if(tail == nullptr){
      head = tail = newNode;
   }else{
      newNode->prev = tail;
      tail->next = newNode;
      tail = newNode;
   }
      
}


void insertAfterValue(Node*& head, Node*& tail, int value,int data){
   Node* newNode = createNode(data);

   Node* current = head;
   while(current != nullptr && current->data != value){
      current = current->next;
   }

   //If current is null. We have reached the end
   if(current == nullptr){
      cout<<"Value " << value <<" not found. Reached End.\n";
      return;
   }

   //Insert the new Node
   newNode->next = current->next;
   newNode->prev = current;
   
   if(current->next != nullptr){
      current->next->prev = newNode;
   }else{
      tail = newNode;
   }
   current->next = newNode;
}

//------------------------------------------
//Deletion methods
void deleteFromBeginning(Node*& head,Node*& tail){
   //If the head is nullptr
   if(head == nullptr){
      cout<< "List is empty\n";
      return;
   }
   
   Node* current = head;
   head = head->next;

   //Checking if our next pointer is null. If it is null then there is only one node in list. Deleting it will make both head and tail null pointers
   if(head == nullptr){
      tail = nullptr;
   }else{
      head->prev = nullptr;
   }
   delete current;

}

void deleteFromEnd(Node*& head, Node*& tail){
   Node* current = tail;
   tail = tail->prev;

   if(tail == nullptr){
      head = nullptr;
   }else{
      tail->next = nullptr;
   }

   delete current;

}
void deleteByValue(Node*& head, Node*& tail, int value){

   //traverse through the list to find the node with the value to delete   
   Node* current = head;
   while(current != nullptr && current->data != value){
      current = current->next; 
   }

   //Check if current node is nullptr
   if(current == nullptr){
      cout<<"No Node with value << " << value << " was found\n";
      return;
   }

   //check if current (Node to delete is the first node)
   if(current == head){
      deleteFromBeginning(head, tail);
      return;
   }

   //check if current (Node to delete is the last node)
   if(current == tail){
      deleteFromEnd(head, tail);
      return;
   }

   current->prev->next = current->next;
   current->next->prev = current->prev;
   delete current;
}
//------------------------------------------
//methods for traversal

//forward traversal (from head to tail)
void forwardTraversal(Node* head){
   Node* current = head;

   while(current != nullptr){
      cout<< current->data <<" -> ";
      current = current->next;
   }
   cout<< "nullptr" <<endl;
}

//backward traversal (from tail to head)
void backwardTraversal(Node* tail){
   Node* current = tail;

   while(current != nullptr){
      cout<< current->data <<" -> ";
      current = current->prev;
   }
   cout<<"nullptr\n";
}

int main(){
   
   Node* head = nullptr;
   Node* tail = nullptr;

   insertAtBeginning(head, tail , 1);
   insertAtBeginning(head, tail , 4);

   insertAtEnd(head , tail , 2);
   insertAtEnd(head, tail , 5);

   insertAfterValue(head , tail, 2 , 7);
   insertAfterValue(head, tail , 7, 6);


   deleteFromEnd(head , tail);

   deleteByValue(head , tail ,4);

   deleteByValue(head , tail , 7);

   deleteByValue(head , tail , 99);             
   forwardTraversal(head);

   return 0;
}
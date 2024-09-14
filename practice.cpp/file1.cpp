#include <iostream>
using namespace std;

struct Node{
   int data;
   Node* next;
};

//method to create a node
Node* createNode(int data){
   Node* node = new Node;
   node->data = data;
   node->next = nullptr;
   return node;
}

//function that creates a node at the start
void insertAtBeginning(Node*& head , int data){
   Node* newNode = createNode(data);
   newNode->next = head;
   head = newNode;  
}

//function that inserts at the end
void insertAtEnd(Node* head, int data){
   Node* newNode = createNode(4);

   if(head == nullptr){
      head->next = newNode;
      return;
   }

   Node* current = head;
   while(current != nullptr){
      current = current->next;
   }

   current->next = newNode;

}
//function that prints all the node
void printNodes(Node* head){
   Node* current = head;

   while(current != nullptr){
      //printing current value
      cout << current -> data << " -> ";
      
      //updating current pointer
      current = current -> next;
   }

   cout << "nullptr"<<endl;
}
int main(){
   Node* head = nullptr;

   
   insertAtBeginning(head, 1);
   printNodes(head);

   cout<<"Inserting 2 at start"<<endl;

   insertAtBeginning(head , 2);
   printNodes(head);
   return 0;
}
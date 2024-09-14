#include <iostream>
using namespace std;

//Making a struct of Node
struct Node{
   int data;
   Node* next;
};

//method that creates a node;
Node* createNode(int data){
   Node* newNode = new Node;
   newNode->data = data; 
   newNode->next = nullptr;
   return newNode;
}

//-----------------------------------
//Following will be all the insertion functions

//Insert at the beginning
void insertAtBeginning(Node*& head, int data){
   Node* newNode = createNode(data);
   newNode->next = head;
   head = newNode;
}

void insertAtEnd(Node*& head, int data){
   Node* newNode = createNode(data);

   //Checking if the list is empty. If list is empty make this new node head and return
   if(head == nullptr){
      head = newNode;
      return;
   }

   //if our list is not empty reach to the end of the list
   Node* current = head;
   while(current->next!= nullptr){
      current = current->next;
   }

   current->next = newNode;

}


void insertAfterValue(Node*& head, int data, int value){
   Node* newNode = createNode(data);

   Node* current = head;
   while( current != nullptr  && current->data != value){
      current = current->next;
   }

   //if we have reached the end
   if(current == nullptr){
      cout<< "Reached the end. Value passed wasn't found." <<endl;
      delete newNode;
      return;
   }

   
   //Pointing our current node to our new node
   newNode->next = current->next;
   current->next = newNode;

}

void insertAfterPosition(Node*& head, int data, int pos){
   Node* newNode = createNode(data);

   //if position is 0 make this node head
   if(pos == 0){
      newNode->next = head;
      head = newNode;
      return;
   }

   Node* current = head;
   int currentPosition = 0;
   while(current != nullptr && currentPosition < pos - 1){
      current = current->next;
      currentPosition++;
   }

   //if our current pointer is null
   if(current == nullptr){
      cout<< "Position "<< pos <<" is out of bounds!"<<endl;
      delete newNode;
      return;
   }

   //insert newNode
   newNode->next = current->next;
   current->next = newNode;

}

//----------------------------------

//Following are all deletion methods
void deleteNode(Node*& head , int key){
   //check if the list is empty
   if(head == nullptr){
      cout<< "List is empty"<<endl;
      return;
   }

   //If key is the head
   if(head->data == key){
      Node* temp = head;
      head = head->next;
      delete temp;
      return;
   }

   Node* current = head;
   Node* previous = nullptr;
   //finding the key node
   while(current != nullptr && current->data != key){
      previous = current;
      current = current->next;
   }

   if(current == nullptr){
      cout<<"Key " <<key <<" not found in the list" <<endl;
      return;
   }

   previous->next = current->next;
   delete current;
}

//method that prints all the nodes
void displayNodes(Node* head){
   Node* current = head;
   while(current != nullptr ){
      //printing the current value
      cout<< current->data << " -> ";
      //changing the current pointer to point at the next node
      current = current->next;
   }

   //after it has reached the end
   cout<< "nullptr" <<endl;
}

//method that finds the length of linked list
int findLength(Node* head){
   Node* current = head;
   int length = 0;

   while(current != nullptr){
      length++;
      current = current -> next;
   }

   return length;
}

int main(){
   Node* head = nullptr;
   
   insertAtBeginning(head,1);
   insertAtBeginning(head, 2);

   insertAfterValue(head, 5 , 1);

   insertAfterPosition(head, 5, 0);
   insertAfterPosition(head, 6, 2);
   displayNodes(head);

   deleteNode(head , 5);
   deleteNode(head,1);
   deleteNode(head, 10);
   displayNodes(head);
   cout<< findLength(head);
   return 0;
}
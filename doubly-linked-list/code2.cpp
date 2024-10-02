#include <iostream>
using namespace std;

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

//Insertion methods:
void insertAtBeginning(Node*& head, int data){
   Node* newNode = createNode(data);

   if(head == nullptr){
      head = newNode;
      return;
   }

   newNode->next = head;
   head->prev = newNode;
   head = newNode;
}

void insertAtEnd(Node*& head, int data){
   Node* newNode = createNode(data);

   if(head == nullptr){
      head = newNode;
      return;
   }

   Node* current = head;
   while(current->next != nullptr){
      current = current->next;
   }

   current->next = newNode;
   newNode->prev = current;
}

//inserting at a specific position
void insertAt(Node*& head, int data, int pos){
   Node* newNode = createNode(data);
   //if pos == head;
   if(pos == 0){
      insertAtBeginning(head, data);
      return;
   }

   Node* current = head;
   int currentPos = 0;
   while(current != nullptr && currentPos != pos){
      current = current->next;
      currentPos++;
   }

   //check if our current is nullptr. We have reached the end of list
   if(current == nullptr){
      cout << "Pos " << pos << " is out of bounds.\n";
      return;
   }

   newNode->next = current->next;

   //if currrent is tail
   if(current->next != nullptr){
      newNode->next->prev = newNode;
   }

   //insert at current position
   newNode->prev = current;
   current->next = newNode;
}


//inserting a node after a specific value
void insertAfter(Node*& head , int data, int value){
   Node* newNode = createNode(data);

   //find the node with value
   Node* current = head;
   while(current != nullptr && current->data != value){
      current = current->next;
   }

   if(current == nullptr){
      cout << "Value " << value << " is not in list\n";
      return; 
   }

newNode->next = current->next;

   //if currrent is tail
   if(current->next != nullptr){
      newNode->next->prev = newNode;
   }

   //insert at current position
   newNode->prev = current;
   current->next = newNode;
}

void insertBefore(Node*& head, int data, int value){
   Node* newNode = createNode(data);

   if(head->data == value){
      insertAtBeginning(head, data);
      return;
   }

   Node* current = head;
   while(current != nullptr && current->data != value){
      current = current->next;
   }

   //if current is not found
   if(current == nullptr){
      cout << "Value " << value << " not found in linked list\n";
      return;
   }

   //apend the new node
   newNode->prev = current->prev;
   current->prev->next = newNode;
   current->prev = newNode;
   newNode->next = current;

}

void deleteNode(Node*& head){
   if (head == nullptr){
      cout << "Linked list is empty\n";
      return;
   }

   if(head->next == nullptr){
      delete head;
      head = nullptr;
      return;
   }

   //delete the head
   Node* temp = head;
   head = head->next;
}

void deleteHead(Node*& head){
   Node* current = head;
   current->next->prev = nullptr;
   head = current->next;
   delete current;
}

void deleteNode(Node*& head, int value){
   if(head == nullptr){
      cout << "Linked list is empty\n";
      return;
   }
   
   //check if value is head
   if(head->data == value){
      deleteHead(head);
      return;
   }

   //find the node with value
   Node* current = head;
   while(current != nullptr && current->data != value){
      current = current->next;
   }

   //if current is null. Node with value is not found
   if(current == nullptr){
      cout << "Value " << value << " is not found\n";
      return;
   }

   if(current->next != nullptr){
      current->next->prev = current->prev;
   }

   current->prev->next = current->next;
   delete current;

}
//traversal
void displayNodes(Node* head){
   Node* current = head;

   if(head == nullptr){
      cout<<"Linked list is empty\n";
      return;
   }

   while (current != nullptr)
   {
      cout << current->data << " -> ";
      current = current->next;
   }

   cout << "nullptr\n";
   
}

void deleteDoublyLinkedList(Node*& head){
   Node* current = head;
   while(current != nullptr){
      Node* temp = current;
      current = current->next;
      delete current;
   }
   head = nullptr;
}


int findMiddle(Node* head){
   int len = 0;
   while(head->next != nullptr){
      len++;
   }
   return ++len / 2;
}

void reverseDoublyLinkedList(Node*& head){
   Node* current = head;
   while(current->next != nullptr){
      Node* temp = current;
      current = current->next;
      Node* x = temp->prev;
      temp->prev = temp->next;
      temp->next = x;
   }
   
   head = current;
   Node* temp = current;
   current = current->next;
   Node* x = temp->prev;
   temp->prev = temp->next;
   temp->next = x;
}
void swap(Node*& head, int val1, int val2){
   Node* v1 = nullptr;
   Node* v2 = nullptr;
   
   Node* current = head;
   while(current != nullptr){
      if(current->data == val1){
         v1 = current;
      }

      if(current->data == val2){
         v2 = current;
      }

      current = current->next;
   }

   if(v1 == nullptr || v2 == nullptr){
      cout <<"given values not found\n";
      return;
   }

   int temp = v1->data;
   v1->data = v2->data;
   v2->data = temp;
}
int main(){
   Node* head = nullptr;
   // insertAtBeginning(head , 20);
   // // displayNodes(head);

   // insertAtBeginning(head , 10);
   // // displayNodes(head);

   // insertAtEnd(head , 30);
   // // displayNodes(head);

   // insertAt(head, 50, 0);
   // // displayNodes(head);

   // insertAt(head , 60 , 3);
   // // displayNodes(head);

   // insertAt(head, 90, 3);
   // // displayNodes(head);

   // insertAt(head, 40, 9);

   // insertAfter(head, 45, 90);
   // // displayNodes(head);

   // // insertAfter(head , 90,50);
   // // displayNodes(head);

   // // insertAfter(head, 10, 999);
   // insertAfter(head, 69, 60);

   // insertBefore(head, 3, 45);
   // insertBefore(head,1, 50);
   // displayNodes(head);

   // // deleteHead(head);
   // // displayNodes(head);

   // // deleteNode(head, 50);
   // // cout << "Deleting head node\n";
   // // displayNodes(head);

   // // deleteNode(head,69);
   // // cout << "Deleting Tail node\n";
   // // displayNodes(head);

   // // deleteNode(head,3);
   // // cout << "Deleting 3rd node\n";
   // // displayNodes(head);

   // cout << "reversing list\n";
   // reverseDoublyLinkedList(head);
   // displayNodes(head);

   // cout << "swapping\n";
   // swap(head,45,30);
   // displayNodes(head);

   insertAtBeginning(head,9);
   insertAtBeginning(head,7);
   insertAtBeginning(head,5);
   insertAtBeginning(head,3);
   insertAtBeginning(head,1);
   displayNodes(head);
   
   cout << "reversing " << endl;
   reverseDoublyLinkedList(head);
   displayNodes(head);
   return 0;
}
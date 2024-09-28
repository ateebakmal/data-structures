#include <iostream>
#include <unordered_map>
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


void deleteBeforeValue(Node*& head, int value){

   //check if value is at head
   if(head->data == value){
      cout << "Head cannot be deleted\n";
      return;
   }

   if(head->next->data == value){
      Node* temp = head;
      head = head->next;
      delete temp;
   }

   Node* current = head;
   Node* prev = nullptr;

   while(current->next != nullptr && current->next->data != value){
      prev = current;
      current = current->next;
   }

   if(current == nullptr){
      cout<<"Value " <<value << " is out of bounds\n";
      return;
   }

   prev->next = current->next;
   delete current;
}

void deleteAfterValue(Node*& head, int value){

   
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

void mergeLists(Node*& head1, Node*& head2){
   //go to the end of current node
   Node* tail = head1;
   while(tail->next != nullptr){
      tail = tail->next;
   }

   Node* current = head2;
   while(current != nullptr){
      tail->next = current;
      tail = tail->next;
      current = current->next;
   }

}


void mergeTwoSortedLists(Node*& head1, Node*& head2){
   //if head1 is empty;
   if(head1 == nullptr){
      head1 = head2;
      return;
   }

   if(head2 == nullptr){
      return;
   }

   Node* dummy = createNode(0);
   Node* tail = dummy;

   Node* c1 = head1;
   Node* c2 = head2;

   //Keep adding nodes until one of the list is exhausted
   while(c1 != nullptr && c2 != nullptr){
      if(c1->data <= c2->data){
         tail->next = c1;
         c1 = c1->next;
         tail = tail->next;
      }else{
         tail->next = c2;
         c2 = c2->next;
         tail = tail->next;
      }
   }

   while( c1 != nullptr){
      tail->next = c1;
      c1 = c1->next;
      tail = tail->next;
   }

   while(c2 != nullptr){
      tail->next = c2;
      c2 = c2->next;
      tail = tail->next;
   }

   head1 = dummy->next;
   
   delete dummy;


}


int sum(Node* head, int currentSum){
   //base case
   if(head == nullptr){
      return currentSum;
   }

   currentSum += head->data;
   return sum(head->next, currentSum);
}

bool isPrime(int num){
   for(int i = 2; i <= num/2; i++){
      if(num % i == 0){
         return false;
      }
   }
   return true;
}
void removePrimes(Node*& head){
   //First move the head to where the head is not prime and delete all heads where head is prime

   while(head != nullptr && isPrime(head->data)){
      //deleting head
      Node* temp = head;
      head = head->next;
      delete temp;
   }

   //if after removing all heads with prime. If list is becomes empty
   if(head == nullptr){
      cout << "Linked list is empty\n";
   }

   Node* current = head->next;
   Node* prev = head;
   
   while(current != nullptr){
      if(isPrime(current->data)){
         Node* temp = current;
         prev->next = current->next;
         current = current->next;
         delete temp;
      }else{
         prev = current;
         current = current->next;
      }
   }
}


int findMiddleValue(Node* head){
   int length = 0;
   Node* current = head;
   while(current != nullptr){
      current = current->next;
      ++length;
   }

   int middlePos;
   if(length % 2 == 0){
      middlePos = length / 2 - 1;
   }else{
      middlePos = length / 2;
   }

   int pos = 0;
   current = head;
   while(pos != middlePos){
      current = current->next;
      ++pos;
   }

   return current->data;
}

int findMiddleNodePosition(Node* head){
   int length = 0;
   Node* current = head;
   while(current != nullptr){
      current = current->next;
      ++length;
   }

   int middlePos;
   if(length % 2 == 0){
      middlePos = length / 2 - 1;
   }else{
      middlePos = length / 2;
   }
   return middlePos;
}
Node* reverseFirstAndSecondHalf(Node*& head){
   int middlePos = findMiddleNodePosition(head);

   int pos = 0;
   
   Node* prev = nullptr;
   Node* forward = nullptr;
   Node* current = head;
   while(pos != middlePos+1){
      ++pos;
      forward = current->next;
      current->next = prev;
      prev = current;
      current = forward;
   }

   //We have reversed till the mid. Our prev is at middle Node that will be our new head so store it
   Node* newHead = prev;

   //reverse the remaining list similarly
   prev = nullptr;
   forward = nullptr;
   while(current != nullptr){
      forward = current->next;
      current->next = prev;
      prev = current;
      current = forward;
   }

   //Link the head to reversed list tail
   head->next = prev;
   return newHead;
}

void removeDuplicates(Node* head){
   unordered_map<int,int> dict;
   Node* prev = nullptr;
   Node* current = head;
   
   while(current != nullptr){
      //check if that value isnt already in dict. If it isnt in the dict add the value
      if(dict.find(current->data) == dict.end()){
         dict[current->data] = current->data;
         prev = current;
         current = current->next;

      }else{
         Node* temp = current;
         prev->next = current->next;
         current = current->next;
         delete temp;
      }
   }
}
int main(){
   Node* head = nullptr;
   
   insertAtEnd(head,1);
   insertAtEnd(head,1);
   insertAtEnd(head,2);
   insertAtEnd(head,2);
   insertAtEnd(head,3);
   insertAtEnd(head,4);
   insertAtEnd(head,5);
   insertAtEnd(head,5);

   // deleteBeforeValue(head,7);
   cout << "Linked List :\n";
   displayNodes(head);
   
   cout << "After removing duplicates : \n";
   removeDuplicates(head);
   displayNodes(head);

   // cout << "--------------------\n";
   // Node* head2 = nullptr;
   // insertAtEnd(head2,1);
   // insertAtEnd(head2,2);
   // insertAtEnd(head2,3);
   // insertAtEnd(head2,4);
   // insertAtEnd(head2,5);
   // insertAtEnd(head2,6);

   // cout << "Linked List 2:\n";
   // displayNodes(head2);
   // cout << "After reversing the both halfs:\n";
   // head2 = reverseFirstAndSecondHalf(head2);
   // displayNodes(head2);

   // twoSortedLists(head,head2);
   // cout<<"After merging: ";
   // displayNodes(head);
   
   return 0;
}
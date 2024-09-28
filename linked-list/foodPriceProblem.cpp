#include <iostream>
using namespace std;

struct groceryNode{
   string itemName;
   int price;
   groceryNode* next;
};

groceryNode* createNode(string name, int price){
   groceryNode* newNode = new groceryNode;
   newNode->itemName = name;
   newNode->price = price;
   newNode->next = nullptr;
   return newNode;

}
void insertAtHead(groceryNode*& head, string name, int price){
   groceryNode* newNode = createNode(name, price);

   newNode->next = head;
   head = newNode;
}

void insertAtEnd(groceryNode*& head , string name, int price){
   groceryNode* newNode = createNode(name,price);
   if(head == nullptr){
      head = newNode;
      return;
   }

   groceryNode* current = head;
   while(current->next != nullptr){
      current = current->next;
   }

   current->next= newNode;
}



int main(){

   groceryNode* head = nullptr;

   insertAtHead(head,"banana", 300);
   insertAtHead(head,"apple", 199);
   insertAtEnd(head, "eggs", 347);
   insertAtEnd(head, "bread", 350);
   insertAtEnd(head, "water", 70);
   insertAtEnd(head , "jam", 143);

   cout << "Original grocery list is: \n";
   displayNodes(head);

   cout << "----------------------------\n";
   cout << "Separating even priced groceries and odd prices groceries: \n";
   cout << "----------------------------\n";
   separateEvenAndOdd(head);
   return 0;
}
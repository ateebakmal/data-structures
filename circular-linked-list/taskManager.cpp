#include <iostream>

using namespace std;

class Task{
   public:
      string taskName;
      int priority;
      string status; //pending  , progress, completed
      Task* next; //pointer pointing towards next node

      Task(string taskName, int priority){
         this->taskName = taskName;
         this->priority = priority;
         this->status = "PENDING";
      }
};


class TaskSchedular{
   private: 
      Task* head;
      Task* tail;
      Task* current = this->head;

   public:
      TaskSchedular(){
         this->head = nullptr;
         this->tail = nullptr;
      }

      void addTask(string name, int priority){
         //this function inserts task at the end
         
         Task* newTask = new Task(name, priority);

         //check if head is empty
         if(!this->head){
            this->head = newTask;
            newTask->next = newTask;
            this->tail = newTask;
            return;
         }

         //if list is not empty. Add the node in the end
         newTask->next = head;
         tail->next = newTask;
         tail = newTask;

      }

      
      void removeTask(string name){
         //check if the task is at head
         if(this->head->taskName == name){
            //Edge case: check if head is the only node in your list
            if(this->head == this->tail){
               delete this->head; //delete the node
               this->head = nullptr; //make both pointers null
               this->tail = nullptr;
               return;
            }

            Task* temp = this->head;
            this->head = head->next;
            tail->next = head;
            delete temp;
            return;
         }

         Task* current = this->head;
         while(current->next != head && current->next->taskName != name){
            current = current->next;
         }


         //Edge case: check if current is at last node. We didnt find the task
         if(current == tail){
            cout << "Task '" << name << "' not founnd." << endl;
         }
         if(current->next == tail){
            current->next = head;
            tail = current;
            delete current->next;
         }else{
            current->next = current->next->next;
            delete current->next;
         }
      }

      void getCurrentTask(){
         if(this->current == nullptr){
            cout << "List is empty\n";
            return;
         }

         cout << "Current task : " << this->current->taskName << "\n";
      }

      void getNextTask(){
         //printing current task
         this->getCurrentTask();

         cout << endl;
         cout << "Going to next pending task" << endl;

         bool found = false;
         while(this->current->next != this->head){
            if(this->current->taskName == "pending"){
               found = true;
               break;
            }
            this->current = this->current->next;
         }

         if(found){
            cout << "\n";
            getCurrentTask();
         }else{
            cout << "\nDidn't find any pending task\n";
         }
      }

      void updateStatus(string taskName, string status){
         Task* current = this->head;
         //We will traverse till the tail
         while(current != tail && current->taskName != taskName){
            current = current->next;
         }

         //Check if our task is at tail and update it
         if(current->taskName == taskName){
            current->status = status;
            cout << "Updated status of '" << current->taskName << "' to '" << current->status <<"'" << endl;
            return;
         }

         if(this->current == current){
            this->getNextTask();
         }


         //we have reached the end and task is not found
         cout << "Task  '" << taskName << "' not found" << endl;
      }


      void display(){
         //Check if list is empty
         if(this->head == nullptr){
            cout << "Linked List is empty\n";
            return;
         }

         Task* current = head;
         while(current->next != head){
            cout << "{" << current->taskName << " : " << current->priority << " : " << current->status << "} -> ";
            current = current->next;
         }

         cout << "{" << current->taskName << " : " << current->priority << " : " << current->status << "} -> head" << endl;
         cout << endl;
      }
};

int main(){
   TaskSchedular assignments;

   assignments.addTask("DSA", 1);
   assignments.addTask("OOP",3);
   assignments.addTask("CALCULUS", 2);
   
   cout << "Printing all the tasks" << "\n";
   assignments.display();

   cout << endl;
   cout << "Updating status of DSA to completed\n";
   assignments.updateStatus("DSA","COMPLETED");
   assignments.display();

   cout << "Adding a new task\n";
   assignments.addTask("ASSINGMENT SUBMISSION",1);
   assignments.display();


   cout << "Removing DSA task" << endl;
   assignments.removeTask("DSA");
   assignments.display();

   cout << "Updating status ot ASSIGNMENT SUBMISSION to IN_PROGRESS" << endl;
   assignments.updateStatus("ASSINGMENT SUBMISSION", "IN_PROGRESS");
   assignments.display();

   return 0;
}

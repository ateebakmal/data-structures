#include <iostream>
using namespace std;

class Task {
public:
    string taskName;
    int priority;
    string status; // PENDING, IN_PROGRESS, COMPLETED
    Task* next;

    Task(string taskName, int priority) {
        this->taskName = taskName;
        this->priority = priority;
        this->status = "PENDING";
        this->next = nullptr;
    }
};

class TaskScheduler {
private:
    Task* head;
    Task* tail;
    Task* current;

public:
    TaskScheduler() {
        this->head = nullptr;
        this->tail = nullptr;
        this->current = nullptr;
    }

    void addTask(string name, int priority) {
        Task* newTask = new Task(name, priority);

        if (!this->head) {
            this->head = newTask;
            this->tail = newTask;
            newTask->next = newTask; // Circular link
            this->current = this->head; // Initialize current to head
        } else {
            newTask->next = this->head;
            this->tail->next = newTask;
            this->tail = newTask;
        }
    }

    void removeTask(string name) {
        if (!this->head) {
            cout << "No tasks to remove\n";
            return;
        }

        Task* temp = this->head;
        Task* prev = nullptr;

        if (this->head->taskName == name) {
            if (this->head == this->tail) { // Single task case
                delete this->head;
                this->head = nullptr;
                this->tail = nullptr;
                this->current = nullptr;
                return;
            }
            this->head = this->head->next;
            this->tail->next = this->head;
            delete temp;
            return;
        }

        while (temp->next != this->head && temp->taskName != name) {
            prev = temp;
            temp = temp->next;
        }

        if (temp->taskName == name) {
            if (temp == this->tail) {
                this->tail = prev;
                this->tail->next = this->head;
            } else {
                prev->next = temp->next;
            }
            delete temp;
        } else {
            cout << "Task '" << name << "' not found.\n";
        }
    }

    void getCurrentTask() {
        if (!this->current) {
            cout << "No current task.\n";
            return;
        }
        cout << "Current task: " << this->current->taskName << "\n";
    }

    void getNextTask() {
        if (!this->current) {
            cout << "No current task.\n";
            return;
        }

        cout << "Moving to next task with status PENDING...\n";
        Task* start = this->current;

        do {
            this->current = this->current->next;
            if (this->current->status == "PENDING") {
                cout << "Next pending task: " << this->current->taskName << "\n";
                return;
            }
        } while (this->current != start);

        cout << "No pending tasks found.\n";
    }

    void updateStatus(string taskName, string status) {
        Task* temp = this->head;
        if (!temp) {
            cout << "No tasks to update.\n";
            return;
        }

        do {
            if (temp->taskName == taskName) {
                temp->status = status;
                cout << "Updated status of '" << temp->taskName << "' to '" << temp->status << "'\n";
                return;
            }
            temp = temp->next;
        } while (temp != this->head);

        cout << "Task '" << taskName << "' not found.\n";
    }

    void display() {
        if (!this->head) {
            cout << "No tasks to display.\n";
            return;
        }

        Task* temp = this->head;
        do {
            cout << "{" << temp->taskName << " : " << temp->priority << " : " << temp->status << "} -> ";
            temp = temp->next;
        } while (temp != this->head);
        cout << "head\n";
    }
};

int main() {
    TaskScheduler scheduler;

    scheduler.addTask("DSA", 1);
    scheduler.addTask("OOP", 3);
    scheduler.addTask("CALCULUS", 2);
   
   cout << endl;
    cout << "Displaying all tasks:\n";
    scheduler.display();

   cout << endl;
    cout << "Adding a new task:\n";
    scheduler.addTask("ASSIGNMENT SUBMISSION", 1);
    scheduler.display();
   
   cout << endl;
   cout << "Getting current task:\n";
   scheduler.getCurrentTask();

   cout << endl;
   cout << "Moving to next pending task:\n";
   scheduler.getNextTask();

   cout << endl;
   cout << "Updating status "

    return 0;
}

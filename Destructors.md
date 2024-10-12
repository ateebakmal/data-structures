<p>
  In C++, destructors are special member functions of a class that are called automatically when an object of the class goes out of scope or is explicitly deleted. The primary purpose of a destructor is to release resources that were acquired during the lifetime of an object, such as dynamically allocated memory, file handles, or other system resources.
</p>

<h3>Syntax of a destructor: </h3>

<ul>
  <li>The destructor has the same name as the class, preceded by a tilde (~).</li>
  <li>It takes no arguments and has no return type.</li>
</ul>

<h3>Example</h3>

```cpp
    class MyClass {
public:
    MyClass() {
        // Constructor: called when an object is created
        cout << "Constructor called!" >> endl;
    }   
    ~MyClass() {
        // Destructor: called when the object is destroyed
        cout << "Destructor called!" >> endl;
    }
};
```

<h3>When does a constructor gets called</h3>
<ol>
  
  <li>
    <b>Object goes out of scope: <b>When an object goes out of scope (for example, at the end of a function), the destructor is called automatically to clean up the resources used by that object.

```cpp
void myFunction() {
MyClass obj; // Constructor is called here
// The object will go out of scope at the end of this function
} // Destructor will be called here
```    
  </li>

  <li>
    <b>Explicity calling <mark>delete</mark>:</b> When you use new to dynamically allocate memory for an object, you need to explicitly call delete to free that memory. When delete is called, the destructor of the object is automatically invoked.

```cpp
MyClass* obj = new MyClass(); // Constructor is called
delete obj;                   // Destructor is called
```

  </li>

  <li>
    <b>For global or static objects: </b>For global or static objects, destructors are called when the program exits.
  </li>
</ol>

<h3>Key Concepts: </h3>
<ol>
  <li>Automatic Cleanup</li>
  <p>The main purpose of destructors is to ensure proper cleanup of resources. If you allocate memory with new, open a file, or establish a network connection in a constructor, you should clean up those resources in the destructor.</p>


```cpp
class MyClass {
private:
    int* data; // Dynamically allocated memory

public:
    MyClass() {
        // Constructor: allocate memory
        data = new int[10];
        cout << "Memory allocated!" >> endl;
    }

    ~MyClass() {
        // Destructor: free memory
        delete[] data;
        cout << "Memory deallocated!" >> endl;
    }
};

int main() {
    MyClass obj; // Constructor is called, memory allocated
    // When obj goes out of scope, the destructor is called automatically
}
```

  <li>Destructor for a Class with Pointers:</li>
  <p>If your class manages dynamic memory (e.g., using new), you must delete that memory in the destructor to avoid memory leaks. Otherwise, if the object is destroyed without freeing that memory, it will lead to a memory leak.</p>

  <li>No Overloading:</li>
  <p>Unlike constructors, you cannot overload destructors. There can only be one destructor per class, and it takes no parameters.</p>

  <li>Order of Destructor Calls:</li>
  <p>For objects created in a function or a scope, destructors are called in the reverse order of their creation. This is known as LIFO (Last In, First Out) order.</p>

```cpp
    
 void myFunction() {
    MyClass obj1;
    MyClass obj2;
} // Destructor for obj2 is called first, then for obj1

```
  </ol>

<h3>Example with Destructors: </h3>

```cpp
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) : data(data), next(nullptr) {
        cout << "Node created with data: " << data << endl;
    }

    ~Node() {
        cout << "Node with data " << data << " is destroyed" << endl;
    }
};

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() : front(nullptr), rear(nullptr) {
        cout << "Queue created" << endl;
    }

   //Writing a destructotor to free up the dynamically allocated memory
    ¬Queue(){
        Node* temp = this->front;
        while(temp != nullptr){
            Node* next = temp->next;
            delete temp;
            temp = next;
         }
      }

    void enqueue(int data) {
        Node* newNode = new Node(data);
        if (rear == nullptr) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    void dequeue() {
        if (front == nullptr) {
            cout << "Queue is empty" << endl;
            return;
        }
        Node* temp = front;
        front = front->next;
        if (front == nullptr) {
            rear = nullptr;
        }
        delete temp;
    }
};

int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.dequeue();
    q.dequeue();

    // Queue is destructed here, and remaining nodes are deleted
    return 0;
}
```

<h3>Explanation:</h3>
<ol>
  <li><b>Node Destructor:</b> Each Node destructor is called when the Queue destructor deletes the nodes in the queue.</li>
  <li><b>Queue Destructor:</b> When the Queue object goes out of scope at the end of the main() function, its destructor is called automatically, ensuring all remaining nodes are deleted.</li>
</ol>

<h3>What Happens:</h3>
<ul>
When you enqueue items, nodes are dynamically created.
When you dequeue or when the queue object is destroyed, the destructor ensures that all nodes are properly deleted, preventing memory leaks.
</ul>

<h3>Why Use Destructors?</h3>
<ul>
  <li>To ensure automatic cleanup of resources (like dynamic memory or open files) when an object is no longer needed.</li>
  <li>Helps prevent memory leaks and resource exhaustion in programs that create and destroy objects frequently.</li>
</ul>

<h3>Question:</h3>
<h4><t>Does these nodes stay in my memory even after the program ends?</h2>
<p>
  No, the dynamically allocated nodes do not stay in memory after the program ends. When your program terminates, the operating system automatically reclaims all memory that was used by the program, including any memory that was leaked due to unfreed Node objects.
</p>
  
<h4>Key Points:</h4>

<ul>
  <li><b>During program execution: </b>If you don't free the memory for your nodes, they remain in memory while the program is running, leading to memory leaks.</li>
  <li><b>After program termination: </b>Once the program finishes and the process ends, the operating system will reclaim all the memory used by the program, including any unfreed dynamic memory.</li>
</ul>

<p>
  So, while memory leaks are problematic during the runtime of your program (as they can exhaust available memory), the memory is automatically cleaned up by the operating system when the program ends. However, it’s still important to properly manage memory to avoid leaks during the program’s execution.
</p>

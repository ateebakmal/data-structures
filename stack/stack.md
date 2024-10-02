#### What is Stack Data Structure?
Stack is a linear data structure based on LIFO(Last In First Out) principle in which the insertion of a new element and removal of an existing element takes place at the same end represented as the top of the stack.

To implement the stack, it is required to maintain the pointer to the top of the stack , which is the last element to be inserted because we can access the elements only on the top of the stack.

LIFO(Last In First Out) Principle in Stack Data Structure:
This strategy states that the element that is inserted last will come out first. You can take a pile of plates kept on top of each other as a real-life example. The plate which we put last is on the top and since we remove the plate that is at the top, we can say that the plate that was put last comes out first.

#### Types of Stack Data Structure:
- **Fixed Size Stack** : As the name suggests, a fixed size stack has a fixed size and cannot grow or shrink dynamically. If the stack is full and an attempt is made to add an element to it, an overflow error occurs. If the stack is empty and an attempt is made to remove an element from it, an underflow error occurs.
- **Dynamic Size Stack** : A dynamic size stack can grow or shrink dynamically. When the stack is full, it automatically increases its size to accommodate the new element, and when the stack is empty, it decreases its size. This type of stack is implemented using a linked list, as it allows for easy resizing of the stack.

- ### Basic Operations on Stack Data Structure:
In order to make manipulations in a stack, there are certain operations provided to us.

<table border="1">
        <tr>
            <th>Function</th>
            <th>Operation</th>
        </tr>
        <tr>
            <td>push()</td>
            <td>to insert an element into the stack</td>
        </tr>
        <tr>
            <td>pop()</td>
            <td>to remove an element from the stack</td>
        </tr>
        <tr>
            <td>top()</td>
            <td>Returns the top element of the stack.</td>
        </tr>
        <tr>
            <td>isEmpty()</td>
            <td>returns true if stack is empty else false.</td>
        </tr>
        <tr>
            <td>isFull()</td>
            <td>returns true if the stack is full else false.</td>
        </tr>
</table>

### Note:
There will be no isFull() function when implemented using linked list, Since there is no size limits in implementing linked lists.

### Read more about stacks at here : https://www.geeksforgeeks.org/introduction-to-stack-data-structure-and-algorithm-tutorials/?ref=outind 

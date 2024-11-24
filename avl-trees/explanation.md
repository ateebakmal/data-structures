
<h1>  Code Explanation: </h1>

<h2> Delete Method: </h2>

### 1. Edge Case: Reached the End of Tree (root == nullptr):

```cpp
if (root == nullptr) {
    return root;  // Correct: Handles the case when the key is not found or the tree is empty.
}
```
Handles the situation where the tree or subtree is empty or the key is not found. It stops the recursion appropriately.

### 2. Finding the Node to Delete:

You are using recursive traversal to locate the node to delete:
```cpp
if (key < root->data) {
    root->left = deleteHelper(root->left, key);
} else if (key > root->data) {
    root->right = deleteHelper(root->right, key);
}
```
This part of the code is correct and follows the logic of a Binary Search Tree (BST) to find the node.

### 3. Handling the Deletion (Found the Key): Once the node to be deleted is found, you correctly handle three scenarios:

- Node with No Children (Leaf Node):

```cpp
if (root->left == nullptr && root->right == nullptr) {
    Node* temp = root;
    root = nullptr;
    delete temp;
}
```
where you set the root to nullptr and delete the node.
#### Node with One Child:

- Left Child Only:

```cpp
else if (root->left != nullptr && root->right == nullptr) {
    Node* temp = root;
    root = root->left;
    delete temp;
}
```
You delete the node and replace it with its left child.
- Right Child Only:

```cpp
else if (root->left == nullptr && root->right != nullptr) {
    Node* temp = root;
    root = root->right;
    delete temp;
}
```
You delete the node and replace it with its right child.

- Node with Two Children:

```cpp
else {
    Node* minNode = this->minValueNode(root->right);  // Correct: Find the smallest node in the right subtree.
    root->data = minNode->data;                       // Replace the value.
    root->right = deleteHelper(root->right, minNode->data);  // Delete the in-order successor.
}
```
This handles the scenario where the node to be deleted has two children.
You correctly find the in-order successor (smallest in the right subtree), replace the current node’s data, and recursively delete the in-order successor.

### 4.Edge Case After Deletion: Subtree Becomes Empty:

```cpp
if (root == nullptr) {
    return root;
}
```
<b>Purpose:</b><br>
This line ensures that if after deletion the current subtree is completely empty, we return immediately without further processing.

<br><b>Why It's Needed:</b><br>
For example, if you delete the last remaining node in the entire tree, or if you delete a node such that the subtree rooted at that node is now empty, you need to return immediately.

<br><b>Execution Flow:</b><br>
When root becomes nullptr, it means the subtree is now empty, so there’s no need for further balancing or height updating.<br>

<br><b>Correct Use:</b> This line is correct and is a necessary base case after deletion.

### 5. Updating Heights and Getting Balance Factor:

- Update the Height:

```cpp
root->height = max(this->getHeight(root->left), this->getHeight(root->right)) + 1;
```
You update the height of the current node to ensure that it is updated after the deletion.
- Get Balance Factor:
```cpp
int balance = getBalance(root);
```
This step is to calculate the balance factor for the current node.

### 6.Checking for Imbalance and Applying Rotations:

- Left-Left (LL) Case:

```cpp
if (balance > 1 && getBalance(root->left) >= 0) {
    return rotateRight(root);
}
```
If the left subtree is heavier and the left child is balanced or left-heavy, perform a right rotation.

- Right-Right (RR) Case:

```cpp
if (balance < -1 && getBalance(root->right) <= 0) {
    return rotateLeft(root);
}
```
If the right subtree is heavier and the right child is balanced or right-heavy, perform a left rotation.

- Left-Right (LR) Case:

```cpp
if (balance > 1 && getBalance(root->left) < 0) {
    return rotateLeftRight(root);
}
```
If the left subtree is heavier and the left child is right-heavy, first perform a left rotation on the left child, followed by a right rotation on the current node.

- Right-Left (RL) Case:

```cpp
if (balance < -1 && getBalance(root->right) > 0) {
    return rotateRightLeft(root);
}
```

If the right subtree is heavier and the right child is left-heavy, first perform a right rotation on the right child, followed by a left rotation on the current node.

### 7.Returning the Root:

```cpp
return root;
```
This returns the updated root of the current subtree after deletion and any necessary rebalancing.

### Key Points to Note:
- **Edge Case Handling:**
The line if `(root == nullptr) return root;` after deletion ensures that if a deletion leaves the subtree empty, the function exits without trying to update heights or balance an empty node.

- **Balancing the Tree:**
Each case for rotations is correctly structured to handle different types of imbalance that may occur after deleting a node.

- **Correct Flow:**
The flow of operations—finding the node, deleting it, updating height, and balancing—is properly implemented, and each of the potential cases (no children, one child, two children) is handled without ambiguity.

//
// Created by ateeb on 19/11/2024.
//

#ifndef AVL_H
#define AVL_H
#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <queue>
using namespace std;
class Node
{
public:
    int data;
    int height;
    Node *left;
    Node *right;

    Node(int data){
        this->data = data;
        this->height = 1;
        this->left = this->right = nullptr;
    }


};

class AVL {
private:
        Node *root;
    int getHeight(Node* root){
        if(!root)
            return 0;
        return root->height;
    }
    int getBalance(Node* root){
        if(!root)
            return 0;
        return this->getHeight(root->left) - this->getHeight(root->right);
    }

    Node* minValueNode(Node* root){
        if(root->left == nullptr){
            return root;
        }
        return minValueNode(root->left);
    }

    //-------rotation methods
    Node* rotateRight(Node* root){
        Node* rootLeft = root->left;

        //Perform rotation
        root->left = rootLeft->right;
        rootLeft->right = root;

        root->height = max(this->getHeight(root->left), this->getHeight(root->right)) + 1;
        rootLeft->height = max(this->getHeight(rootLeft->left), this->getHeight(rootLeft->right)) + 1;

        //return the new root
        return rootLeft;
    }

    Node* rotateLeft(Node* root){

        Node* rootRight = root->right;

        //Perform rotation
        root->right = rootRight->left;
        rootRight->left = root;

        //Update heights
        root->height = max(this->getHeight(root->left), this->getHeight(root->right)) + 1;
        rootRight->height = max(this->getHeight(rootRight->left), this->getHeight(rootRight->right)) + 1;

        //return the new root
        return rootRight;


    }

    Node* rotateLeftRight(Node* root){
        root->left = rotateLeft(root->left);
        root = rotateRight(root);
        return root;
    }

    Node* rotateRightLeft(Node* root){
        root->right = rotateRight(root->right);
        root = rotateLeft(root);
        return root;
    }

    //-------------------------------------------------------------


    //----- Insert Method
    Node* insertHelper(Node* root, int data){

        //1. You have found the right place to add the node
        if(root == nullptr){
            return new Node(data);
        }

        if(data < root->data)
            root->left = insertHelper(root->left, data);
        else if(data > root->data)
            root->right = insertHelper(root->right, data);
        else
            return root; //Equal case - Duplicates are not allowed



        //2. Update height of each node
        root->height = 1 + max(this->getHeight(root->right), this->getHeight(root->left));

        //3. Get the balance factor
        int balance = getBalance(root);


        //Check if nodes become unbalanced

        //left left case (LL)
        if(balance > 1 && data < root->left->data){
            root = rotateRight(root);
            return root;
        }

        //Right Right Case (RR)
        if(balance < -1 && data > root->right->data){
            root = rotateLeft(root);
            return root;
        }


        //Left Right Case
        if(balance > 1 && data > root->left->data){
            root = rotateLeftRight(root);
            return root;
        }

        //Right Left Case
        if(balance < -1 && data < root->right->data){
            root = rotateRightLeft(root);
            return root;
        }

        return root;

    }

    //------------Deletion Method
    Node* deleteHelper(Node* root, int key){
        //Edge case: We reached the end of tree and haven't found the key
        if(root == nullptr){
            return root;#
        }

        //1) Find the node

            //WHERE TO GO TO?. IF KEY IS LESS THAN CURRENT NOTE. WE GO left
        if(key < root->data){

            root->left = deleteHelper(root->left, key);

        }else if(key > root->data){
            //IF KEY IS GREATER THAN CURRENT NOTE. WE GO Right
            root->right = deleteHelper(root->right, key);

        }else{
        // 2) We have found the  key node.

            //Now we have three cases here.

            //a. Node has no child
            if(root->left == nullptr && root->right == nullptr){
                Node* temp = root;
                root = nullptr;
                delete temp;
            }
            //b. Node has one child only.
                //Root has left child only
            else if(root->left != nullptr && root->right == nullptr){
                Node* temp = root;
                root = root->left;
                delete temp;
            }
                //Root has right child only
            else if(root->left == nullptr &&root->right != nullptr){
                Node* temp = root;
                root = root->right;
                delete temp;
            }

            //c. Root has both left and right children
            else{
                //i. Find the min node
                Node* minNode = this->minValueNode(root->right);

                //ii. Replace the values
                root->data = minNode->data;

                //iii. Delete the min node
                root->right = deleteHelper(root->right, minNode->data);
            }
        }

        //Edge Case: After deleting the node. Our sub-tree is empty

//         Why This Happens:
//              - When deleting a node, especially in scenarios where the deleted node is the only node in the subtree, the subtree may become empty.
//              - In such a case, root is set to nullptr to represent an empty subtree.
//              - This line is checking if the current root is nullptr (i.e., the subtree has become empty) and returns nullptr immediately, stopping further processing.

        if(root == nullptr){
            return root;
        }


        //3) Update the heights
        root->height = max(this->getHeight(root->left), this->getHeight(root->right)) + 1;

        //4) Get balance Factor
        int balance = getBalance(root);

        //Check if need to perform shifting

        //a. Left-Left Case
        if(balance > 1 && getBalance(root->left) >= 0){
            return rotateRight(root);
        }

        //b. Right-Right Case
        if(balance < -1 && getBalance(root->right) <= 0){
            return rotateLeft(root);
        }

        //c. Left Right Case
        if(balance > 1 && getBalance(root->left) < 0){
            return rotateLeftRight(root);
        }

        //d. Right Left Case
        if(balance <  -1 && getBalance(root->right) > 0){
            return rotateRightLeft(root);
        }

        return root;
    }

    //---- Method i got from chat-gpt to print an AVL Tree
    //Recursive helper to print all leaf nodes and number of leaf nodes
    void printTreeHelper(Node* node, string prefix, bool isRight) {
        if (node == nullptr) {
            return;
        }

        // Print the current node
        cout << prefix;
        cout << (isRight ? "+--- " : "|--- ");
        cout << node->data << endl;

        // Adjust the prefix for child nodes
        string newPrefix = prefix + (isRight ? "    " : "|   ");

        // Recurse to the left and right children
        printTreeHelper(node->left, newPrefix, false);  // Left child
        printTreeHelper(node->right, newPrefix, true);  // Right child
    }
public:
    AVL(){
        this->root = nullptr;
    }

    void insert(int data){
        this->root = insertHelper(this->root, data);
    }


    void printTree(){
        this->printTreeHelper(this->root, "", true);
    }

};



#endif //AVL_H

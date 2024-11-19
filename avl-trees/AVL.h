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

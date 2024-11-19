//
// Created by ateeb on 09/11/2024.
//

#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H
#include <iostream>
#include <queue>
using namespace std;
class BstNode
{
public:
    int data;
    BstNode* left;
    BstNode* right;

    BstNode(int data)
    {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class BinarySearchTree {
private:
    BstNode* root;

    BstNode* insertByRecursion(BstNode* root, int data){
        if(root == nullptr){
            return new BstNode(data);
        }

        if(data < root->data){
            root->left = insertByRecursion(root->left, data);
        }else if(data > root->data){
            root->right = insertByRecursion(root->right, data);
        }

        return root;
    }

    void preOrder(BstNode* root){
        if(root == nullptr)
            return;

        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }

    void postOrder(BstNode* root){
        if(root == nullptr)
            return;

        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << " ";
    }

    void inOrder(BstNode* root){
        if(root == nullptr)
            return;

        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }

    int findMin(BstNode* root){
        if(root->left == nullptr)
            return root->data;

        return findMin(root->left);
    }

    BstNode* deleteNode(BstNode* root, int data){
        if(root == nullptr)
            return nullptr;
        else if(data < root->data)
            root->left = deleteNode(root->left, data);
        else if(data > root->data)
            root->right = deleteNode(root->right, data);

        else if(data == root->data){
            if(root->left == nullptr && root->right == nullptr){
                delete root;
                root = nullptr;
            }else if(root->right == nullptr && root->left != nullptr ){
                BstNode* temp = root;
                root = root->left;
                delete temp;
            }else if(root->right != nullptr && root->left == nullptr){
                BstNode* temp = root;
                root = root->right;
                delete temp;
            }else{
                int min = findMin(root->right);
                root->data = min;
                root->right = deleteNode(root->right, min);
            }
        }

        return root;
    }


    //Recursive helper to print all leaf nodes and number of leaf nodes
    BstNode* printLeaves(BstNode* root, int& count){
        if(root->left == nullptr && root->right == nullptr){
            cout << root->data << " ";
            count++;
            return root;
        }

        if(root->left != nullptr)
            root->left = printLeaves(root->left, count);
        if (root->right != nullptr)
            root->right = printLeaves(root->right, count);

        return root;
    }

    // Recursive helper to print the tree
    void printTreeHelper(BstNode* node, string prefix, bool isRight) {
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
    BinarySearchTree()
    {
     root = nullptr;
    }

    bool isEmpty()
    {
        if(root == nullptr)
            return true;
        return false;
    }

    void insert(int data)
    {
        BstNode* temp = this->root;
        BstNode* newNode = new BstNode(data);

        if (temp == nullptr){
            this->root = newNode;
            return;
        }

        while(temp != nullptr){
            if (data < temp->data && temp->left == nullptr){
                temp->left = newNode;
                return;
            }
            else if (data < temp->data){
                temp = temp->left;
            }
            else if (data > temp->data && temp->right == nullptr){
                temp->right = newNode;
                return;
            }
            else if (data > temp->data){
                temp = temp->right;
            }
        }

    }

    void insertByRecursion(int data){
        this->root = this->insertByRecursion(this->root, data);
    }

    void preOrder(){
        preOrder(this->root);
        cout << endl;

    }

    void postOrder(){
        this->postOrder(this->root);
        cout << endl;
    }

    void inOrder(){
        this->inOrder(this->root);
        cout << endl;
    }

    void levelOrder(){
        queue<BstNode*> q;

        q.push(this->root);

        while(!q.empty()){
            BstNode* temp = q.front();
            q.pop();

            cout << temp->data << " ";

            if(temp->left != nullptr)
                q.push(temp->left);
            if(temp->right != nullptr)
                q.push(temp->right);

        }
    }

    int findMin(){
        return findMin(this->root);
    }

    void deleteNode(int data){
        this->root = deleteNode(this->root, data);
    }

    void printTree(){
        this->printTreeHelper(this->root, "", true);
    }

    void printLeaves(){
        int count = 0;
        this->root = this->printLeaves(this->root, count);
        cout << "\nCount : " << count << endl;
    }
};



#endif //BINARYSEARCHTREE_H

// Binary tree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<queue>
using namespace std;

class Node
{
    Node* left;
    Node* right;
    int key;
    friend class Tree;
};

class Tree
{
    Node* root;
public:
    Tree() { root = nullptr; }
    void insert(int key);
    void inorder(Node* p);
    void preorder(Node* p);
    void postorder(Node* p);
    Node* getRoot() const { return root; }
};

void Tree::insert(int key)
{
    Node* nuovoNodo = new Node;
    nuovoNodo->key = key;
    nuovoNodo->left = nuovoNodo->right = nullptr;
    if (root == nullptr)
        root = nuovoNodo;

    else
    {
        Node* current = root;
        Node* parent = nullptr;
        while (current!=nullptr)
        {
            parent = current;
            if (key < current->key)
                current = current->left;
            else
                current = current->right;
        }
        if (key < parent->key)
            parent->left = nuovoNodo;
        else // (key > parent->key&& current == nullptr)
            parent->right = nuovoNodo;
    }
}

void Tree::inorder(Node* p)
{
    if (p != nullptr)
    {
        inorder(p->left);
        cout << p->key << endl;
        inorder(p->right);
    }
}

void Tree::preorder(Node* p)
{
    if (p != nullptr)
    {
        cout << p->key;
        preorder(p->left);
        preorder(p->right);
    }
}

void Tree::postorder(Node* p)
{
    if (p != nullptr)
    {
        postorder(p->left);
        postorder(p->right);
        cout << p->key << endl;
    }
}

int main()
{
    Tree t;
    t.insert(6);
    t.insert(3);
    t.insert(8);
    t.inorder(t.getRoot());
    

}


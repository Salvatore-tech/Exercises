#include "tree.h"
#include<iostream>
using namespace std;
// 1  -3  5 -2 7 -3

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
        while (current != nullptr)
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


int Tree::minSearch(Node* p)
{
    Node* parent = nullptr;
    while (p != nullptr)
    {
        parent = p;
        p = p->left;
    }
    return parent->key;
}
/*
int Tree::minSearch(Node* p)
{
    if (p != nullptr)
        minSearch(p->left);
    else 
        return p->key;

    
}
*/
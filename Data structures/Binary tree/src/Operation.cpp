#include "tree.h"
#include<iostream>
using namespace std;
// 1  -3  5 -2 7 -3

void Tree::insert(int key)
{
    Node* nuovoNodo = new Node;
    nuovoNodo->key = key;
    nuovoNodo->left = nuovoNodo->right = nuovoNodo->parent = nullptr;
    Node* x = root;
    Node* y = nullptr;
    while (x != nullptr)
    {
        y = x;
        if (key < x->key)
            x = x->left;
        else
            x = x->right;
    }
    nuovoNodo->parent = y;
    if (y == nullptr)
        root = nuovoNodo;
    else if (nuovoNodo->key < nuovoNodo->parent->key)
        nuovoNodo->parent->left = nuovoNodo;
    else
        nuovoNodo->parent->right = nuovoNodo;
}


Node* Tree::maxSearch(Node* p)
{
    while (p->right != nullptr)
        p = p->right;
    return p;
}

Node* Tree::minSearch(Node* p)
{
    while (p->left != nullptr)
        p = p->left;
    return p;
}

//Il successore di un generico nodo v è il più piccolo nodo maggiore dello stesso
Node* Tree::successorSearch(Node* p)
{
    if (p->right != nullptr)
        return(minSearch(p->right));
    Node* y = p->parent;
    while (y != nullptr && p == p->parent->right)
    {
        Node* x = y;
        y = p->parent;
    }
    return y;
}

Node* Tree::predecessorSearch(Node* p)
{
    if (p->left != nullptr)
        return(maxSearch(p->left));
    Node* y = p->parent;
    while (y!=nullptr && p==p->parent->left)
    {
        Node* x = y;
        y = p->parent;
    }
    return y;
}

void Tree::trasplant(Node* u, Node* v)
{
    if (u->parent == nullptr)
        root = v;
    else if (u == u->parent->left)
        u->left->parent = v;
    else
        u->parent->right = v;
    if (v != nullptr)
        v->parent = u->parent;



}
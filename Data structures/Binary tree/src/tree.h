#pragma once
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
    int minSearch(Node* p);
    void inorder(Node* p);
    void preorder(Node* p);
    void postorder(Node* p);
    void levelorder(Node* p);
    int height(Node* p);
    void printLevel(Node* head, int level);
    void printAll(Node* head);
    Node* getRoot() const { return root; }
};
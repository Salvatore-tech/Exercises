#pragma once
using namespace std;


class Node
{
    Node* parent;
    Node* left;
    Node* right;
    int key;
    friend class Tree;
public:
    int getKey() { return this->key; };
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
    void levelorder(Node* p);
    int height(Node* p);
    void printLevel(Node* head, int level);
    void printAll(Node* head);
    Node* getRoot() const { return root; }

    Node* maxSearch(Node* p);
    Node* minSearch(Node* p);
    Node* successorSearch(Node* p);
    Node* predecessorSearch(Node* p);
    void trasplant(Node* u, Node* v);




    Node& operator++();
};



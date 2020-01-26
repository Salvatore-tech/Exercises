#include "tree.h"
#include<iostream>
#include<queue>
using namespace std;

/*
DFS visit: 
1) Inorder visit: Left->Root->Right
2) Preorder visit: Root->Left->Right
3) Postorder visit: Left->Right->Root
*/


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
/*Two types of level order (BFS for trees):
1) Queue based: push the root in the queue, print the data of the node, pop it and if it has children push them
2) Compute the height of the tree, print all the nodes at given level and repete for all the levels
*/
void Tree::levelorder(Node* p) // 1st type of level order
{
    if (p == nullptr)
        return;
    queue<Node*> q;
    q.push(root);
    while (!q.empty())
    {

        Node* app = q.front();
        cout << app->key << endl;
        q.pop();
        if (app->left != nullptr)
            q.push(app->left);
        if (app->right != nullptr)
            q.push(app->right);
    }
}

int Tree::height(Node* p) // 2) type of level order
{
    if (p == nullptr)
        return 0;
    int left_height = height(p->left);
    int right_height = height(p->right);
    if (left_height > right_height)
        return (left_height + 1);
    return (right_height + 1);
}

void Tree::printLevel(Node* p, int level)
{
    if (p == nullptr)
        return ;
    if (level == 0)
        cout << p->key << "\t";
    else if (level > 0)
    {
        printLevel(p->left, level - 1);
        printLevel(p->right, level - 1);
    }
}

void Tree::printAll(Node* t)
{
    int h = height(t);
    for (int i = 0; i <= h; i++)
    {
        printLevel(t, i);
        cout << endl;
    }
}
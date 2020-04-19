// Binary tree.cpp : 
//

#include <iostream>
#include<queue>
#include"tree.h"
using namespace std;


int main()
{
    Tree t;
    t.insert(6);
    t.insert(3);
    t.insert(8);
    t.insert(11);
    t.insert(5);
    t.insert(1);
    t.printAll(t.getRoot());
    cout << "\nL'elemento minimo del BST e': " << t.minSearch(t.getRoot()) << endl;





    for (Node n = ++t; &n!=NULL; n=++t)
        cout << "Successor print starting by the root: " << n.getKey() << endl;

}


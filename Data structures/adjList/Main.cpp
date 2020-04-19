#include<iostream>
#include <list>
#include <iterator>
#include <queue>
#include <vector>
#include <limits>
//#include "allocation.h"
using namespace std;


void* operator new(size_t size)
{
    cout << "\nAllocating" <<size <<" bytes" << endl;
    void* p = malloc(size);
    return p;
}
void operator delete(void* p)
{
    cout << "\nFreeing "<<sizeof(p)<< "bytes"<< endl;
    free(p);
}

class Node 
{
    bool color;
    Node* p;
    int d;
    char data;
    list<Node*>* adj;
public:
    Node(const char& data) { this->data = data; color = false; p = nullptr; d = std::numeric_limits<int>::max(); adj = new list<Node*>; }
    Node(const Node& other) : data(other.data), color(other.color), d(other.d), p(nullptr)
    {
        d++;
        adj = new list<Node*>;
        for (auto i:*other.adj)
            adj->emplace_back(new Node(*i));
        //memcpy(adj, other.adj, sizeof(other.adj));
    }
    /*~Node()
    {
        delete[] adj;
        cout << "Node destroyed" << endl;
    }
    */
    void addEdge(Node* w) { adj->push_back(w); }
    list<Node*>* getAdj() { return adj; }
    char getData() { return data; }
    void setColor(int c) { color = c;}
    int getColor() { return color; }
    void setP(Node* p) { this->p = p; }
    Node* getP() { return p; }
    void setD(int d) { this->d = d; }
    int getD() { return d; }
    friend class Graph;
};

class Graph
{
    vector<Node*>* adj;
protected:
    void DFS_helper(Node* s, vector<bool>* visited);
public:
    Graph() { adj = new vector<Node*>; }
    void addNode(Node* w) { adj->emplace_back(w); }
    Node* getNode(int v) { return adj->at(v); }
    void printAdj();
    void BFS(Node* s);
    void DFS(Node* s);
    //void DFS(Node s);
};

void Graph::BFS(Node* s) {
    queue<Node*> Q;
    s->color = true;
    s->d = 0;
    Q.push(s);
    while (!Q.empty())
    {
        Node extracted = *Q.front();
        cout << extracted.data << "\t"<<extracted.d<<endl;
        Q.pop();
        for (Node* i:*extracted.getAdj())
        {
            if (i->color == false)
            {
                i->color = true;
                (i->d)++;
                Q.push(i);
            }
            extracted.color = true;
        }
    }

    //Q.push();
    //Q.pop();
    s->color = false;
    s->d = numeric_limits<int>::max();
}
void Graph::DFS(Node* s) 
{
    Node t1 = *s;
    t1.color = true;
    cout << t1.data << endl;
    for (auto i : *t1.getAdj())
        if (i->color == false)
        {
            i->color = true;
           DFS(i);
        }
}


void Graph::printAdj() {
    for (auto v : *adj) {
        cout << "Adj(" << v->getData() << "):";
        for (auto vv : *v->getAdj())
            cout << " " << vv->getData();
        cout << endl;
    }
}

int main()
{
    Graph g;
    g.addNode(new Node('A'));//0
    g.addNode(new Node('B'));//1
    g.addNode(new Node('C'));//2
    g.addNode(new Node('D'));//3
    g.addNode(new Node('E'));//4
    g.addNode(new Node('F'));//5


    g.getNode(0)->addEdge(g.getNode(1));
    g.getNode(1)->addEdge(g.getNode(2));
    g.getNode(2)->addEdge(g.getNode(4));
    g.getNode(0)->addEdge(g.getNode(4));
    g.getNode(2)->addEdge(g.getNode(3));
    g.getNode(4)->addEdge(g.getNode(5));

    g.printAdj();
    g.DFS(g.getNode(0));
    cout << "\nSecond bfs" << endl;
    g.DFS(g.getNode(0));
    //g.DFS(g.getNode(0));
    /*g.BFS(g.getNode(0));
    g.BFS(g.getNode(0));*/
    return 0;
}

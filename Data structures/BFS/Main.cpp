#include <iostream>
#include <vector>
#include <queue>
#define NO_VERT 10
using namespace std;
typedef enum {white, grey, black} Color;

class Node
{
	Node* parent;
	int data;
	int distance;
	Color color;

	friend class Graph;
public:
	Node(int data)
	{
		parent = nullptr;
		color = white;
		distance = INT_MAX;
		this->data=data;
	}
};

class Graph
{
	vector<vector<Node>> adj;
	int no_vertices;
public:
	Graph(int no_vertices)
	{
		this->no_vertices = no_vertices;
		adj.resize(no_vertices);
	}

	void addEdge(int u, int v) 
	{
		adj[u].push_back(Node(v));
		adj[v].push_back(Node(u));
	}
	
	void print();
	void breadFirstSearch()
	{
		/*
		auto& source = adj[0];
		source.color = grey;
		source.at(0).distance = 0;
		//source(0, grey);
		queue<Node> q;
		q.push(source);
		vector<Node>::iterator i;
		while (!q.empty())
		{
			Node& estratto = q.front();
			cout << estratto.data << " ";
			q.pop();


		}
		*/
	}
	

};
void Graph::print()
{
	for (int i = 0; i < no_vertices; i++)
	{
		cout << "[" << i << "]";
		for (const auto& x : adj[i])
			cout << "\t" << x.data;
		cout << "\n";
	}
}



int main()
{
	int array[10];
	Graph g(NO_VERT);
	g.addEdge(0, 5);
	g.addEdge(0, 7);
	g.print();
	//g.breadFirstSearch();
	return 0;
}
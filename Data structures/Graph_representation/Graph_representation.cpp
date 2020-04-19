/* This is an exemple of a representation of undirected graph data structure based on array of list
   to keep track of the V
*/

#include <iostream>
#include <vector>
using namespace std;

class Graph
{
	int no_vertices;
	vector<int>* adj;
public:
	Graph(int no_vertices) { this->no_vertices = no_vertices;  adj = new vector<int>[no_vertices]; }
	void addEdge(int u, int v) { adj[u].push_back(v); adj[v].push_back(u); }
	void print();
};

void Graph::print()
{
	for (int i = 0; i < no_vertices; i++)
	{
		cout << "[" << i << "]";
		for (const auto& x : adj[i])
			cout << "\t" << x;
		cout << "\n";
	}
}

// Formula memorizzazione matrici zio cane
class GraphMatrix
{
	int no_vertices;
	int** matrix;
public:
	GraphMatrix(int no);
	void addEdge(int u, int v);
	void print();
};

GraphMatrix::GraphMatrix(int no)
{
	no_vertices = no;
	matrix = new int* [no_vertices];
	for (int i = 0; i < no_vertices; i++)
		for (int j=0; j<no_vertices; j++)
		*(matrix + (i*no_vertices)+j) = 0;
}

void GraphMatrix::print()
{
	for (int i = 0; i < no_vertices; i++)
	{
		cout << "\n";
		for (int j = 0; j < no_vertices; j++)
			cout <<*(matrix + (i * no_vertices) + j) << "\t";
	}
}

int main()
{
	/*
	
	Graph g(10);
	g.addEdge(1, 2);
	g.addEdge(1, 3);
	g.addEdge(1, 6);
	g.addEdge(7, 8);
	g.print();
	*/
	GraphMatrix g(10);
	g.print();
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

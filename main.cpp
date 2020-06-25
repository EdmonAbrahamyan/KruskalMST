// kruskalsMST.cpp : Defines the entry point for the console application.
//

#include "Graph.h"
#include <iostream>
using namespace std;

Graph*
sampleGraph()
{
	int n = 6;
	Node** v = new Node*[n];
	for (int i = 0; i < n; i++)
		v[i] = new Node(0, i, 0);

	int m = 9;
	Edge**  edges = new Edge*[m];

	edges[0] = new Edge(v[0], 7, v[1]);
	edges[1] = new Edge(v[0], 5, v[2]);
	edges[2] = new Edge(v[0], 10, v[4]);

	edges[3] = new Edge(v[1], 3, v[3]);
	edges[4] = new Edge(v[1], 2, v[5]);

	edges[5] = new Edge(v[2], 4, v[3]);
	edges[6] = new Edge(v[2], 8, v[4]);

	edges[7] = new Edge(v[3], 1, v[5]);

	edges[8] = new Edge(v[4], 9, v[5]);

	return new Graph(v, n, edges, m);
}


int main()
{
	Graph* graph = sampleGraph();
	cout << "***** INITIAL GRAPH *****" << endl;
	graph->print();
	
	Graph* mst = graph->kruskalsMST();
	cout << "***** THE MINIMUM SPANNING TREE *****" << endl;
	mst->print();

	system("pause");
	return 0;
}


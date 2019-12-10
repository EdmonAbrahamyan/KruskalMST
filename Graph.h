#pragma once
#include "Node.h"
#include "Edge.h"

class Graph {
	void sortEdges();
public:
	Graph(Node** vertices, int n, Edge**edges, int m);
	~Graph();
	Graph* kruskalsMST();
	void print()const;
private:
	Node**  vertices_;
	int		n_;		//number of vertices
	Edge**	edges_;
	int		m_;		//number of edges
};

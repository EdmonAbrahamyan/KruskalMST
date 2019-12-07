#pragma once
#include "Node.h"

class Edge
{
public:
	Node*	first_;
	int		weight_;
	Node*	second_;
	Edge(Node* first = 0, int weight = 0, Node* second = 0);
	~Edge();
};

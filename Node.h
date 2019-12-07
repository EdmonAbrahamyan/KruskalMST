#pragma once
class Node
{
public:
	Node*	parent_;
	int		element_;
	int		rank_;
	Node(Node* parent = 0, int element = 0, int rank = 0);
	~Node();
};

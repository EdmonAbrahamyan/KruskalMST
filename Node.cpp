#include "Node.h"

Node::Node(Node* parent, int element, int rank) :
	parent_(parent), element_(element), rank_(rank){}

Node::~Node(){}

#include "Edge.h"

Edge::Edge(Node* first, int weight, Node* second) :
	first_(first), weight_(weight), second_(second){}

Edge::~Edge(){}

#include "Graph.h"
#include <iostream>
using namespace std;


Graph::Graph(Node** vertices, int n, Edge**edges, int m) :
	vertices_(vertices), n_(n), edges_(edges), m_(m)
{
}

Graph::~Graph() {
	for (int j = 0; j < m_; j++)
		delete edges_[j];
	delete[]edges_;

	for (int i = 0; i < n_; i++)
		delete vertices_[i];
	delete[]vertices_;
}

void
make_set(Node* x)
{
	x->parent_ = x;
	x->rank_ = 0;
}

Node*
find_set(Node* x)
{
	if (x != x->parent_)
		x->parent_ = find_set(x->parent_);
	return x->parent_;
}

void
un_sets(Node* x, Node* y)
{
	Node* root1 = find_set(x);
	Node* root2 = find_set(y);

	if (root1->rank_ > root2->rank_)
		root2->parent_ = root1;
	else
	{
		root1->parent_ = root2;
		if (root1->rank_ == root2->rank_)
			root2->rank_++;
	}
}

void
Graph::sortEdges()  //insertionSort
{
	int		i, j;
	Edge*	ei;
	for (i = 1; i < m_; i++)
	{
		ei = edges_[i];
		j = i - 1;
		while (j >= 0 && edges_[j]->weight_ > ei->weight_)
		{
			edges_[j + 1] = edges_[j];
			j--;
		}
		edges_[j + 1] = ei;
	}
}

Graph*
Graph::kruskalsMST()
{
	Graph* G = new Graph(NULL, 0, NULL, 0);
	Edge** E = new Edge*();
	Node** V = new Node*[n_];
	int m = 0;
		for (int i = 0; i < n_; i++)
	{
		make_set(vertices_[i]);
	}
	sortEdges();
	for (int i = 0; i < m_; ++i)
	{
		if (find_set(edges_[i]->first_) != find_set(edges_[i]->second_)) 
		{
			E[m] = edges_[i];
			m++;
			un_sets(edges_[i]->first_, edges_[i]->second_);
		}
	}
	for (int i = 0; i < n_; ++i)
	{
		V[i] = new Node(0, i, 0);
	}
	G->edges_ = E;
	G->vertices_ = V;
	G->m_ = m;
	G->n_ = n_;
	return G;
}

void
Graph::print()const
{
	cout << endl << "VERTICES: ";
	for (int i = 0; i < n_; i++)
		cout << vertices_[i]->element_ << " ";
	cout << endl;

	cout << endl << "EDGES:" << endl;
	for (int j = 0; j < m_; j++)
	{
		cout << (edges_[j])->first_->element_ << ", ";
		cout << (edges_[j])->weight_ << ", ";
		cout << (edges_[j])->second_->element_ << endl;
	}
	cout << endl;
}

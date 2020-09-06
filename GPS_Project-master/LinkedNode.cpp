#include "LinkedNode.h"
#include "Node.h"
#include <vector>
#include <iostream>

LinkedNode::LinkedNode(){
	next=0;
	curr=0;	
}
LinkedNode::~LinkedNode()
{
	if (LinkedNode::next!=0){
		delete LinkedNode::next;
	}
}



void LinkedNode::addNode(Node* node, double newcost){
	LinkedNode* edge;
	edge->data = node;
	edge->cost = newcost;
	edge->next = 0;

	if (next!=0){
		size=1;
		curr=next;
		while(curr->next!=0){
			size++;
			curr=curr->next;
		}
		size++;
		curr->next=edge;
	}

	else{
		next=edge;
		size=1;
	}
}

std::vector<Node*> LinkedNode::getNeighbors(){
	LinkedNode* edge=next;
	std::vector<Node*> neighbors;	
	while(edge!=0){
		neighbors.push_back(edge->data);
		edge=edge->next;
	}
	return neighbors;
}

std::vector<double> LinkedNode::getCosts(){
	LinkedNode* edge=next;
	std::vector<double> costs;	

	while (edge!=0){
		costs.push_back(edge->cost);
		edge=edge->next;
	}
	return costs;
}

int LinkedNode::getSize(){
	return size;
}

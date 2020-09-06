#ifndef LINKEDNODE_H_EXISTS
#define LINKEDNODE_H_EXISTS
#include <string>
#include <cstring>
#include <fstream>
#include <iostream> 
#include <sstream>
#include <vector> 

class Node;



class LinkedNode{
	private:
		/*typedef*/// struct Edge{
		//	Node* data;
		//	double cost;
		//	Edge* next;
		//};
		//Edge* helm;
		LinkedNode* curr;
		LinkedNode* next;
		Node* data;
		double cost;
		int size;

	public:
		LinkedNode();
		~LinkedNode();
		std::vector<Node*> getNeighbors();
		std::vector<double> getCosts();
		int getSize();
		void addNode(Node* node, double newcost);			
};
#endif

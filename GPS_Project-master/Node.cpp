#include "Node.h"
#include "Edge.h"
#include <iostream>
//#include "LinkedNode.h"

Node::Node(){
	Node::NID;
	Node::Xcoord;
	Node::Ycoord;
	short_cost=999999999999;//high cost to be deleted
//	lneighbors=0;//makes the LinkedNode Null
}

Node::~Node(){
	//delete lneighbors;
}


void Node::setStats(std::string line){//sets the id x and y coord
	std::string NID, Xcoord, Ycoord;
	std::stringstream data, converter;
	data.clear();//clears data
	data<<line;//puts line into data
        std::getline(data, NID, ' ');//take the Node ID out of line into NID
	converter.clear();//clears converter
	converter<<NID;//puts NID into converter
	
	converter >> Node::NID;//converts NID into the node's NID
	//std::cout << "NID : " << Node::NID << std::endl;
        std::getline(data, Xcoord, ' ');
	converter.clear();
	converter<<Xcoord;
	converter>>Node::Xcoord;
        
	std::getline(data, Ycoord, ' ');
	converter.clear();
	converter<<Ycoord;
	converter>>Node::Ycoord;
}

void Node::makeNeighbors(Node* node/*, double cost*/){//puts the nodes that are neighbors into neighbors
	Node::neighbors.push_back(node);
	//Node::lneighbors->addNode(node, cost);
	
} 

void Node::setNCost(double cost){//makes the cost vector, to be replaced
	Node::costs.push_back(cost);
}


int Node::getNID(){
	return Node::NID;
}

void Node::getStats(){//checking neighbors for vector

	for(int i = 0; i < neighbors.size(); i++){
		std::cout << "Edge to Node: " << neighbors[i]->getNID();
		std::cout << "  cost: " << costs[i] << std::endl;


	}
}

bool Node::operator <(const Node& rhs){//overrides < to check node<node
	return Node::short_cost<rhs.short_cost; 
}

void Node::setPrev(Node* node){//to be implemented
	prev_node=node;
}

std::vector<Node*>* Node::getNeighbors(){//gives the vector of neighbors for a node
	//neighbors=lneighbors->getNeighbors();
	return &neighbors;
}

std::vector<double>* Node::getCosts(){//gives the vector of costs for a node
	//costs=lneighbors->getCosts();
	return &costs;
}
double Node::getShortCost(){//gets the current cost of the node
	return Node::short_cost;
}

void Node::setShortCost(double cost){//changes the cost of a node to the cost of the prev node + the cost to the node
	Node::short_cost=cost;
}

int Node::getPrevId(){//sends the id of the previous node back to main
	int ID=prev_node->getNID();//sets ID equal to the Node ID of prev
	return ID;//sends ID to main
}

Node* Node::getPrev(){//sends prev to main
	return prev_node;
}

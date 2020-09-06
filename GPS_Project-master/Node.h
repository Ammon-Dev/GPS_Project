#ifndef NODE_H_EXISTS
#define NODE_H_EXISTS
#include <string>
#include <cstring>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

//class LinkedNode;//setting for later

class Node{
	private:
		int NID;
		double Xcoord, Ycoord, short_cost;//short cost is the shortest cost of the path to this node
		std::vector<Node*> neighbors;//the list of neighbors
		std::vector<double> costs;//costs to get to the neighbors
		Node* prev_node;//to be implemented, the node connecting
		//LinkedNode* lneighbors;	//next step in the project
			
	public:
		Node();
		~Node();
		bool operator <(const Node& rhs);//allows Nodes to be compared
		/*void setNID(int ID);
		void setXcoord(double coord);
		void setYcoord(double coord);*/
		void setStats(std::string line);//sets NID, Xcoord, and Ycoord
		void makeNeighbors(Node* node/*, double cost*/);//Makes the nodes into a linked list
		int getNID();//gives NID to main
		void getStats();//gives NID, Xcoord, and Ycoord to main
		int getPrevId();//gives prev_node id to main
		Node* getPrev();//gives prev_node to main
		void setPrev(Node* node);//sets prev_node to a neighbor
		void setNCost(double cost);
		double getShortCost();//gets distance traveled to this node
		std::vector<double> * getCosts();//vector of costs
		std::vector<Node*> * getNeighbors();//vector of neighbors
		void setShortCost(double cost);//set distance traveled to this node
};
#endif

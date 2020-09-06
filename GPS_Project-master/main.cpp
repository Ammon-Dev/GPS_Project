#include <string>
#include <iostream>
#include <cstring>
#include <sstream>
#include <fstream>

#include <iomanip>
#include <map>
#include <set>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>
#include <cstdlib>

#include "Node.h"




int main(){
	Node* inter = new Node[18263]; // to be implemented DO NOT DELETE
	//Node* inter = new Node[7];
	std::ifstream inNFile, inEFile;
	inNFile.open("node.txt"); //to be implemented DO NOT DELETE
	inEFile.open("edge.txt"); //to be implemented DO NOT DELETE
	//inNFile.open("exnode.txt");
	//inEFile.open("example.txt");
	std::string line;
	/*
	for (int a=0; a<18263; a++){ to be implemented DO NOT DELETE, although change to while loop
                std::getline(inNFile, line);
                inter[a].setStats(line);
        }*/
	
	
	int a=0, b=0;
	while(std::getline(inNFile, line)){//example, just comment out DO NOT DELETE
	        inter[a].setStats(line);//make each node of the example
		a++;
	}

	std::stringstream hold, converter;
	std::string buffer, node1_str, node2_str, cost_str;
	int node1, node2, cost;
	while(std::getline(inEFile, line)){ //goes through each edge line	
		hold.str(line);  //
		
		std::getline(hold, buffer, ' ');//skips the first number in the line
		std::getline(hold, node1_str, ' ');//takes in the first node to be converted to an int
		converter << node1_str;
		converter >> node1;
		
		converter.clear();//always do this when you need to use this again

		converter.str("");//this too I guess
		std::getline(hold, node2_str, ' ');//second node
		converter << node2_str;
		converter >> node2;
		

		converter.clear();

		converter.str("");
		
		inter[node1].makeNeighbors(inter + node2);//makes node 2 the first neighbor in node 1
		inter[node2].makeNeighbors(inter + node1);//reverse above, to be changed
		
		std::getline(hold, cost_str, ' ');//the cost to be converted
		converter << cost_str;
		converter >> cost;
		
		//inter[node1].makeNeighbors(inter+node2, cost);
		//inter[node2].makeNeighbors(inter+node1, cost); 
		
		inter[node1].setNCost(cost); //puts the cost into a vector for each neighbor of a node
		inter[node2].setNCost(cost); //ditto

		converter.clear();
		converter.str("");
		
		
		
		//clear hold stringstream	
		hold.clear();
		hold.str("");
	}
	
	
	inNFile.close();//closes the ifstreams
	inEFile.close();
/*
	for(int i = 0; i < 7; i++){ 			//D's Algorithm
		std::cout << "Node : " << inter[i].getNID() << std::endl;

		inter[i].getStats();
		std::cout << "\n\n";

	}*/
	
	
	std::priority_queue <Node*, std::vector<Node*>, std::greater<Node*> > pq;//make the queue that takes in numbers and sorts them
	int start=0, end=5, size;//the start and finish
	double tempcost, nextcost, neighborcost;//cost of the node I'm on, cost to go to the neighbor node, cost currently on the neighbor
	Node* temp;//the node that we are on
	std::vector<Node*>* neighbors;	//neighbors of the node that we're on
	std::vector<double>* costs;  //cost to go to those neighbors
	// only for first node
	
	std::cout<<"Between 0 and 18262 where would you like to start?: ";
	std::cin>>start;
	std::cout<<"Between 0 and 18262 where would you like to end?: ";
	std::cin>>end;
	
	inter[start].setShortCost(0);//sets the short cost of the starting node to 0
	
	pq.push(inter + start);//pushes that starting node onto the queue
		
	std::cout << "start algorithm" << std::endl;	
	
	// Doing for every nodes	
	
	while(temp!=(inter + end)){//while we are not at our target value
		temp = pq.top();//puts the lowest node in the queue into temp
		pq.pop();//takes the lowest out of the queue

		neighbors=temp->getNeighbors();//puts temps neighbors into the neighbors vector
		costs=temp->getCosts();//does the same for costs

		//std::cout << "node " << temp->getNID()<<std::endl;//prints temps Id
		//std::cout << "neighbors size: " << neighbors->size()<<std::endl;//prints the size of the vector
		//std::cout << "costs size: " << costs->size()<<std::endl;//prints the size of the vector
		int size = neighbors->size();	//takes neighbors size
		for(int t=0;t<size;t++){//goes through each neighbor

			tempcost=temp->getShortCost();//gets the current cost of this node
			// DOuble dereference
			// (*costs) = value pointer is pointing to (actual vector)
			// (*costs)[i] = value at actual vector index i
			nextcost=(*costs) [t];//gets the cost to move to the neighbor
			neighborcost=(*neighbors)[t]->getShortCost();//gets the neighbors current cost


			if ((tempcost+nextcost)<neighborcost){//checks if the path going to a node is shorter than the current cost to get to that node
				(*neighbors)[t]->setShortCost(tempcost+nextcost);//if so this is now the path it will take and changes the cost
				pq.push((*neighbors)[t]);//puts this onto the queue to be sorted
				//(*neighbors)[t]->setPrev(temp);
			}
		}
	}
	
	
	std::cout <<"AND the shortest path issssss..... " <<  inter[end].getShortCost();//says the cost to get to the end point
	//Node* prev=new Node;//take in the node you come from
	//prev=inter[end].getPrev();//take in the previous node to the end
	//std::cout <<"The previous node is "<</*inter[end].getPrevId()*/prev->getNID()<<std::endl;//prints out the previous node
	////prev=inter[end].getPrev();//take in the previous node to the end
	//while(prev->getPrevId()!=start){//while you aren't back to start
	//	std::cout<<"Followed by "<<prev->getPrevId()<<std::endl;//prints out the node id previous to the node prev
	//	prev=prev->getPrev();//makes prev equal the node previous to it
	//}
	//std::cout<<"Starting with "<<prev->getPrevId()<<std::endl;//prints out the starting node
	delete [] inter;//deletes all nodes
	//delete prev;
}



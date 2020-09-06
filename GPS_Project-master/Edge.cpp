/*#include "Edge.h"
#include "Node.h"

//
void setEID(int ID){
	Edge::EID=ID;
}

void setN1ID(int ID){
	Edge::N1ID=ID
}

void setN2ID(int ID){
	Edge::N2ID=ID;
}

void setLength(std::string l){
	Edge::length=l;
}
//
Edge::Edge(){
	Edge::length;
	Edge::node = 0;
}
//

Edge::~Edge(){
}

void Edge::setStats(std::string line, Node Node[]){

	std::cout << "line: " << line << std::endl;
	std::string nEID, nN1ID, nN2ID, nlength;
	std::stringstream data, converter;
	//data.clear();
	
	data<<line;
	std::getline(data, nEID, ' ');

	std::cout << "nEID: " << nEID << std::endl;
	converter<<nEID;
	converter>>Edge::EID;


	std::getline(data, nN1ID, ' ');
	converter.clear();
	//converter.str("");

	
	std::cout << "nN1ID: " << nN1ID << std::endl;
	converter<<nN1ID;  
	converter>>Edge::N1ID;
	
	std::cout << "nN1ID: after conversion " << Edge::N1ID << std::endl;
	Edge::node1=&Node[Edge::N1ID];
	
	std::cout << "node1 ID :" << node1->getNID();
 
	std::getline(data, nN2ID, ' ');
	converter.clear();
	converter<<nN2ID;
	converter>>Edge::N2ID;
	Edge::node2=&Node[Edge::N2ID];

	//std::cout<<Edge::N2ID<<std::endl;
	std::getline(data, nlength, ' ');
	converter.clear();
	converter<<nlength;
	std::cout<<"length before convert: "<<nlength<<std::endl;
	converter>>Edge::length;
	std::cout<<"length after convert"<<Edge::length<<std::endl;
}

int Edge::getN1ID(){
	return Edge::N1ID;
}

int Edge::getN2ID(){
	return Edge::N2ID;
}

void Edge::check(){

	std::cout<<node1->getNID()<<std::endl;
	std::cout<<node2->getNID()<<std::endl;
	std::cout<<Edge::length<<std::endl;
}*/

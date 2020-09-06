map: main.o Node.o LinkedNode.o
	g++ -g main.o Node.o LinkedNode.o -o map

main.o: main.cpp Node.h Edge.h
	g++ -g -c main.cpp

Node.o: Node.cpp Node.h Edge.h LinkedNode.h
	g++ -g -c Node.cpp

LinkedNode.o: LinkedNode.cpp LinkedNode.h Node.h
	g++ -g -c LinkedNode.cpp

clean:
	rm *.o
	rm map

run: map
	./map

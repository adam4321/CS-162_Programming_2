
linkedList: linkedListMain.o Node.o listFunctions.o
	g++ -std=c++11 linkedListMain.o Node.o listFunctions.o -g -o linkedList

linkedListMain.o: linkedListMain.cpp
	g++ -std=c++11 -c linkedListMain.cpp

Node.o: Node.cpp Node.hpp
	g++ -std=c++11 -c Node.cpp

linkedList.o: listFunctions.cpp listFunctions.cpp
	g++ -std=c++11 -c listFunctions.cpp

clean:
	rm *.o linkedList

recursive: recursiveMain.o recursiveFunctions.o
	g++ recursiveMain.o recursiveFunctions.o -g -o recursive

recursiveMain.o: recursiveMain.cpp
	g++ -c recursiveMain.cpp

recursiveFunctions.o: recursiveFunctions.cpp
	g++ -c recursiveFunctions.cpp

clean: 
	rm *.o recursive
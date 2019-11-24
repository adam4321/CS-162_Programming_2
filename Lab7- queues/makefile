
queue: queueMain.o Queue.o
	g++ queueMain.o Queue.o -g -o queue

queueMain.o: queueMain.cpp
	g++ -c queueMain.cpp

Queue.o: Queue.cpp Queue.hpp
	g++ -c Queue.cpp

clean:
	rm *.o queue

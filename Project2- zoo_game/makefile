
zooTycoon: zooTycoonMain.o Animal.o Zoo.o Tiger.o Penguin.o Turtle.o
	g++ zooTycoonMain.o Animal.o Zoo.o Tiger.o Penguin.o Turtle.o -g -o zooTycoon

zooTycoonMain.o: zooTycoonMain.cpp
	g++ -c zooTycoonMain.cpp

Animal.o: Animal.cpp Animal.hpp
	g++ -c Animal.cpp

Zoo.o: Zoo.cpp Zoo.hpp
	g++ -c Zoo.cpp

Tiger.o: Tiger.cpp Tiger.hpp
	g++ -c Tiger.cpp

Penguin.o: Penguin.cpp Penguin.hpp
	g++ -c Penguin.cpp

Turtle.o: Turtle.cpp Turtle.hpp
	g++ -c Turtle.cpp

clean:
	rm *.o zooTycoon

simulation: simulationMain.o Critter.o Ant.o Doodlebug.o
	g++ -std=c++11 simulationMain.o Critter.o Ant.o Doodlebug.o -g -o simulation

simulationMain.o: simulationMain.cpp
	g++ -std=c++11 -c simulationMain.cpp

Critter.o: Critter.cpp Critter.hpp
	g++ -std=c++11 -c Critter.cpp

Ant.o: Ant.cpp Ant.hpp
	g++ -std=c++11 -c Ant.cpp

Doodlebug.o: Doodlebug.cpp Doodlebug.hpp
	g++ -std=c++11 -c Doodlebug.cpp

clean:
	rm *.o simulation
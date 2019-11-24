
langtonAnt: langtonAntMain.o Menu.o Ant.o 
	g++ langtonAntMain.o Menu.o Ant.o -g -o langtonAnt

langtonAntMain.o: langtonAntMain.cpp
	g++ -c langtonAntMain.cpp

Ant.o: Ant.cpp Ant.hpp
	g++ -c Ant.cpp

Menu.o: Menu.cpp Menu.hpp
	g++ -c Menu.cpp

clean: 
	rm *.o langtonAnt

warGame: warGameMain.o Game.o Die.o LoadedDie.o
	g++ warGameMain.o Game.o Die.o LoadedDie.o -g -o warGame

warGameMain.o: warGameMain.cpp
	g++ -c warGameMain.cpp

Game.o: Game.cpp Game.hpp
	g++ -c Game.cpp

Die.o: Die.cpp Die.hpp
	g++ -c Die.cpp

LoadedDie.o: LoadedDie.cpp LoadedDie.hpp
	g++ -c LoadedDie.cpp

clean:
	rm *.o warGame
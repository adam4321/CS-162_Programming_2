
fantasyCombat: fantasyCombatMain.o Character.o Vampire.o Barbarian.o Blue_Men.o Medusa.o Harry_Potter.o
	g++ -std=c++11 fantasyCombatMain.o Character.o Vampire.o Barbarian.o Blue_Men.o Medusa.o Harry_Potter.o -g -o fantasyCombat

fantasyCombatMain.o: fantasyCombatMain.cpp
	g++ -std=c++11 -c fantasyCombatMain.cpp

Character.o: Character.cpp Character.hpp
	g++ -std=c++11 -c Character.cpp

Vampire.o: Vampire.cpp Vampire.hpp
	g++ -std=c++11 -c Vampire.cpp

Barbarian.o: Barbarian.cpp Barbarian.hpp
	g++ -std=c++11 -c Barbarian.cpp

Blue_Men.o: Blue_Men.cpp Blue_Men.hpp
	g++ -std=c++11 -c Blue_Men.cpp

Medusa.o: Medusa.cpp Medusa.hpp
	g++ -std=c++11 -c Medusa.cpp

Harry_Potter.o: Harry_Potter.cpp Harry_Potter.hpp
	g++ -std=c++11 -c Harry_Potter.cpp

clean: 
	rm *.o fantasyCombat
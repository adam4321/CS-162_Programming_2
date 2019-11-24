
tournament: tournamentMain.o Character.o Vampire.o Barbarian.o Blue_Men.o Medusa.o Harry_Potter.o Queue.o
	g++ -std=c++11 tournamentMain.o Character.o Vampire.o Barbarian.o Blue_Men.o Medusa.o Harry_Potter.o Queue.o -g -o tournament

tournamentMain.o: tournamentMain.cpp
	g++ -std=c++11 -c tournamentMain.cpp

Queue.o: Queue.cpp Queue.hpp
	g++ -std=c++11 -c Queue.cpp

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
	rm *.o tournament
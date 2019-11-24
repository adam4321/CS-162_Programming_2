
countLetters: letterCounterMain.o letterFunctions.o
	g++ -std=c++11 -g letterCounterMain.o letterFunctions.o -o countLetters

letterCounterMain.o: letterCounterMain.cpp
	g++ -std=c++11 -c letterCounterMain.cpp

letterFunctions.o: letterFunctions.cpp letterFunctions.hpp
	g++ -std=c++11 -c letterFunctions.cpp

clean:
	rm *.o countLetters
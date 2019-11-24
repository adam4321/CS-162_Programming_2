
compareTime: compareMain.o recursiveFib.o iterativeFib.o
	g++ -std=c++11 compareMain.o recursiveFib.o iterativeFib.o -g -o compareTime

compareMain.o: compareMain.cpp
	g++ -std=c++11 -c compareMain.cpp 

recursiveFib.o: recursiveFib.hpp recursiveFib.cpp
	g++ -std=c++11 -c recursiveFib.cpp

iterativeFib.o: iterativeFib.hpp iterativeFib.cpp
	g++ -std=c++11 -c iterativeFib.cpp

clean:
	rm *.o compareTime
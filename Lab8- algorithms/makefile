
searchSort: searchSortMain.o algorithms.o
	g++ -std=c++11 searchSortMain.o algorithms.o -g -o searchSort

searchSortMain.o: searchSortMain.cpp
	g++ -std=c++11 -c searchSortMain.cpp

algorithms.o: algorithms.cpp algorithms.hpp
	g++ -c algorithms.cpp

clean: 
	rm *.o searchSort
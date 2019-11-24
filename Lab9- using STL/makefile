
templates: templateMain.o functions.o
	g++ templateMain.o functions.o -g -o templates

templateMain.o: templateMain.cpp
	g++ -c templateMain.cpp

functions.o: functions.hpp functions.cpp
	g++ -c functions.cpp

clean:
	rm *.o templates
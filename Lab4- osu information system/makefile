
osuInfo: osuInfoMain.o Person.o Student.o Instructor.o University.o Building.o
	g++ -std=c++11 osuInfoMain.o Person.o Student.o Instructor.o University.o Building.o -g -o osuInfo

osuInfoMain.o: osuInfoMain.cpp
	g++ -std=c++11 -c osuInfoMain.cpp

Person.o: Person.cpp
	g++ -std=c++11 -c Person.cpp

Student.o: Student.cpp
	g++ -std=c++11 -c Student.cpp

Instructor.o: Instructor.cpp
	g++ -std=c++11 -c Instructor.cpp

University.o: University.cpp
	g++ -std=c++11 -c University.cpp

Building.o: Building.cpp
	g++ -std=c++11 -c Building.cpp

clean:
	rm *.o osuInfo
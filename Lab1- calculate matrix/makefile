
matrixCalculate: calculateMatrixMain.o readMatrix.o determinant.o
	g++ calculateMatrixMain.o readMatrix.o determinant.o -o matrixCalculate

calculateMatrixMain.o: calculateMatrixMain.cpp
	g++ -c calculateMatrixMain.cpp

readMatrix.o: readMatrix.cpp readMatrix.hpp
	g++ -c readMatrix.cpp
	
determinant.o: determinant.cpp determinant.hpp
	g++ -c determinant.cpp

clean: 
	rm *.o matrixCalculate
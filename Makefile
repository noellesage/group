all: output

output: main.o ant.o board.o critter.o doodlebug.o intVal.o menu.o
	g++ -std=c++11 main.o ant.o board.o critter.o doodlebug.o intVal.o Menu.o -o output
main.o: main.cpp
	g++ -std=c++11 -c main.cpp
ant.o: ant.cpp ant.hpp
	g++ -std=c++11 -c ant.cpp
board.o: board.cpp board.hpp
	g++ -std=c++11 -c board.cpp
critter.o: critter.cpp critter.hpp
	g++ -std=c++11 -c critter.cpp
doodlebug.o: doodlebug.cpp doodlebug.hpp
	g++ -std=c++11 -c doodlebug.cpp
intVal.o: intVal.cpp intVal.hpp
	g++ -std=c++11 -c intVal.cpp
Menu.o: Menu.cpp Menu.hpp
	g++ -std=c++11 -c Menu.cpp
clean:
	rm *.o output

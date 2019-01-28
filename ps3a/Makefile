all: NBody

NBody: Body.o main.o
	g++ Body.o main.o -o NBody -lsfml-graphics -lsfml-window -lsfml-system

Body.o: Body.cpp Body.hpp
	g++ -c Body.cpp -Wall -ansi -pedantic -std=c++0x

main.o: main.cpp Body.hpp
	g++ -c main.cpp -Wall -ansi -pedantic -std=c++0x

clean:
	rm NBody *.o

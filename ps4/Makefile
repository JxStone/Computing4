all: ED

ED: main.o ED.o
	g++ -g -o ED main.o ED.o -lsfml-system

main.o: main.cpp ED.hpp
	g++ -g -c main.cpp -Wall -ansi -pedantic -std=c++0x

ED.o: ED.cpp ED.hpp
	g++ -g -c ED.cpp -Wall -ansi -pedantic -std=c++0x

clean:
	rm *.o ED

all: PhotoMagic

PhotoMagic: PhotoMagic.o LFSR.o
	g++ PhotoMagic.o LFSR.o -o PhotoMagic -std=c++0x -lsfml-graphics -lsfml-window -lsfml-system

PhotoMagic.o: PhotoMagic.cpp LFSR.hpp
	g++ -c PhotoMagic.cpp -Wall -ansi -pedantic -std=c++0x

LFSR.o: LFSR.cpp LFSR.hpp
	g++ -c LFSR.cpp -Wall -ansi -pedantic

clean:
	rm *.o PhotoMagic


all:sierpinski original

sierpinski: main.o sierpinski.o
	g++ main.o sierpinski.o -o sierpinski -lsfml-graphics -lsfml-window -lsfml-system
main.o: main.cpp
	g++ -c main.cpp -Wall -Werror -std=c++0x -pedantic
sierpinski.o: sierpinski.cpp sierpinski.hpp
	g++ -c sierpinski.cpp -Wall -Werror -std=c++0x -pedantic
original: main_original.o original.o
	g++ main_original.o original.o -o original -lsfml-graphics -lsfml-window -lsfml-system
main_original.o: main_original.cpp
	g++ -c main_original.cpp -Wall -Werror -std=c++0x -pedantic
original.o: original.cpp original.hpp
	g++ -c original.cpp -Wall -Werror -std=c++0x -pedantic
clean:
	rm *.o sierpinski original *~

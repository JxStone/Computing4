ps2a: test.o LFSR.o
	g++ test.o LFSR.o -o ps2a -lboost_unit_test_framework -std=c++0x

test.o: test.cpp
	g++ -c test.cpp -Wall -Werror -ansi -pedantic -std=c++0x

LFSR.o: LFSR.cpp LFSR.hpp
	g++ -c LFSR.cpp -Wall -Werror -ansi -pedantic

clean:
	rm *.o ps2a

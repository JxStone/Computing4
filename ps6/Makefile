all: TextGenerator mmtest

mmtest: MarkovModel.o mmtest.o
	g++ -o mmtest MarkovModel.o mmtest.o -lboost_unit_test_framework

mmtest.o: mmtest.cpp MarkovModel.hpp
	g++ -c -g mmtest.cpp -Wall -ansi -pedantic

TextGenerator: TextGenerator.o MarkovModel.o
	g++ -o TextGenerator TextGenerator.o MarkovModel.o -lboost_unit_test_framework

TextGenerator.o: TextGenerator.cpp MarkovModel.hpp
	g++ -c -g TextGenerator.cpp -Wall -ansi -pedantic

MarkovModel.o: MarkovModel.cpp MarkovModel.hpp
	g++ -c -g MarkovModel.cpp -Wall -ansi -pedantic

clean:
	rm *.o TextGenerator mmtest

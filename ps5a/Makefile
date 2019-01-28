all: ps5a

ps5a: test.o RingBuffer.o
	g++ -o ps5a test.o RingBuffer.o -lboost_unit_test_framework
test.o: test.cpp RingBuffer.hpp
	g++ -c test.cpp -Wall -ansi -pedantic
RingBuffer.o: RingBuffer.cpp RingBuffer.hpp
	g++ -c RingBuffer.cpp -Wall -ansi -pedantic
clean:
	rm *.o ps5a
all: ps7a

ps7a: main.o InTouchDeviceStartUp.o
	g++ -o ps7a InTouchDeviceStartUp.o main.o -lboost_regex -lboost_date_time

main.o: main.cpp InTouchDeviceStartUp.hpp
	g++ -c main.cpp -Wall -ansi -pedantic

InTouchDeviceStartUp.o: InTouchDeviceStartUp.cpp InTouchDeviceStartUp.hpp
	g++ -c InTouchDeviceStartUp.cpp -Wall -ansi -pedantic

clean:
	rm *.o ps7a

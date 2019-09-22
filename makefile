CFLAGS = -O
CC = g++

driver: valueIteration.o
	$(CC) $(CFLAGS) -o driver valueIteration.o state.o --std=c++11

valueIteration.o: state.o valueIteration.cpp
	$(CC) $(CFLAGS) -c valueIteration.cpp --std=c++11

state.o: state.h state.cpp
	$(CC) $(CFLAGS) -c state.cpp --std=c++11

run:
	./driver

clean:
	rm -f driver *.o

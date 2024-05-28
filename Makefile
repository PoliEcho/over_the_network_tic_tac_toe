
all: main.o net.o
	g++ main.o net.o -o over_the_network_tic_tac_toe

main.o: main.cpp
	g++ -c main.cpp

net.o: net.cpp
	g++ -c net.cpp
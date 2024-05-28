

all: build/obj/main.o build/obj/net.o build/obj/input.o
	g++ build/obj/main.o build/obj/net.o build/obj/input.o -o build/bin/over_the_network_tic_tac_toe

build/obj/main.o: src/main.cpp
	g++ -c src/main.cpp -o build/obj/main.o

build/obj/net.o: src/net.cpp
	g++ -c src/net.cpp -o build/obj/net.o

build/obj/input.o: src/input.cpp
	g++ -c src/input.cpp -o build/obj/input.o

clean:
	rm build/obj/*
	rm build/bin/*
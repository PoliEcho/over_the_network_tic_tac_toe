CC = g++
CC_FLAGS =

all: build/bin/over_the_network_tic_tac_toe

build/bin/over_the_network_tic_tac_toe: build/obj/main.o build/obj/net.o build/obj/input.o build/obj/gameplay.o
	$(CC) $(CC_FLAGS) build/obj/main.o build/obj/net.o build/obj/input.o build/obj/gameplay.o -o build/bin/over_the_network_tic_tac_toe

build/obj/main.o: src/main.cpp
	mkdir -p build/obj
	mkdir -p build/bin
	$(CC) $(CC_FLAGS) -c src/main.cpp -o build/obj/main.o

build/obj/net.o: src/net.cpp
	$(CC) $(CC_FLAGS) -c src/net.cpp -o build/obj/net.o

build/obj/input.o: src/input.cpp
	$(CC) $(CC_FLAGS) -c src/input.cpp -o build/obj/input.o

build/obj/gameplay.o: src/gameplay.cpp
	$(CC) $(CC_FLAGS) -c src/gameplay.cpp -o build/obj/gameplay.o

clean:
	rm -fr build
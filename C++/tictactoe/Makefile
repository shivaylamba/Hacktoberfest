CC		=		g++
CCFLAGS	=		-c -O2 -I include/

build: src/tictactoe.cpp src/board.cpp
	mkdir build
	$(CC) src/tictactoe.cpp $(CCFLAGS) -o build/tictactoe.o
	$(CC) src/board.cpp $(CCFLAGS) -o build/board.o
	

	$(CC) build/tictactoe.o build/board.o -o build/tictactoe

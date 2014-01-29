CC = g++
FLAGS = -c
LIBS = -lSDLmain -lSDL -lGL -lglut
SOURCES = main.cpp block.cpp tttWorld.cpp players.cpp
HEADERS = block.h tttWorld.h players.h
GLOBALS = headers.h globals.h
OBJECTS = $(SOURCES:.cpp=.o)

all: TicTacToe

TicTacToe: $(OBJECTS)
	$(CC) $(OBJECTS) $(LIBS) -o $@ 

main.o: main.cpp tttWorld.h $(GLOBALS)
	$(CC) $(FLAGS) main.cpp $(LIBS)

block.o: block.cpp block.h $(GLOBALS)
	$(CC) $(FLAGS) block.cpp $(LIBS)

tttWorld.o: tttWorld.cpp $(HEADERS) $(GLOBALS)
	$(CC) $(FLAGS) tttWorld.cpp $(LIBS)

players.o: players.cpp players.h $(GLOBALS)
	$(CC) $(FLAGS) players.cpp $(LIBS)

clean: 
	rm -rf *o TicTacToe
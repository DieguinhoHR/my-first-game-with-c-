BIN = ./bin
INCLUDE = ./include
SRC = ./src

all:	
	g++ -o ./bin/main ${SRC}/*.cpp `pkg-config --cflags --libs sdl2` && ./bin/main
run:
	./bin/main
clean:
	rm $(BIN)/*
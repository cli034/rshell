COMPILE = g++
FLAGS = -Wall -Werror -ansi -pedantic
OBJS = ./src/basecmd.cpp ./src/connector_composites.cpp ./src/functions.cpp ./src/leafcmd.cpp

all:
	mkdir -p ./bin
	$(COMPILE) $(FLAGS) ./src/main.cpp -o ./bin/rshell $(OBJS)

main: main.cpp basecmd.o connector_composites.o functions.o leafcmd.o
	$(COMPILE) $(FLAGS) ./src/main.cpp
	
basecmd: Basecmd.cpp Basecmd.h
	$(COMPILE) -c $(FLAGS) ./src/basecmd.cpp

cmd: leafcmd.cpp leafcmd.h
	$(COMPILE) -c $(FLAGS) ./src/leafcmd.cpp

connector: connector_composites.cpsp connector_composites.h
	$(COMPILE) -c $(FLAGS) ./src/connector_composites.cpp

functions: functions.cpp functions.h
	$(COMPILE) -c $(FLAGS) ./src/functions.cpp

clean:
	rm -rf ./bin


CC_FLAGS := -Wall -Wextra -g -O0
CC_INCLUDES :=-I .
CC := gcc ${CC_FLAGS} ${CC_INCLUDES}
TARGET_BIN := main

all: main.o network.o sender.o receiver.o
	gcc main.o network.o sender.o receiver.o -o ${TARGET_BIN}

main.o: main.c network.c network.h sender.c sender.h receiver.c receiver.h
	gcc -c main.c

network.o: network.c network.h sender.h receiver.h
	gcc -c network.c

sender.o: sender.c sender.h network.h receiver.h
	gcc -c sender.c

receiver.o: receiver.c receiver.h network.h sender.h
	gcc -c receiver.c

clean:
	rm -f *.o ${TARGET_BIN}

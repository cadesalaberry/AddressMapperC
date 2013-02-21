CC=gcc
CC_FLAGS=-g -O2 -c -Wall
OBJECTS=addressmapper.o

all:$(OBJECTS)
	$(CC) addressmapper.o -o addressmapper

$(OBJECTS):%.o:%.c
	$(CC) $(CC_FLAGS) $< -o $@

clean:
	rm *.o
	rm -rf addressmapper

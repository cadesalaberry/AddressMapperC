# Sets the C Compiler
CC=gcc

# Optimise the compilation and enable all warnings
CC_FLAGS=-g -O2 -c -Wall

PROG_NAME=addressmapper
OBJECTS=$(PROG_NAME).o

# Disables randomization of the virtual address space.
# http://en.wikipedia.org/wiki/Address_space_layout_randomization
RAND_OFF=setarch $$(uname -m) --addr-no-randomize

start: run clean

all:$(OBJECTS)
	$(CC) $(OBJECTS) -o $(PROG_NAME)

run: all
	@$(RAND_OFF) ./$(PROG_NAME) --text
	@$(RAND_OFF) ./$(PROG_NAME) --data
	@$(RAND_OFF) ./$(PROG_NAME) --bss
	@$(RAND_OFF) ./$(PROG_NAME) --memory
	@$(RAND_OFF) ./$(PROG_NAME) --stack
	@$(RAND_OFF) ./$(PROG_NAME) --heap

$(OBJECTS):%.o:%.c
	$(CC) $(CC_FLAGS) $< -o $@

clean:
	rm $(OBJECTS)
	rm -rf $(PROG_NAME)
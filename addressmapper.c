#include <stdio.h>			// Needed for I/O to stdout.
#include <stdlib.h>			// Standard Library.
#include <unistd.h>			// Needed to get PID of a process.

#define STACK_ADDR 0
#define HEAP_ADDR 1
#define DATA_ADDR 2
#define MEMORY_ADDR 3
#define TEXT_ADDR 4

void * get_addr_according_to_mode(int mode, int size){
	
	switch(mode){
		case STACK_ADDR: {
			return alloca(size * sizeof (char));
			break;
		}
		case HEAP_ADDR: {
			return malloc(size * sizeof (char));
			break;
		}
		case DATA_ADDR: {
			char not_init[size];
			return not_init;
			break;
		}
		case MEMORY_ADDR: {
			printf("\n");
			break;
		}
		case TEXT_ADDR: {
			printf("\n");
			break;
		}
		default:{
			printf("%i is not a valid argument.\n", mode);
			exit(-1);
			break;
		}
	}
	return 0;
}

int display_pid_map(){
	char sInput[69];
	// Displays the map for the running process
	sprintf(sInput, "cat /proc/%d/maps", getpid());
	printf("%s", sInput);
	
	if (fgets(sInput, sizeof sInput, stdin) != NULL){
	
	}
	
	return 0;
}
int main(int argc, char *argv[]){
	
	int i;
	void * min;
	void * temp;
	void * max;
	int mode = atoi(argv[1]);
	int nb_try = atoi(argv[2]);
	
	if (argc != 3){
		printf("Wrong usage. Available commands:\n");
		printf("0\t Will estimate stack segment size.\n");
		printf("1\t Will estimate heap segment size.\n");
		printf("2\t Will estimate BSS and data segment size.\n");
		printf("3\t Will estimate memory segment size.\n");
		printf("4\t Will estimate text segment size.\n");
	}
	
	temp = get_addr_according_to_mode(mode, 1);
	min = temp;
	max = temp;
	printf("nb_try: %i\n", nb_try);
	for (i = 0; i < nb_try; i++){
		
		temp = get_addr_according_to_mode(mode, nb_try);
		
		// Finds out if it is out of the boundaries.
		// If it is make it a boundary.
		if (temp < min) min = temp;
		else if (temp > max) max = temp;
	}
	printf("%p, %p\n", min, max);
	return 0;
}

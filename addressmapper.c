#include <stdio.h>			// Needed for I/O to stdout.
#include <stdlib.h>			// Standard Library.
#include <unistd.h>			// Needed to get PID of a process.
#include <string.h>
#include "addressmapper.h"


int main(int argc, char *argv[]) {

	if(argc == 2) {
		if(!strcmp(argv[1], "--stack") || !strcmp(argv[1], "-s")) {

			// Gets stack segment bounds
			printf("Stack:\t");
			fflush(stdout);
			printf("%p - ", stack_sgmt2(START));
			printf("%p\n", stack_sgmt2(END));

		} else if(!strcmp(argv[1], "--memory") || !strcmp(argv[1], "-m")) {
		
			// Gets memory segment bounds
			printf("Memory:\t");
			printf("%p - ", memory_sgmt(START));
			printf("%p \n", memory_sgmt(END));

		} else if(!strcmp(argv[1], "--text") || !strcmp(argv[1], "-t")) {

			// Gets text segment bounds
			printf("Text:\t");
			printf("%p - ", text_sgmt(START));
			printf("%p \n", text_sgmt(END));

		} else if(!strcmp(argv[1], "--data") || !strcmp(argv[1], "-d")) {

			// Gets data segment bounds
			printf("Data:\t");
			printf("%p - ", data_sgmt(START));
			printf("%p \n", data_sgmt(END));

		} else if(!strcmp(argv[1], "--bss") || !strcmp(argv[1], "-b")) {

			// Gets memory info
			printf("BSS:\t");
			printf("%p - ", bss_sgmt(START));
			printf("%p \n", bss_sgmt(END));

		} else if(!strcmp(argv[1], "--heap") || !strcmp(argv[1], "-h")) {

			// Gets memory info
			printf("Heap:\t");
			fflush(stdout);
			printf("%p - ", heap_sgmt(START));
			printf("%p \n", heap_sgmt(END));

		}

	} else {
		printf("Wrong usage.\n");
	}

	return 0;
}

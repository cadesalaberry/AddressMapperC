
#include <sys/mman.h>
#include <sys/resource.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <alloca.h>

#define START 0
#define END 1

void * memory_sgmt(int e) {

	char * file_name = "addressmapper.c";
	int fd = open(file_name, O_RDONLY);
	struct stat file_stat;
	stat(file_name,&file_stat);

	void * ptr, * tmpPtr;

	ptr = mmap(NULL, file_stat.st_size, PROT_READ, MAP_PRIVATE, fd, 0);

	if (e == START) {
		
		return ptr;
	
	} else {

		while (1) {
			tmpPtr = mmap(NULL, file_stat.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
			if(tmpPtr == (void *)-1)
			{
				return ptr;
			}
			else
			{
				ptr = tmpPtr;
			}
		}
	}
}

void * stack_sgmt(int e) {

	if (e == START) {
		return alloca(1024);
	
	} else {
		while(1)
		{
			//Run until seg fault
			void * ptr = alloca(1024);
			printf("%p", ptr);
			printf("\b\b\b\b\b\b\b\b\b\b");
		}
	}
}

void * heap_sgmt(int e) {
	
	if (e == START) {
		void * ptr = malloc(1);
		return ptr;
	
	} else {

		int i = 0;
		void * ptr, * tmpPtr = malloc(1);

		ptr = tmpPtr;

		while(tmpPtr) {

			ptr = tmpPtr;
			i++;
			tmpPtr = realloc(ptr, i*1024);
		}
		return ptr;
	}

}

void * text_sgmt(int e) {

	if (e == START) {
		return (void *) 0x8048000;

	} else {
		extern char _etext;
		return &_etext-1;
	}
}

void * data_sgmt(int e) {

	if (e == START) {
		extern char _etext;
		return &_etext;

	} else {
		extern char _edata;
		return &_edata-1;
	}
}

void * bss_sgmt(int e) {

	if (e == START) {
		extern char _edata;
		return &_edata;

	} else {
		extern char _end;
		return &_end;
	}
}

void * stack_sgmt2(int e){
	int i;
	void * min, * temp, * max;

	temp = alloca( 1* sizeof (char));
	min = temp;
	max = temp;
	
	
	if (e == START) {
		return min;

	} else {

		for (i = 0; i <= 999999999; i++){
		
		temp = alloca(i * sizeof (char));
		
		// Finds out if it is out of the boundaries.
		// If it is make it a boundary.
		if (temp < min) min = temp;
		else if (temp > max) max = temp;
	}

		return max;
	}
}


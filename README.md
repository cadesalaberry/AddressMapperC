`AddressMapperC`
==================

Prints the size of different memory segment to the console. (Text, Data, BSS, Heap, Memory, Stack).

## Usage

Here is the sample I get every time I ran my program.

~~We can see that the Stack is HUGE.~~

Well obviously. The address is a high number for it starts at the end of the memory map...

```shell
[cdesal][teaching][~] make start
gcc -g -O2 -c -Wall addressmapper.c -o addressmapper.o
gcc addressmapper.o -o addressmapper
Text:	0x8048000 - 0x8048bd5
Data:	0x8048bd6 - 0x804a033
BSS:	0x804a034 - 0x804a03c
Memory:	0xb7fda000 - 0xa7e3d000
Stack:	0xbffff710 - 0xfffffff0
Heap:	0x804b008 - 0x2be08008
```

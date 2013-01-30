#1/bin/bash

PROG_NAME=addressmapper

echo
echo Getting physical address map to file ../result/phys_addr_map
echo $(cat /proc/iomem) > ../result/phys_addr_map
cd ./bin
echo 
echo Building...
gcc -Wall -o $PROG_NAME ../$PROG_NAME.c
echo
echo Running with randomization of the virtual address  space disabled.
echo
for MODE in {0..4..1}
do
	echo Mode $MODE: Computing...	
	MIN_AND_MAX=$(setarch x86_64 --addr-no-randomize ./$PROG_NAME $MODE 100000000000)
	echo $MIN_AND_MAX >> mode$MODE.csv
	echo Boundaries writen to files.
done
echo

#1/bin/bash

PROG_NAME=addressmapper
FOLDER=results
echo
echo Creating results folder "$FOLDER".
mkdir $FOLDER
echo
echo Getting physical address map to file "./$FOLDER/phys_addr_map".
echo $(cat /proc/iomem) > ./$FOLDER/phys_addr_map
echo 
echo Building...
gcc -Wall -o $PROG_NAME ./$PROG_NAME.c
echo
echo Running with randomization of the virtual address  space disabled.
echo
for MODE in {0..4..1}
do
	echo Mode $MODE: Computing...	
	MIN_AND_MAX=$(setarch i686 --addr-no-randomize ./$PROG_NAME $MODE 1000)
	echo $MIN_AND_MAX >> ./$FOLDER/mode$MODE.csv
	echo Boundaries writen to files.
done
echo

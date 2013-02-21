RAND_OFF="setarch i686 --addr-no-randomize"

if [ -e ./*.o ]
	then make clean
fi
make > /dev/null
if [ -e ./addressmapper ]
	then
	$RAND_OFF ./addressmapper -text
	$RAND_OFF ./addressmapper -data
	$RAND_OFF ./addressmapper -bss
	$RAND_OFF ./addressmapper -heap
	$RAND_OFF ./addressmapper -memory
	$RAND_OFF ./addressmapper -stack
fi
if [ -e ./*.o ]
	then make clean
fi
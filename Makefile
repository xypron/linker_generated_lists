
all:
	gcc -I. -g -c test.c
	ld -o test test.o \
	-T test.lds \
	--print-map \
	-L /usr/lib/gcc/x86_64-linux-gnu/11/ \
	-lc -lgcc \
	/usr/lib/x86_64-linux-gnu/crti.o \
	/usr/lib/x86_64-linux-gnu/crt1.o \
	/usr/lib/x86_64-linux-gnu/crtn.o \
	-dynamic-linker /lib64/ld-linux-x86-64.so.2




all:
	gcc -I. -g -c test.c
	gcc -I. -g -c srst1.c
	gcc -I. -g -c srst2.c
	gcc -I. -g -c srst3.c
	ld -o test test.o srst1.o srst2.o srst3.o \
	-T test.lds \
	--print-map \
	-L /usr/lib/gcc/x86_64-linux-gnu/11/ \
	-lc -lgcc \
	/usr/lib/x86_64-linux-gnu/crti.o \
	/usr/lib/x86_64-linux-gnu/crt1.o \
	/usr/lib/x86_64-linux-gnu/crtn.o \
	-dynamic-linker /lib64/ld-linux-x86-64.so.2

clean:
	rm -f test.o test

check:
	./test

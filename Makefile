.POSIX:

HOST=${shell gcc -dumpmachine}

all:
	gcc -I. -g -c test.c
	gcc -I. -g -c srst1.c
	gcc -I. -g -c srst2.c
	gcc -I. -g -c srst3.c
	gcc -o test test.o srst1.o srst2.o srst3.o \
	-Wl,-T $(HOST).lds \
	-Wl,-Map=test.map

clean:
	rm -f *.map *.o test

check:
	./test

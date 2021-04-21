OBJS = core.o green.o orange.o blue.o red.o yellow.o purple.o

binary: $(OBJS) libfifo.so libsem.so libshm.so
	gcc -o binary $(OBJS) -L. -lfifo -lsem -lshm -Wl,-rpath,.
core.o: core.c
	gcc -c core.c
green.o: green.c
	gcc -c green.c
orange.o: orange.c
	gcc -c orange.c
blue.o: blue.c
	gcc -c blue.c
red.o: red.c
	gcc -c red.c
yellow.o: yellow.c
	gcc -c yellow.c
purple.o: purple.c
	gcc -c purple.c
libfifo.so: fifo.o
	gcc -shared -o libfifo.so fifo.o
fifo.o: lib/fifo.c
	gcc -c -fPIC lib/fifo.c
libsem.so: sem.o
	gcc -shared -o libsem.so sem.o
sem.o: lib/sem.c
	gcc -c -fPIC lib/sem.c
libshm.so: shm.o
	gcc -shared -o libshm.so shm.o
shm.o: lib/shm.c
	gcc -c -fPIC lib/shm.c
clean:
	rm -rf *.o *.so result_* yellow-green.fifo red-result.bin binary

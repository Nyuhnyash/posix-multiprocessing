binary: core.o green.o orange.o blue.o red.o yellow.o purple.o
	gcc -o binary core.o green.o orange.o blue.o red.o yellow.o purple.o
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
clean:
	rm -f *.o binary

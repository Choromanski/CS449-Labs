mallocdrv: tree.o main.o
	gcc -o mallocdrv tree.o main.o

tree.o: tree.c tree.h
	gcc -c tree.c

main.o: main.c tree.h
	gcc -c main.c

tree.h: malloc.h

clean:
	rm -f *.o mallocdrv

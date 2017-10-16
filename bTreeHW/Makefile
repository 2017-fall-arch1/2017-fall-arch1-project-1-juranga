CC=gcc
CFLAGS= -Wall 

bTreeDemo: bTreeDemo.c bTree.c
	${CC} ${CFLAGS} -o bTreeDemo bTreeDemo.c bTree.c 

clean:
	rm -f .o ./bTreeDemo

demo: bTreeDemo
	./bTreeDemo

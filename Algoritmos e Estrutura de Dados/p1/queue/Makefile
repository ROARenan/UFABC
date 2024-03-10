CC = gcc -Wall -pedantic

dir:
	mkdir -p build

element: dir
	$(CC) -c element.c -o build/element.o

queue: element
	$(CC) -c queue.c -o build/queue.o

main: queue
	$(CC) main.c build/queue.o build/element.o -o build/main
all: caesar queue

caesar:
	rm -f caesar *~
	gcc -Wall -g -o caesar caesar.c

queue:
	rm -f queue *~
	gcc -Wall -g -o queue queue.c

clean:
	rm -f caesar queue *~

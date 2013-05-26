all:
	gcc main.c -o cat

clean:
	rm -f cat

example:
	./cat main.c

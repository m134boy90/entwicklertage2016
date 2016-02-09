CC=gcc
FLAGS= -g -Wall -m32

hello: hello.c
	$(CC) $(FLAGS) -o hello hello.c

arrayhack: arrayhack.c
	$(CC) $(FLAGS) -fno-stack-protector -o arrayhack arrayhack.c

.PHONY: clean

clean:
	rm -f hello arrayhack

CC=gcc
FLAGS= -g -Wall -m32
LD=ld -m elf_i386

#all: hello.o
#	$(LD) -o hello hello.o
all: hello.o
	$(CC) $(FLAGS) -o hello hello.o

hello.o: hello.asm
	nasm -f elf -g  hello.asm

.PHONY: clean

clean:
	rm -f *.o hello

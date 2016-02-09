OBJS = main.o
LIBOBJS =
HEADS = 

EXECUTABLE = out.x

CC = gcc -m32
DEBUG = -g3 -O0
CFLAGS = -c
AFLAGS = -fno-stack-protector $(DEBUG)
LDFLAGS =

all: $(EXECUTABLE) hello.x

$(EXECUTABLE): $(OBJS)
	$(CC) $(AFLAGS) -o $@ $^ $(LIBOBJS) $(LDFLAGS) 

%.o: %.c $(HEADS)
	$(CC) $(AFLAGS) $(CFLAGS) $<

hello.x: hello.o
	ld -m elf_i386 -o hello.x hello.o

hello.o: hello.asm
	nasm -g -f elf hello.asm

.PHONY: tidy clean re pack link

re:
	$(MAKE) clean
	$(MAKE) $(EXECUTABLE)
	$(MAKE) pack

tidy: 
	rm -f *.o core

link:
	ln -fs $(EXECUTABLE) runnable

clean: tidy
	rm -f *.x *.txz runnable

pack:
	tar cvf - *.c *.asm makefile | pixz -9 -e > $(PACKFILE).txz


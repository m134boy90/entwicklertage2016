OBJS = hello.o

EXECUTABLE = out.x

CC = nasm -f elf
LD = ld -m elf_i386

#all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJS)
	$(LD) -o $@ $^

%.o: %.asm
	$(CC) $<

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
	tar cvf - *.asm makefile | pixz -9 -e > $(PACKFILE).txz


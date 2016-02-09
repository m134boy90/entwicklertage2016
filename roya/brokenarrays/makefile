OBJS = main.o
LIBOBJS =
HEADS = 

EXECUTABLE = out.x

CC = gcc -m32
DEBUG = -g3 -O0
CFLAGS = -c
AFLAGS = -fno-stack-protector $(DEBUG)
LDFLAGS =

#all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJS)
	$(CC) $(AFLAGS) -o $@ $^ $(LIBOBJS) $(LDFLAGS) 

%.o: %.c $(HEADS)
	$(CC) $(AFLAGS) $(CFLAGS) $<

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
	tar cvf - *.c *.h makefile | pixz -9 -e > $(PACKFILE).txz


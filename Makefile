CC=gcc
CFLAGS=-g -O0
ASFLAGS=-g
LD=ld
LDFLAGS=

EXE=test

OBJS=test.o start.o syscall.o

all: $(EXE)
	./$(EXE) hello world

$(EXE): $(OBJS)
	$(LD) $(LDFLAGS) -o $@ $^

clean:
	rm -f $(OBJS) $(EXE)-* $(EXE)

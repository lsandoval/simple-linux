CC=gcc
CFLAGS=-g -O0 -fno-asynchronous-unwind-tables
ASFLAGS=-g
LD=ld
LDFLAGS+=-z separate-code
ifdef PIE
LDFLAGS+=-pie --no-dynamic-linker
endif

EXE=test

OBJS=test.o start.o syscall.o

all: $(EXE)
	./$(EXE); echo $$?

$(EXE): $(OBJS)
	$(LD) $(LDFLAGS) -o $@ $^

clean:
	rm -f $(OBJS) $(EXE)-* $(EXE)

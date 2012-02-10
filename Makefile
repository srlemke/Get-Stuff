CC	= gcc
CFLAGS	= -g -O0 -Wall `pkg-config gtk+-2.0 --cflags gmodule-2.0`
LD	= gcc
LDFLAGS	=
LIBS	= `pkg-config gtk+-2.0 --libs gmodule-2.0`
BIN	= get_stuff
OBJS	= skype.o util.o main.o flash.o plugin.o

.c.o:
	$(CC) -c $(CFLAGS) -o $*.o $<

all: $(BIN)

$(BIN): $(OBJS)
	$(LD) -o $@ $(LDFLAGS) $(OBJS) $(LIBS)

clean:
	rm -f $(BIN) $(OBJS) *~ core

depend: Makefile
	$(CC) -c -MM $(OBJS:.o=.c) > $@

include depend

CC=gcc
CFLAGS=-Wall -Wextra -pedantic -std=c99
LIBS=-lm
OBJS=area.o help.o circle.o rectangle.o triangle.o
DEPS=area.h
bindir=/usr/local/bin

area: $(OBJS)
	$(CC) -o area $(OBJS) $(LIBS)

area.o: $(DEPS)

clean:
	rm area $(OBJS)

install: area
	install -g root -o root area $(bindir)/area

uninstall: $(bindir)/area
	rm $(bindir)/area

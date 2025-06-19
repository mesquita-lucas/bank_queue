CC = gcc
CARGS = -Wall -Wextra -Isrc -Iinc

OBJDIR = objs

OBJS = $(OBJDIR)/main.o \
	   $(OBJDIR)/queue.o

all: bank_queue

bank_queue: $(OBJS)
	$(CC) $(CARGS) -o bank_queue $(OBJS)

$(OBJDIR)/main.o: src/main.c inc/queue.h
	$(CC) $(CARGS) -c src/main.c -o $@

$(OBJDIR)/queue.o: src/queue.c inc/queue.h
	$(CC) $(CARGS) -c src/queue.c -o $@

$(OBJDIR):
	mkdir -p $@

$(OBJS): | $(OBJDIR)

clean:
	rm -rf bank_queue $(OBJDIR)

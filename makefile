CC := gcc
CFLAGS := -Wall -pedantic -std=c17 -D_GNU_SOURCE
OBJS := \
main.o \
mvector/vector2.o \
lin/pqr.o

all: clean $(OBJS) build

build:
	$(CC) $(CFLAGS) -o main $(OBJS) -lm

$(OBJS): %.o : %.c

clean:
	rm -f $(OBJS)
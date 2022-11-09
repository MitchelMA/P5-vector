CC := gcc
CFLAGS := -Wall -pedantic -std=c17 -D_GNU_SOURCE
OBJS := \
main.o \
mvector/vector2.o

all: clean $(OBJS) build

build:
	$(CC) $(CFLAGS) -o main.out $(OBJS) -lm

$(OBJS): %.o : %.c

clean:
	rm -f $(OBJS)
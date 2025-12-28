CFLAGS = -Wall -Wextra -Werror -std=c11

SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)

TARGET = main

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

test: CFLAGS += -DTEST
test: clean all

clean:
	rm -f $(OBJS) $(TARGET) a.out

.PHONY: all test clean


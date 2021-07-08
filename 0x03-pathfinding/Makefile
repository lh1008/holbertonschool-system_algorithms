CC = gcc
CFLAGS = -Wall -Wextra -Werror -pedantic

TASK0 = 0-backtracking_array

all: 0-backtracking_array

$(TASK0): $(TASK0).c 0-main.c
	$(CC) -o $@ $(CFLAGS) $^ -lqueues

.PHONY: clean, check, run

clean:
	rm $(TASK0)

check:
	betty *.c *.h

CC = gcc
CFLAGS = -Wall -Wextra -Werror -pedantic

TASK0 = 0-backtracking_array
TASK1 = 1-backtracking_graph
TASK2 = 2-dijkstra_graph

all: 0-backtracking_array 1-backtracking_graph 2-dijkstra_graph

$(TASK0): 0-main.c $(TASK0).c
	$(CC) -o $@ $(CFLAGS) $^ -L. -lqueues

$(TASK1): 1-main.c $(TASK1).c
	$(CC) -o $@ $(CFLAGS) $^ -L. -lqueues -lgraphs

$(TASK2): 2-main.c $(TASK2).c
	$(CC) -o $@ $(CFLAGS) $^ -L. -lqueues -lgraphs

.PHONY: clean, check, run

clean:
	rm $(TASK0) $(TASK1) $(TASK2)

check:
	betty *.c *.h

# 0x03. C - Pathfinding

### Learning Objectives

- What is pathfinding
- What are the most common applications of pathfinding
- What is backtracking, and why you should never use it
- What is Dijkstra’s algorithm, and what is its main weakness
- What is A star algorithm, and how it is better than Dijkstra’s

### Compilation and Instructions

All these files were compiled using `Ubuntu 20.04 LTS`.

The programs and functions will be compiled with `gcc 8.4.0` using flags `-Wall` `-Werror` `-Wextra` and `-pedantic`.

The prototypes of all the functions are included in the header file called `pathfinding.h`.

#### Libraries - `graphs` & `queues`

Download the libraries using your terminal with the following commands, or download them from [here](https://github.com/holbertonschool/0x07-pathfinding.c):

- `wget -O graphs.h https://raw.githubusercontent.com/holbertonschool/0x07-pathfinding.c/master/graphs.h`

- `wget -O queues.h https://raw.githubusercontent.com/holbertonschool/0x07-pathfinding.c/master/queues.h`

The code will be compiled using `-lgraphs` and `-lqueues`.

### Data Structure

```
/**
 * struct point_s - Structure storing coordinates
 *
 * @x: X coordinate
 * @y: Y coordinate
 */
typedef struct point_s
{
    int x;
    int y;
} point_t;
```

### Tasks

_**0. Backtracking - Array**_
Write a function that searches for the first path from a starting point to a target point within a two-dimensional array.

- Protorype: `queue_t *backtracking_array(char **map, int rows, int cols, point_t const *start, point_t const *target);`

- Compilation: `gcc -o 0-backtracking_array -Wall -Wextra -Werror -pedantic 0-main.c 0-backtracking_array.c -lqueues`

_**1. Backtracking - Graph**_
Write a function that searches for the first path from a starting point to a target point in a graph.

- Prototype: `queue_t *backtracking_graph(graph_t *graph, vertex_t const *start, vertex_t const *target);`

- Compilation: `gcc -o 1-backtracking_graph -Wall -Wextra -Werror -pedantic 1-main.c 1-backtracking_graph.c -lqueues -lgraphs`

_**2. Dijkstra's - Graph**_
Write a function that searches for the shortest path from a starting point to a target point in a graph.

- Prototype: `queue_t *dijkstra_graph(graph_t *graph, vertex_t const *start, vertex_t const *target);`

- Compilation #1: `gcc -o 2-dijkstra_graph -Wall -Wextra -Werror -pedantic 2-main.c 2-dijkstra_graph.c -lqueues -lgraphs`

- Compilation #2: `gcc -o 2-dijkstra_graph_1 -Wall -Wextra -Werror -pedantic 2-main_1.c 2-dijkstra_graph.c -lqueues -lgraphs`

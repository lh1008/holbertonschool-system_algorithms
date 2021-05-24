# 0x01. C - Graphs

### Learning Objectives

- What is a graph
- What are vertices and edges
- What are the different types of graphs (directed, weighted, …)
- What are the most common ways used to represent graphs in C
- How to traverse a graph using DFS and BFS

### Tasks

_**0. Create graph**_
Write a function that allocates memory to store a `graph_t` structure, and initializes its content.

_**1. Add a vertex**_
Write a function that adds a vertex to an existing graph.
- Prototype: `vertex_t *graph_add_vertex(graph_t *graph, const char *str);`

_**2. Add an edge**_
Write a function that adds an edge between two vertices to an existing graph.
- Prototype: `int graph_add_edge(graph_t *graph, const char *src, const char *dest, edge_type_t type);`

_**3. Delete graph**_
Write a function that completely deletes a graph.
- Prototype: `void graph_delete(graph_t *graph);`

_**4. Depth-first traversal**_
Write a function that goes through a graph using the `depth-first` algorithm.
- Prototype: `size_t depth_first_traverse(const graph_t *graph, void (*action)(const vertex_t *v, size_t depth));`

_**5. Breadth-first traversal**_
Write a function that goes through a graph using the `breadth-first` algorithm.
- Prototype: `size_t breadth_first_traverse(const graph_t *graph, void (*action)(const vertex_t *v, size_t depth));`

### Compile & Instructions

This project was compiled on `Ubuntu 20.4 LTS`.

These were compiled using `GCC` (`gcc version 8.4.0`). The program and functions will be compiled using the flags `-Wall` `-Werror` `-Wextra` and `-pedantic`.

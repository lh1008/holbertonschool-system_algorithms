#include "pathfinding.h"

static graph_t *g_graph;
static vertex_t const *g_target;
static queue_t *g_path;
static char *g_visited;

/**
 * backtrack_graph - entry to backtrack graph
 * Desc: backtrack_graph function to bracktrack visited cities
 * @vertex: current vertex to traverse
 * Return: 1 if destination found else 0
 */
static int backtrack_graph(vertex_t const *vertex)
{
	char *city;
	edge_t *edge;

	if (g_visited[vertex->index])
		return (0);
	printf("Checking %s\n", vertex->content);
	g_visited[vertex->index] = 1;
	city = strdup(vertex->content);
	if (!city)
		exit(98);
	queue_push_front(g_path, city);
	if (vertex == g_target)
		return (1);
	for (edge = vertex->edges; edge; edge = edge->next)
		if (backtrack_graph(edge->dest))
			return (1);
	free(dequeue(g_path));
	return (0);
}

/**
 * backtracking_graph - entry to backtracking grapg
 * Desc: backtracking_graph function that searches for the first
 * path from a starting point to a target point in a graph.
 * @graph: pointer to graph struct
 * @start: pointer to starting vertex
 * @target: pointer to target vertex
 * Return: queue of vertices forming path
 */

queue_t *backtracking_graph(graph_t *graph, vertex_t const *start,
		vertex_t const *target)
{
	char *city;
	queue_t *reverse_path = NULL;

	if (!graph || !start || !target)
		return (NULL);
	setbuf(stdout, NULL);
	g_visited = calloc(graph->nb_vertices, sizeof(*g_visited));
	if (!g_visited)
		return (NULL);
	g_path = queue_create();
	if (!g_path)
		return (NULL);
	g_target = target;
	g_graph = graph;
	if (backtrack_graph(start))
	{
		reverse_path = queue_create();
		if (!reverse_path)
			return (NULL);
		for (city = dequeue(g_path); city != NULL;
		     city = dequeue(g_path))
			if (!queue_push_front(reverse_path, city))
				return (NULL);
	}
	queue_delete(g_path);
	free(g_visited);
	return (reverse_path);
}

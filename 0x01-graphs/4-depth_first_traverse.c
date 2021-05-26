#include "graphs.h"

/**
 * debth - entry to debth
 * Desc: debth function to traverse a graph
 * using depth-first algorithm
 * @v: pointer vertex node being visited
 * @visited: array specifying if vertex has been visited
 * @action: function pointer to be called for each visited vertex
 * @depth: current depth
 * @max_depth: max depth reached during traversal
 */

size_t debth(vertex_t *vertex, int *visited,
	 void (*action)(const vertex_t *v, size_t depth), size_t depth,
	 size_t *max_depth)
{
	edge_t *edges;

	if (visited[vertex->index])
		return (depth - 1);

	action(vertex, depth);
	visited[vertex->index] = 1;

	if (depth > *max_depth)
		*max_depth = depth;
	++depth;

	edges = vertex->edges;
	while (edges)
	{
		debth(edges->dest, visited, action, depth, max_depth);
		edges = edges->next;
	}

	return (*max_depth);
}

/**
 * depth_first_traverse - entry to depth first
 * Desc: depth_first_traverse function that goes
 * through a graph using depth-first algorithm
 * @graph: pointer to graph to traverse
 * @action: pointer for each visited vertex
 *    v: const pointer to the visited vertex
 *    depth: depth of v
 * Return: biggest vertex depth, or 0 on failure
 */
size_t depth_first_traverse(const graph_t *graph,
			    void (*action)(const vertex_t *v, size_t depth))
{
	int *visited;
	size_t max_depth = 0;

	if (!graph)
		return (0);

	visited = calloc(graph->nb_vertices, sizeof(*visited));
	if (!visited)
		return (0);

	debth(graph->vertices, visited, action, 0, &max_depth);
	free(visited);

	return (max_depth);
}

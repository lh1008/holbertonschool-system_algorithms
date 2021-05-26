#include "graphs.h"

/**
 * depth - entry to depth
 * Desc: depth recursive function to find max depth using depth-first search
 * @vertex: vertex to search
 * @action: pointer to function to be called for each visited vertex
 * @visited: boolean
 * @depth: current depth
 * @max_depth: max depth
 * Return: max_depth or 0 on failure
 */
void depth(vertex_t *vertex, void (*action)(const vertex_t *v, size_t depth),
			int *visited, size_t depth, size_t *max_depth)
{
	edge_t *edges;

	if (!vertex || visited[vertex->index])
		return;

	action(vertex, depth);
	visited[vertex->index] = 1;

	if (depth > *max_depth)
		*max_depth = depth;
	depth++;

	edges = vertex->edges;
	while (edges)
	{
		dfs(edges->dest, action, visited, depth, max_depth);
		edges = edges->next;
	}
}

/**
 * depth_first_traverse - entry to depth first
 * Desc: depth_first_traverse function that goes through
 * a graph using depth-first algorithm
 * @graph: pointer to graph to traverse
 * @v: const pointer to the visited vertex
 * @depth: depth of v, from the starting vertex
 * Return: return biggest vertex depth, or 0 in failure
 */
size_t depth_first_traverse(const graph_t *graph,
			    void (*action)(const vertex_t *v, size_t depth))
{
	int *seen;
	size_t max_depth = 0;

	if (!graph)
		return (0);

	if (graph->nb_vertices)
	{
		seen = calloc(graph->nb_vertices, sizeof(char));
		dfs(graph->vertices, action, seen, 0, &max_depth);
		free(seen);
	}
	return (max_depth);
}

#include "graphs.h"

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
}

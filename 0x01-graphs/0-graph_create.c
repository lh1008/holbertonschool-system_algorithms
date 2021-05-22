#include "graphs.h"

/**
 * graph_create - entry to graph create
 * Desc: graph_create function that allocates memory
 * to store a graph_t structure
 * Return: pointer to the allocated structure, or NULL on failure
 */
graph_t *graph_create(void)
{
	struct graph_s *graph_t;

	graph_t = malloc(sizeof(graph_t));

	if (graph_t == NULL)
		return (NULL);

	graph_t->vertices = (struct vertex_s*)malloc(sizeof(struct vertex_s));

	return (graph_t);

}

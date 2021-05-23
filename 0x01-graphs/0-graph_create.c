#include "graphs.h"

/**
 * graph_create - entry to graph create
 * Desc: graph_create function that allocates memory
 * to store a graph_t structure
 * Return: pointer to the allocated structure, or NULL on failure
 */
graph_t *graph_create(void)
{
	graph_t *graph_node;

	graph_node = malloc(sizeof(graph_t));

	if (!graph_node)
		return (NULL);

	graph_node->nb_vertices = 0;
	graph_node->vertices = NULL;

	return (graph_node);

}

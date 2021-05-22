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
	size_t nb_vertices = 0, i;

	graph_t = malloc(sizeof(graph_t));

	if (graph_t == NULL)
		return (NULL);

	graph_t->nb_vertices = nb_vertices;

	graph_t->vertices = (struct vertex_s*)malloc(nb_vertices * sizeof(struct vertex_s));

	for (i = 0; i < nb_vertices; ++i)
		graph_t->vertices[i].next = NULL;

	return (graph_t);

}

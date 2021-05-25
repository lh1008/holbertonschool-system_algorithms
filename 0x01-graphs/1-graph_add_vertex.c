#include "graphs.h"

/**
 * graph_add_vertex - entry graph add vertex
 * Desc: graph_add_vertex funtcion that adds a vertex to
 * an existing graph.
 * @graph: pointer graph_t type to the graph to add the vertex
 * @str: pointer char type string to store in the new vertex
 * Return: pointer to the created vertex, or NULL on failure
 */
vertex_t *graph_add_vertex(graph_t *graph, const char *str)
{
	vertex_t *vertex, *new;

	if (graph == NULL || str == NULL)
		return (NULL);
	vertex = graph->vertices;
	while (vertex)
	{
		if (!strcmp(vertex->content, str))
			return (NULL);
		if (!vertex->next)
			break;
		vertex = vertex->next;
	}
	new = malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->content = strdup(str);
	if (!new->content)
	{
		free(new);
		return (NULL);
	}
	graph->nb_vertices++;
	if (!vertex)
	{
		graph->vertices = new;
		new->index = 0;
	}
	else
	{
		vertex->next = new;
		new->index = vertex->index + 1;
	}
	new->nb_edges = 0;
	new->edges = NULL;
	new->next = NULL;

	return (new);
}

#include "graphs.h"

/**
 * get_vertex - entry to get_vertex
 * Desc: A function that fetches an vertex existing in graph
 * @graph: A pointer to the graph
 * @str: The string identifying the vertex
 * Return: vertex on success,  NULL on failure
 */
vertex_t *get_vertex(graph_t *graph, const char *str)
{
	vertex_t *node;

	if (str == NULL)
		return (0);
	node = graph->vertices;
	if (node == NULL)
		return (NULL);
	while (node != NULL)
	{
		if (strcmp(node->content, str) == 0)
		{
			return (node);
		}
		node = node->next;
	}
	return (NULL);
}

/**
 * create_edge - entry to create edge
 * Desc: create_edge function that creates an edge between two vertices
 * @src: The src vertex to make the connection from
 * @dest: The destination vertex to connect to
 * Return: 1 on success,  0 on failure
 */
int create_edge(vertex_t *src, vertex_t *dest)
{
	edge_t *current_edge, *new_edge = NULL;

	current_edge = src->edges;
	while (current_edge && current_edge->next != NULL)
	{
		current_edge = current_edge->next;
	}

	new_edge = malloc(sizeof(edge_t));
	if (new_edge != NULL)
	{
		new_edge->dest = dest;
		new_edge->next = NULL;

		if (src->nb_edges == 0)
			src->edges = new_edge;
		else
			current_edge->next = new_edge;
		return (1);
	}
	return (0);
}

/**
 * edge_exists - entry to edge exists
 * Desc: edge_exists function that checks
 * if an edge between two vertices exists
 * @src: The src vertex to make the connection from
 * @dest: The destination vertex to connect to
 * Return: 1 if exists,  0 if not exists
 */
int edge_exists(vertex_t *src, vertex_t *dest)
{
	edge_t *edge = NULL;

	edge = src->edges;
	while (edge != NULL)
	{
		if (edge->dest == dest)
			return (1);
		edge = edge->next;
	}

	return (0);
}

/**
 * graph_add_edge - entry to graph add edge
 * Desc: graph_add_edge function that adds an edge
 * between two vertices to an existing graph.
 * @graph: struct graph_t structure pointer to the graph to add the edge
 * @src: pointer char to string identifying the vertex
 * @dest: pointer char string to identify the vertex to connect
 * @type: type of the edge to use; UNIDERECTIONAL/BIDIRECTIONAL
 * Return: return 1 in success or 0 on failure.
 */
int graph_add_edge(graph_t *graph, const char *src,
		   const char *dest, edge_type_t type)
{
	vertex_t *source, *destination;

	if (graph == NULL || (type != UNIDIRECTIONAL && type != BIDIRECTIONAL))
		return (0);
	source = get_vertex(graph, src);
	destination = get_vertex(graph, dest);
	if (!source || !destination)
		return (0);

	if (type == UNIDIRECTIONAL || type == BIDIRECTIONAL)
	{
		if (edge_exists(source, destination))
			return (1);
		if (!create_edge(source, destination))
			return (0);
		source->nb_edges += 1;
	}
	if (type == BIDIRECTIONAL)
	{
		if (edge_exists(destination, source))
			return (1);
		if (!create_edge(destination, source))
			return (0);
		destination->nb_edges += 1;
	}
	return (1);
}

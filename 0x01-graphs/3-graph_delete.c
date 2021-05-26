#include "graphs.h"

/**
 * graph_delete - entry to graph delete
 * Desc: graph_delete function that completely deletes a graph
 * @graph: pointer to graph delete
 * Return: deleted graphs
 */
void graph_delete(graph_t *graph)
{
	vertex_t *vertex, *vertex_temp;
	edge_t *edge, *edge_temp;

	if (graph == NULL)
		return;
	for (vertex = graph->vertices; vertex;)
	{
		free(vertex->content);
		for (edge = vertex->edges; edge;)
		{
			edge_temp = edge;
			edge = edge->next;
			free(edge_temp);
		}
		vertex_temp = vertex;
		vertex = vertex->next;
		free(vertex_temp);
	}
	free(graph);
	graph = NULL;
}

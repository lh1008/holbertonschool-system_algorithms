#include "heap.h"

/**
 * heap_insert - entry to heap insert
 * Desc: heap_insert function that inserts a value
 * in a Min Binary Heap
 * @heap: pointer to the heap in which the node has to be inserted
 * @data: pointer containing the datato store in the new node
 * Return: return a pointer to the creatednode containing data,
 * or NULL if it fails
 */
binary_tree_node_t *heap_insert(heap_t *heap, void *data)
{
	heap_t *node_insert;

	if (!heap || !data)
		return (EXIT_FAILURE);

	if (heap->root == NULL)
		node_insert = heap->root;

	if (heap->size == 0)
	{
		heap->root = data;
		heap->size += 1;
	}
	else
	{
	}
}

""" https://www.programiz.com/dsa/heap-data-structure """

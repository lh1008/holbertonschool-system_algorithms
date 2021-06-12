#include "heap.h"

/**
 * heap_create - entry to main
 * Desc: heap_create function that creates a Heap data structure
 * @data_cmp: pointer type to a comparison function
 * Return: pointer to the created heap_t, NULL if it fails
 */
heap_t *heap_create(int (*data_cmp)(void *, void *))
{
	heap_t *node;

	node = malloc(sizeof(heap_t));

	if (node == NULL)
		return (NULL);

	node->size = 0;
	node->data_cmp = data_cmp;
	node->root = NULL;

	return (node);
}

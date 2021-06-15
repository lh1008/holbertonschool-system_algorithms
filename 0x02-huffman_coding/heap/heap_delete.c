#include "heap.h"

/**
 * free_binary_tree - entry to free binary tree
 * Desc: free_binary_tree function that frees all nodes in a binary tree
 * @node: pointer to root node
 * @free_data: pointer to function used to free node content
 * Return: nothing, void function
 */
void free_binary_tree(binary_tree_node_t *node, void (*free_data)(void *))
{
	if (!node)
		return;

	free_binary_tree(node->left, free_data);
	free_binary_tree(node->right, free_data);

	if (free_data)
		free_data(node->data);
	free(node);
}

/**
 * heap_delete - entry to heap delete
 * Desc: heap_delete function that deallocate a heap
 * @heap: pointer to heap to delete
 * @free_data: pointer to function used to free node content
 * Return: nothing, void function
 */
void heap_delete(heap_t *heap, void (*free_data)(void *))
{
	if (!heap)
		return;
	free_binary_tree(heap->root, free_data);
	free(heap);
}

#include "heap.h"

/**
 * swap_node - entry to swap nodes
 * Desc: swap_node function to swap data of two specified nodes
 * @a: pointer to first node
 * @b: pointer to second node
 * Return: pointer containing 'a' node data
 */
binary_tree_node_t *swap_node(binary_tree_node_t *a, binary_tree_node_t *b)
{
	void *tmp;

	tmp = b->data;
	b->data = a->data;
	a->data = tmp;
	a = b;

	return (a);
}

/**
 * shift_down - entry to shift down
 * Desc: shift_down function to heapify subtree
 * @heap: pointer to heap to heapify
 * Return: nothing, void function
 */
void shift_down(heap_t *heap)
{
	binary_tree_node_t *largest, *node;

	if (!heap || !heap->root)
		return;
	node = heap->root;
	while (node->left)
	{
		largest = node->left;
		if (node->right && heap->data_cmp(node->data,
						  node->right->data) >= 0 &&
		heap->data_cmp(node->right->data,
			       node->left->data) < 0 && node->left)
		{
			swap_node(node->right, node);
			largest = node->right;
		}
		else if (heap->data_cmp(node->left->data, node->data) <= 0)
			swap_node(node->left, node);
		node = largest;
	}
}

/**
 * heap_extract - entry to heap_extract
 * Desc: heap_extract function extracts the root value of a Min Binary Heap
 * @heap: pointer to the heap from which to extract the value
 * Return: pointer to the data that was stored in the root node, or NULL
 */
void *heap_extract(heap_t *heap)
{
	binary_tree_node_t *bottom_node;
	void *root_dt;

	if (!heap)
		return (NULL);

	root_dt = heap->root->data;
	bottom_node = ith_node(heap->root, heap->size);
	heap->root->data = bottom_node->data;

	if (bottom_node->parent)
	{
		if (bottom_node->parent->left == bottom_node)
			bottom_node->parent->left = NULL;
		else
			bottom_node->parent->right = NULL;
	}
	else
		heap->root = NULL;
	free(bottom_node);
	shift_down(heap);
	heap->size -= 1;
	return (root_dt);
}

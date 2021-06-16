#include "huffman.h"

/**
 * huffman_extract_and_insert - entry to extract huffman function
 * Desc: huffman_extract_and_insert function that extracts the two nodes
 * of the priority queue and insert a new node
 * @priority_queue: pointer to the priority queue node to extract
 * Return: 1 on success or 0 on failure
 */
int huffman_extract_and_insert(heap_t *priority_queue)
{
	binary_tree_node_t *node, *left, *right;
	size_t sum;
	symbol_t *symbol;

	if (!priority_queue || priority_queue->size < 2)
		return (0);

	left = heap_extract(priority_queue);
	right = heap_extract(priority_queue);
	sum = ((symbol_t *)left->data)->freq;
	sum += ((symbol_t *)right->data)->freq;
	symbol = symbol_create(-1, sum);

	if (!symbol)
		return (0);

	left->parent = right->parent = node = binary_tree_node(NULL, symbol);
	node->left = left;
	node->right = right;

	if (heap_insert(priority_queue, node) != NULL)
		return (0);

	return (1);
}

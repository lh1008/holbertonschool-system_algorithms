#include "huffman.h"

/**
 * data_cmp - entry to data cmp
 * Desc: data_cmp function that compares freq data in symbol struct
 * @node_a: first node containing a symbol struct
 * @node_b: second node containing a symbol struct
 * Return: difference of the frequencies
 */
int data_cmp(void *node_a, void *node_b)
{
	symbol_t *symbol_a, *symbol_b;

	symbol_a = ((binary_tree_node_t *)node_a)->data;
	symbol_b = ((binary_tree_node_t *)node_b)->data;

	return (symbol_a->freq - symbol_b->freq);
}

/**
 * huffman_priority_queue - entry to huffman priority queue
 * Desc: huffman_priority_queue function that creates a priority
 * queue for the Huffman coding algorithm
 * @data: char pointer array of characters of size size
 * @freq: size_t pointer array containing associated frequencies
 * @size: size_t size
 * Return: pointer to the created min heap
 */
heap_t *huffman_priority_queue(char *data, size_t *freq, size_t size)
{
	heap_t *heap;
	symbol_t *symbol;
	binary_tree_node_t *node;
	size_t i;

	heap = heap_create(data_cmp);
	for (i = 0; i < size; i++)
	{
		symbol = symbol_create(data[i], freq[i]);
		node = binary_tree_node(NULL, symbol);
		node = heap_insert(heap, node);
	}

	return (heap);
}

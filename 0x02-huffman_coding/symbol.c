#include "huffman.h"

/**
 * symbol_create - entry to symbol create
 * Desc: symbol_create function that creates a symbol_t data structure
 * @data: char type data to be storedin the structure
 * @freq: size_t type associated frequency
 * Return: pointer to the created structure, or NULL if it fails
 */
symbol_t *symbol_create(char data, size_t freq)
{
	symbol_t *node;

	node = malloc(sizeof(symbol_t));

	if (node == NULL)
		return (NULL);

	node->data = data;
	node->freq = freq;

	return (node);
}

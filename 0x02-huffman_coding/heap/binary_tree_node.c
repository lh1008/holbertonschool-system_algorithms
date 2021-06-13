#include "heap.h"

/**
 * binary_tree_node - entry to binary tree node
 * Desc: binary_tree_node function that creates a generic Binary Tre node
 * @parent: pointer to the parent node of the node to be created
 * @data: data pointer to be stored in the node
 * Return: return pointer to the created node or NULL if it fails.
 */
binary_tree_node_t *binary_tree_node(binary_tree_node_t *parent, void *data)
{
	binary_tree_node_t *new_node;

	new_node = malloc(sizeof(binary_tree_node_t));

	if (new_node == NULL)
		return (NULL);

	new_node->data = data;
	new_node->parent = parent;
	new_node->left = NULL;
	new_node->right = NULL;

	return (new_node);
}

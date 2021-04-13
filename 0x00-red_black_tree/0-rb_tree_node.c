#include "rb_trees.h"

/**
 * rb_tree_node - entry to rb_tree_node
 * Desc: rb_tree_node function that creates a Red-Black Tree node
 * @parent: pointer to the parent node of the node to create
 * @value: value to out in the new node
 * @color: color of the node
 * Return: pointer to the new node, or NULL on failure
 */
rb_tree_t *rb_tree_node(rb_tree_t *parent, int value, rb_color_t color)
{
	rb_tree_t *new_parent;

	new_parent = malloc(sizeof(rb_tree_t));
	if (new_parent == NULL)
		return (NULL);

	new_parent->n = value;
	new_parent->left = NULL;
	new_parent->right = NULL;
	new_parent->parent = parent;

	return (new_parent);
}

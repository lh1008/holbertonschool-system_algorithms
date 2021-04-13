#include "rb_trees.h"

/**
 * rb_tree_is_valid - entry to rb_tree_is_valid
 * Desc: rb_tree_is_valid function that checks if a binary tree is valid
 * @tree: struct pointer to tree
 * Return: 1 if tree is valid, 0 if not
 */
int rb_tree_is_valid(const rb_tree_t *tree)
{
	int black = 0;

	if (tree == NULL || tree->color == RED)
		return (0);

	if (!tree)
	{
		black = 1;
		return (black);
	}

	if (tree->color != RED && tree->color != BLACK)
		return (0);

	if (tree->color == RED)
	{
		if (tree->left && tree->left->color == RED)
			return (0);
		if (tree->right && tree->right->color == RED)
			return (0);
	}

	if (tree->color == BLACK)
		black += 1;

	return (1);
}

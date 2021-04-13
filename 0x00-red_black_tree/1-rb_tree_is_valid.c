#include "rb_trees.h"

/**
 * rb_tree_is_valid - entry to rb_tree_is_valid
 * Desc: rb_tree_is_valid function that checks if a binary tree is valid
 * @tree: struct pointer to tree
 * Return: 1 if tree is valid, 0 if not
 */
int rb_tree_is_valid(const rb_tree_t *tree)
{
	int black, right, left;

	black = right = left = 0;

	if (tree == NULL)
		return (0);

	if (tree->left != NULL)
		left = rb_tree_is_valid(tree->left);
	else
		left = 1;
	if (tree->right != NULL)
		right = rb_tree_is_valid(tree->right);
	else
		right = 1;

	if (right == left)
	{
		black = right;
		if (tree->color == BLACK)
			black += 1;
	}
	else
		black = 0;

	if (tree->parent == NULL && tree->color != BLACK)
		black = 0;

	if (tree->color != RED && tree->color != BLACK)
		black = 0;

	if (tree->parent && tree->color == RED && tree->parent->color == RED)
		black = 0;

	if (tree->parent == NULL && black != 0)
		return (1);
	return (black);
}

#include "nary_trees.h"

/**
 * nary_tree_delete - entry to function
 * Desc: nary_tree_delete function that deallocates
 * an entire N-ary tree
 * @tree: pointer to tree struct node
 * Return: nothing, void function
 */
void nary_tree_delete(nary_tree_t *tree)
{
	nary_tree_t *next_node = NULL, *children = NULL;

	if (tree == NULL)
		return;

	children = tree->children;
	while (children)
	{
		nary_tree_delete(children->children);
		free(children->content);
		next_node = children->next;
		free(children);
		children = next_node;
	}
	free(tree->content);
	free(tree);
}

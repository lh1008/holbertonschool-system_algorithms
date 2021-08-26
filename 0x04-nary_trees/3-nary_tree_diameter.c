#include "nary_trees.h"

static size_t diameter;

/**
 * nary_max_height - entry to function
 * Desc: nary_max_height function that finds
 * the max height of N-ary tree
 * @root: pointer to current root of subtree
 * Return: max height of this root
 */
size_t nary_max_height(nary_tree_t const *root)
{
	size_t max1 = 0, max2 = 0, h;
	nary_tree_t *child;

	if (!root)
		return (0);

	for (child = root->children; child; child = child->next)
	{
		h = nary_max_height(child);
		if (h > max1)
			max2 = max1, max1 = h;
		else if (h > max2)
			max2 = h;
	}
	diameter = MAX(diameter, max1 + max2);
	return (MAX(max1, max2) + 1);
}

/**
 * nary_tree_diameter - entry to function
 * Desc: nary_tree_diameter function that computes
 * the diameter of an N-ary tree
 * @root: pointer to root node
 * Return: diameter of the tree pointed to by root
 */
size_t nary_tree_diameter(nary_tree_t const *root)
{
	if (!root)
		return (0);
	nary_max_height(root);
	return (diameter + 1);
}

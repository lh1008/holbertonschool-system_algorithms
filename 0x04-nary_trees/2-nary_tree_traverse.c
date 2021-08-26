#include "nary_trees.h"

/**
 * get_depth_nary - entry to function
 * Desc: get_depth_nary function that gets
 * max depth of a nary tree
 * @root: root node of the nary tree
 * @d: current depth
 * @action: function pointer to make an action while traverse
 * Return: the max depth
 */
size_t get_depth_nary(nary_tree_t const *root, size_t d,
		void (*action)(nary_tree_t const *node, size_t depth))
{
	nary_tree_t *children = NULL;
	size_t max_d = 0, cd = 0;

	action(root, d);
	children = root->children;
	max_d = d;
	while (children)
	{
		cd = get_depth_nary(children, d + 1, action);
		if (cd > max_d)
			max_d = cd;
		children = children->next;
	}

	return (max_d);
}

/**
 * nary_tree_traverse - entry to function
 * Desc: nary_tree_traverse function that goes
 * through an N-ary tree, node by node
 * @root: pointer to the root node of the tree to traverse
 * @action: pointer to function to traverse each node
 * Return: biggest depth of the tree pointed to by root
 */
size_t nary_tree_traverse(nary_tree_t const *root,
			  void (*action)(nary_tree_t const *node, size_t depth))
{
	if (root == NULL)
		return (0);

	return (get_depth_nary(root, 0, action));
}

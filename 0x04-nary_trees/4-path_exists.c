#include "nary_trees.h"

/**
 * check_path - entry to function
 * Desc: check_path function to check if a path exists
 * @root: pointer to the root node of the tree
 * @path: pointer to a NULL terminated array of strings.
 * Return: return 1 if all elements in path present.
 */
int check_path(nary_tree_t const *root, char const * const *path)
{
	nary_tree_t const *n = NULL;

	if (*path == NULL)
		return (1);
	if (root == NULL)
		return (0);

	n = root;
	while (n)
	{
		if (strcmp(*path, n->content) == 0)
			if (check_path(n->children, path + 1) == 1)
				return (1);
		n = n->next;
	}

	return (0);
}

/**
 * path_exists - entry to function
 * Desc: path_exists function that checks if
 * a path exists in a N-ary tree
 * @root: pointer to the root node of the tree
 * @path: pointer to a NULL terminated array of strings.
 * Return: return 1 if all elements in path present.
 */
int path_exists(nary_tree_t const *root, char const * const *path)
{
	if (root == NULL || path == NULL)
		return (0);
	return (check_path(root, path));
}

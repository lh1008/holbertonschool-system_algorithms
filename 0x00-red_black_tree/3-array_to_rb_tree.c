#include "rb_trees.h"

/**
 * array_to_rb_tree - entry to arrat_to_rb_tree
 * Desc: array_to_rb_tree function that builds a Red-Black Tree
 * from an array
 * @array: array of integers, may be unsorted and have repeating values
 * @size: amount of array members
 * Return: pointer to root node of the created R-B tree, or NULL if failure
 */
rb_tree_t *array_to_rb_tree(int *array, size_t size)
{
	rb_tree_t *tree = NULL;
	size_t i, j;

	if (array == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
	{

		if (rb_tree_insert(&tree, array[i]) == NULL)
		{
			for (j = 0; j < size && array[j] != array[i]; j++)
				;

			if (j == i)
				return (NULL);
		}
	}
	return (tree);
}

#include "nary_trees.h"

/**
 * nary_node_creation - entry to function
 * Desc: nary_node_creation that creates nary node
 * Return: new node created
 */
nary_tree_t *nary_node_creation(void)
{
	nary_tree_t *new_node = NULL;

	new_node = malloc(sizeof(nary_tree_t));
	if (new_node == NULL)
		return (NULL);

	new_node->content = NULL;
	new_node->parent = NULL;
	new_node->nb_children = 0;
	new_node->children = NULL;
	new_node->next = NULL;

	return (new_node);
}

/**
 * nary_tree_insert - entry to function
 * Desc: nary_tree_insert function that
 * inserts a node in a N-ary tree.
 * @parent: pointer to the parent node
 * @str: pointer char const string
 * Return: a pointer to the created node, or NULL on failure
 */
nary_tree_t *nary_tree_insert(nary_tree_t *parent, char const *str)
{
	nary_tree_t *new_node = NULL;

	new_node = nary_node_creation();
	if (new_node == NULL)
		return (NULL);

	new_node->content = strdup(str);
	if (parent == NULL)
		return (new_node);

	new_node->parent = parent;
	new_node->next = parent->children;

	parent->children = new_node;
	parent->nb_children++;

	return (new_node);
}

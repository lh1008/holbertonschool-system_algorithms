#include "heap.h"

/**
 * heapify - entry to heapify
 * Desc: heapify function that heapifies a binary tree
 * @heap: pointer to heap
 * @node_insert: new node that was just inserted
 * Return: node_insert
 */
binary_tree_node_t *heapify(heap_t *heap, binary_tree_node_t *node_insert)
{
	void *temp_node;

	if (!node_insert)
		return (NULL);

	while (node_insert->parent)
	{
		if (heap->data_cmp(node_insert->parent->data,
				   node_insert->data) > 0)
		{
			temp_node = node_insert->data;
			node_insert->data = node_insert->parent->data;
			node_insert->parent->data = temp_node;
		}
		node_insert = node_insert->parent;
	}
	return (node_insert);
}

/**
 * ith_node - entry to ith_node
 * Desc: ith_node funtciont that finds ith node of binary tree
 * @root: pointer to root node
 * @i: ith node to find
 * Return: pointer to root node or NULL if failed
 */
binary_tree_node_t *ith_node(binary_tree_node_t *root, int i)
{
	int index, mask;

	if (!root || i <= 0)
		return (NULL);

	for (index = 0; 1 << (index + 1) <= (int)i; index++)
		;
	for (--index; index >= 0; --index)
	{
		mask = 1 << index;
		if (i & mask)
		{
			if (root->right)
				root = root->right;
			else
				break;
		}
		else
		{
			if (root->left)
				root = root->left;
			else
				break;
		}
	}
	return (root);
}

/**
 * heap_insert - entry to heap insert
 * Desc: heap_insert function that inserts a value
 * in a Min Binary Heap
 * @heap: pointer to the heap in which the node has to be inserted
 * @data: pointer containing the datato store in the new node
 * Return: return a pointer to the creatednode containing data,
 * or NULL if it fails
 */
binary_tree_node_t *heap_insert(heap_t *heap, void *data)
{
	binary_tree_node_t *node_insert, *parent_node;

	if (!heap || !data)
		return (NULL);

	node_insert = binary_tree_node(NULL, data);

	if (!node_insert)
		return (NULL);

	if (heap->root == NULL)
	{
		heap->root = node_insert;
		heap->size += 1;
	}
	else
	{
		heap->size += 1;
		parent_node = ith_node(heap->root, heap->size);

		if (!parent_node->left)
			parent_node->left = node_insert;
		else
			parent_node->right = node_insert;

		node_insert->parent = parent_node;

	}

	heapify(heap, node_insert);

	return (node_insert);
}

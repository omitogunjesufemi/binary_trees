#include "binary_trees.h"

/**
 * binary_tree_sibling - A function that finds the sibling of a node
 * @node: Pointer to the node to find the sibling
 * Return: pointer to the sibling node
 * If node is NULL or the parent is NULL, return NULL
 * If node has no sibling, return NULL
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	binary_tree_t *sibling_1, *sibling_2, *parent;

	if (node == NULL)
		return (NULL);

	parent = node->parent;
	if (parent == NULL)
		return (NULL);

	sibling_1 = parent->left;
	sibling_2 = parent->right;

	if (sibling_1 == NULL)
		return (NULL);
	if (sibling_2 == NULL)
		return (NULL);

	if (sibling_1 == node)
		return (sibling_2);
	return (sibling_1);
}

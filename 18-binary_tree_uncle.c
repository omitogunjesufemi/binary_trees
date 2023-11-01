#include "binary_trees.h"

/**
 * binary_tree_uncle - Function finds the uncle of a node
 * @node: Pointer to the node to find the node
 * Return: Pointer to the uncle node
 * If node is NULL, return NULL
 * If node has no uncle return NULL
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t *parent, *g_parent, *g_parent_child_1,
		*g_parent_child_2;

	if (node == NULL)
		return (NULL);

	parent = node->parent;
	if (parent == NULL)
		return (NULL);

	g_parent = parent->parent;
	if (g_parent == NULL)
		return (NULL);

	g_parent_child_1 = g_parent->left;
	g_parent_child_2 = g_parent->right;

	if (g_parent_child_1 == NULL)
		return (NULL);
	if (g_parent_child_2 == NULL)
		return (NULL);

	if (g_parent_child_1 == parent)
		return (g_parent_child_2);
	return (g_parent_child_1);
}

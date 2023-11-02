#include "binary_trees.h"


binary_tree_t *lowest_common_ancestor(const binary_tree_t *root,
				      const binary_tree_t *first,
				      const binary_tree_t *second);

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes
 * @first: Pointer to the first node
 * @second: Pointer to the second node
 * Return: Pointer to the lowest common ancestor node of the two nodes
 * If no common ancestor was found, your function must return NULL
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second)
{
	const binary_tree_t *root;

	if (first == NULL || second == NULL)
		return (NULL);

	if (first->parent == NULL)
	{
		return ((binary_tree_t *)first);
	}

	if (second->parent == NULL)
	{
		return ((binary_tree_t *)second);
	}

	root = first;
	while (root->parent != NULL)
	{
		root = root->parent;
	}

	return (lowest_common_ancestor(root, first, second));
}

/**
 * lowest_common_ancestor - Recursive check for the lowest common ancestor
 * @root: Root of the binary tree
 * @first: Pointer to the first node
 * @second: Pointer to the second node
 * Return: Pointer to the lowest common ancestor node of the two nodes
 * If no common ancestor was found, your function must return NULL
 */

binary_tree_t *lowest_common_ancestor(const binary_tree_t *root,
				      const binary_tree_t *first,
				      const binary_tree_t *second)
{
	binary_tree_t *left, *right;

	if (root == NULL || root == first || root == second)
		return ((binary_tree_t *)root);

	left = lowest_common_ancestor(root->left, first, second);
	right = lowest_common_ancestor(root->right, first, second);

	if (left == NULL)
		return ((binary_tree_t *)right);
	else if (right == NULL)
		return ((binary_tree_t *)left);
	else
		return ((binary_tree_t *)root);
}

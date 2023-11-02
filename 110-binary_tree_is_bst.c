#include "binary_trees.h"

int is_bst(const binary_tree_t *tree, int max_value, int min_value);

/**
 * binary_tree_is_bst - Checks if a binary tree is a valid Binary Search Tree
 * @tree: Pointer to the root node of the tree to check
 * Return: 1 if tree is a valid BST, 0 otherwise
 * If tree is NULL, return 0
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (is_bst(tree, INT_MAX, INT_MIN));
}

/**
 * is_bst - Recursively checks if the left subtree is lesser and right
 * subtree is greater
 * @tree: Subtree to be checked
 * @max_value: The maximum limit of the subtree
 * @min_value: The minimum limit of the subtree
 */
int is_bst(const binary_tree_t *tree, int max_value, int min_value)
{
	int l_flag, r_flag;

	if (tree == NULL)
		return (1);

	if (tree->n > max_value || tree->n < min_value)
		return (0);

	l_flag = is_bst(tree->left, tree->n, min_value);
	r_flag = is_bst(tree->right, max_value, tree->n);

	return (l_flag && r_flag);
}

#include "binary_trees.h"

void tree_is_full(const binary_tree_t *tree, int *flag);

/**
 * binary_tree_is_full - Checks if a binary tree is full
 * @tree: Pointer to the root node of the tree to check
 * Return: 1 if balanced, 0 if otherwise
 * If tree is NULL, your function must return 0
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	int flag;

	flag = 1;
	if (tree == NULL)
		return (0);
	tree_is_full(tree, &flag);
	return (flag);
}

void tree_is_full(const binary_tree_t *tree, int *flag)
{
	if (tree == NULL)
		return;

	tree_is_full(tree->left, flag);
	tree_is_full(tree->right, flag);

	if ((tree->left == NULL && tree->right != NULL)
	    || (tree->left != NULL && tree->right == NULL))
		*flag = 0;
}

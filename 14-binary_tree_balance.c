#include "binary_trees.h"

int tree_height(const binary_tree_t *tree);

/**
 * binary_tree_balance - A function that measures the balance factor of
 * a binary tree
 * @tree: Pointer to the root node of the tree to measure the balance factor
 * If tree is NULL return 0
 * Return: Balance factor
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int l_sub_tree, r_sub_tree, balance_factor;

	if (tree == NULL)
		return (0);

	l_sub_tree = tree_height(tree->left);
	r_sub_tree = tree_height(tree->right);

	balance_factor = l_sub_tree - r_sub_tree;
	return (balance_factor);
}

/**
 * tree_height - A function that measures the height of a tree
 * @tree: Pointer to the root node of the tree to measure the height
 * If tree is NULL return 0
 * Return: Height of tree
 */
int tree_height(const binary_tree_t *tree)
{
	int l_height, r_height, max;

	if (tree == NULL)
		return (0);
	l_height = tree_height(tree->left);
	r_height = tree_height(tree->right);

	if (l_height > r_height)
		max = l_height;
	else
		max = r_height;
	return (max + 1);
}

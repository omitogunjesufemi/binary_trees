#include "binary_trees.h"

/**
 * binary_tree_rotate_right - Performs a right rotation on a binary tree
 * @tree: Pointer to the root node of the tree to rotate
 * Return: Pointer to the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *old_root, *new_root, *old_right;

	if (tree == NULL)
		return (NULL);
	old_root = tree;
	new_root = tree->left;
	old_right = tree->left->right;

	if (old_right != NULL)
		old_right->parent = old_root;
	old_root->left = old_right;
	new_root->right = old_root;

	old_root->parent = new_root;
	new_root->parent = NULL;

	return (new_root);
}

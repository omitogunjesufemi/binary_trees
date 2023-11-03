#include "binary_trees.h"

/**
 * bst_search - Searches for a value in a Binary Search Tree
 * @tree: Pointer to the root node of the BST to search
 * @value: Value to search in the tree
 * Return: Pointer to the node containing a value eqaul to value
 * If tree is NULL or if nothing is found return NULL
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	if (tree == NULL)
		return (NULL);

	else if (value < tree->n)
	{
		return (bst_search(tree->left, value));
	}

	else if (value > tree->n)
	{
		return (bst_search(tree->right, value));
	}
	else
	{
		return ((bst_t *)tree);
	}
}

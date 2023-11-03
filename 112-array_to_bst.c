#include "binary_trees.h"

/**
 * array_to_bst - Function that builds a BST from an array
 * @array: Pointer to the first element of the array to be converted
 * @size: Number of element in the array
 * Return: Pointer to the root node of the created BST, or NULL on
 * failure
 * If a value of the array is already present in the tree, it should be
 * ignored
 */
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *root;
	size_t i;

	if (size == 0 || array == NULL)
		return (NULL);
	root = NULL;
	root = bst_insert(&root, array[0]);
	for (i = 1; i < size; i++)
	{
		bst_insert(&root, array[i]);
	}

	return (root);
}

#include "binary_trees.h"

bst_t *insert_bst_node(bst_t **tree, int value, bst_t **node);

/**
 * bst_insert - Inserts a value in a Binary Search Tree
 * @tree: A double pointer to the root node of the BST to insert the value
 * @value: Value to store in the node to be inserted
 * Return: Pointer to the created node, or NULL on failure
 * If the address stored in tree is NULL, the created node must become the
 * root node
 * If the value is already present in the tree, it must be ignored
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *node;

	insert_bst_node(tree, value, &node);
	return (node);
}

/**
 * insert_bst_node - Recursively Inserts a value in a Binary Search Tree
 * @tree: A double pointer to the root node of the BST to insert the value
 * @value: Value to store in the node to be inserted
 * @node: The pointer to the node that was added
 * Return: Pointer to the created node, or NULL on failure
 * If the address stored in tree is NULL, the created node must become the
 * root node
 * If the value is already present in the tree, it must be ignored
 */
bst_t *insert_bst_node(bst_t **tree, int value, bst_t **node)
{
	if (*tree == NULL)
	{
		*tree = binary_tree_node(*tree, value);
		*node = *tree;
		if (*tree == NULL)
			return (NULL);
	}

	else if (value < (*tree)->n)
	{
		(*tree)->left = insert_bst_node(&((*tree)->left),
						value, node);
		(*tree)->left->parent = *tree;
	}

	else if (value > (*tree)->n)
	{
		(*tree)->right = insert_bst_node(&((*tree)->right),
						 value, node);
		(*tree)->right->parent = *tree;
	}

	else
	{
		*node = NULL;
	}

	printf("Tree Value: %d\n", (*tree)->n);
	return (*tree);
}

#include "binary_trees.h"

/**
 * binary_tree_insert_right - Inserts a node as the right child of
 * another node
 * @parent: Pointer to the node to insert the right child in
 * @value: Value to store in the new node
 * Return: Pointer to the created node, or NULL on failure or if parent
 * is NULL
 * If parent already has a right-child, the new node must take its place
 * and the old right-child must be set as the right-child of the new node
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;
	binary_tree_t *temp;

	new_node = malloc(sizeof(binary_tree_t));
	if (new_node == NULL || parent == NULL)
		return (NULL);

	new_node->n = value;
	new_node->parent = parent;
	new_node->right = NULL;
	new_node->left = NULL;

	if (parent->right == NULL)
		parent->right = new_node;
	else
	{
		temp = parent->right;
		parent->right = new_node;
		new_node->right = temp;
		temp->parent = new_node;
	}

	return (new_node);
}

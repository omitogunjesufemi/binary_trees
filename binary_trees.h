#ifndef _BINARY_TREES_H_
#define _BINARY_TREES_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
};
typedef struct binary_tree_s bst_t;

typedef struct binary_tree_s binary_tree_t;

void binary_tree_print(const binary_tree_t *);

/**
 * binary_tree_node - Creates a binary tree node
 * @parent: a pointer to the parent node of the node to create
 * @value: the value to put in the new node
 * Created node does not have any child
 * Return: pointer to the new node or NULL on failure
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);

/**
 * binary_tree_insert_left - A function that inserts a node as the
 * left-child of another node
 * @parent: A pointer to the node to insert the left-child in
 * @value: The value to store in the new node
 * Return: Pointer to the created node, or NULL on failure, or if
 * parent is NULL
 * If parent already has a left-child, the new node must take its place,
 * and the old left-child must be set as the left-child of the new node
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value);

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
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value);

/**
 * binary_tree_delete - Deletes an entire binary tree
 * @tree: Pointer to the root node of the tree to delete
 * If tree is NULL, do nothing
 */
void binary_tree_delete(binary_tree_t *tree);

#endif /* _BINARY_TREES_H_ */

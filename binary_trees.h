#ifndef _BINARY_TREES_H_
#define _BINARY_TREES_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <limits.h>

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
typedef struct binary_tree_s avl_t;
typedef struct binary_tree_s heap_t;
typedef struct binary_tree_s binary_tree_t;

struct queue_s
{
	const binary_tree_t *tree;
	struct queue_s *next;
};
typedef struct queue_s queue;

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

/**
 * binary_tree_is_leaf - Checks if a node is a leaf
 * @node: Pointer to the node to check
 * Return: 1 if node is a leaf, otherwise 0. If node is NULL return 0
 */
int binary_tree_is_leaf(const binary_tree_t *node);

/**
 * binary_tree_is_root - Checks if a given node is a root
 * @node: Pointer to the node to check
 * Return: 1 if node is root, otherwise 0. If node is NULL, return 0
 */
int binary_tree_is_root(const binary_tree_t *node);

/**
 * binary_tree_preorder - A function that goes through a binary tree using
 * pre-order traversal
 * @tree: A pointer to the root node of the tree to traverse
 * @func: A pointer to a function to call for each node. The value in the
 * node must be passed as a parameter to this function.
 * If tree or func is NULL, do nothing
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int));

/**
 * binary_tree_inorder - A function that goes through a binary tree using
 * inorder traversal
 * @tree: A pointer to the root node of the tree to traverse
 * @func: A pointer to a function to call for each node. The value in the node
 * must be passed as a parameter to this function
 * If tree or func is NULL, do nothing
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int));

/**
 * binary_tree_postorder - A function that goes through a binary tree using
 * postorder traversal
 * @tree: A pointer to the root node of the tree to traverse
 * @func: A pointer to a function to call for each node. The value in the node
 * must be passed as a parameter to this function
 * If tree or func is NULL, do nothing
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int));

/**
 * binary_tree_height - A function that measures the height of a binary tree
 * @tree: A pointer to the root node of the tree to measure the height
 * Return: Measured height of tree
 * If tree is NULL, return 0
 */
size_t binary_tree_height(const binary_tree_t *tree);

/**
 * binary_tree_depth - A function that measures the depth of a node in
 * a binary tree
 * @tree: A pointer to the node to measure the depth
 * Return: Depth of the node
 * If tree is NULL, your function must return 0
 */
size_t binary_tree_depth(const binary_tree_t *tree);

/**
 * binary_tree_size - A function that measures the size of a binary tree
 * @tree: A pointer to the root node of the tree to measure the size
 * Return: Depth of a node
 * If tree is NULL, the function must return 0
 */
size_t binary_tree_size(const binary_tree_t *tree);

/**
 * binary_tree_leaves - A function that counts the leaves in a binary tree
 * @tree: A pointer to the root node of the tree to count the number of leaves
 * Return: Number of leaves in a binary tree
 * If tree is NULL, the function must return 0
 * A NULL pointer is not a leaf
 */
size_t binary_tree_leaves(const binary_tree_t *tree);

/**
 * binary_tree_nodes - A function that counts the nodes with atleast 1 child
 * @tree: A pointer to the root node of the tree to count the number of nodes
 * If tree is NULL, the function must return 0
 * A NULL pointer is not a node
 */
size_t binary_tree_nodes(const binary_tree_t *tree);

/**
 * binary_tree_balance - A function that measures the balance factor of
 * a binary tree
 * @tree: Pointer to the root node of the tree to measure the balance factor
 * If tree is NULL return 0
 * Return: Balance factor
 */
int binary_tree_balance(const binary_tree_t *tree);

/**
 * binary_tree_is_full - Checks if a binary tree is full
 * @tree: Pointer to the root node of the tree to check
 * Return: 1 if balanced, 0 if otherwise
 * If tree is NULL, your function must return 0
 */
int binary_tree_is_full(const binary_tree_t *tree);

/**
 * bianry_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: Pointer to the root node of the tree to check
 * Return: 1 if perfect, and 0 if otherwise
 * If tree is NULL, function must return 0
 */
int binary_tree_is_perfect(const binary_tree_t *tree);

/**
 * binary_tree_sibling - A function that finds the sibling of a node
 * @node: Pointer to the node to find the sibling
 * Return: pointer to the sibling node
 * If node is NULL or the parent is NULL, return NULL
 * If node has no sibling, return NULL
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node);

/**
 * binary_tree_uncle - Function finds the uncle of a node
 * @node: Pointer to the node to find the node
 * Return: Pointer to the uncle node
 * If node is NULL, return NULL
 * If node has no uncle return NULL
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node);

/**
 * binary_tree_levelorder - Function that goes through a binary tree using
 * level-order traversal
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node.
 * The value in the node must be passed as a parameter to this function
 * If tree or func is NULL, do nothing
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int));

/**
 * binary_tree_rotate_left - Performs a left rotation on a binary tree
 * @tree: Pointer to the root node of the tree to rotate
 * Return: Pointer to the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree);

/**
 * binary_tree_rotate_right - Performs a right rotation on a binary tree
 * @tree: Pointer to the root node of the tree to rotate
 * Return: Pointer to the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree);

/**
 * binary_tree_is_complete - Function checks if a binary tree is complete
 * @tree: Pointer to the root node of the tree to check
 * Return: 1 if complete, 0 if otherwise
 * If tree is NULL, your function must return 0
 */
int binary_tree_is_complete(const binary_tree_t *tree);

/**
 * binary_tree_is_bst - Checks if a binary tree is a valid Binary Search Tree
 * @tree: Pointer to the root node of the tree to check
 * Return: 1 if tree is a valid BST, 0 otherwise
 * If tree is NULL, return 0
 */
int binary_tree_is_bst(const binary_tree_t *tree);

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes
 * @first: Pointer to the first node
 * @second: Pointer to the second node
 * Return: Pointer to the lowest common ancestor node of the two nodes
 * If no common ancestor was found, your function must return NULL
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second);

/**
 * bst_insert - Inserts a value in a Binary Search Tree
 * @tree: A double pointer to the root node of the BST to insert the value
 * @value: Value to store in the node to be inserted
 * Return: Pointer to the created node, or NULL on failure
 * If the address stored in tree is NULL, the created node must become the
 * root node
 * If the value is already present in the tree, it must be ignored
 */
bst_t *bst_insert(bst_t **tree, int value);

#endif /* _BINARY_TREES_H_ */

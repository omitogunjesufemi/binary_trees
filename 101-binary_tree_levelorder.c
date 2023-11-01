#include "binary_trees.h"

queue *create_node(const binary_tree_t *tree);
void enqueue(queue **first, queue **last, const binary_tree_t *tree);
void dequeue(queue **first, queue **last);

/**
 * binary_tree_levelorder - Function that goes through a binary tree using
 * level-order traversal
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node.
 * The value in the node must be passed as a parameter to this function
 * If tree or func is NULL, do nothing
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	queue *first, *last;

	if (tree == NULL || func == NULL)
		return;
	first = NULL, last = NULL;
	enqueue(&first, &last, tree);

	while (first != NULL && last != NULL)
	{
		func(first->tree->n);
		if (first->tree->left != NULL)
			enqueue(&first, &last, first->tree->left);
		if (first->tree->right != NULL)
			enqueue(&first, &last, first->tree->right);
		dequeue(&first, &last);
	}
}

/**
 * create_node - Creates Queue node
 * @tree: Pointer to tree node
 * Return: Queue node created
 */
queue *create_node(const binary_tree_t *tree)
{
	queue *node;

	node = malloc(sizeof(queue));
	if (node == NULL)
		return (NULL);

	node->tree = tree;
	node->next = NULL;

	return (node);
}

/**
 * enqueue - For enqueing tree nodes in the queue
 * @first: Exit point of queue
 * @last: Entry point of queue
 * @tree: tree data to put in queue
 */
void enqueue(queue **first, queue **last, const binary_tree_t *tree)
{
	queue *node;

	node = create_node(tree);
	if (node == NULL)
		return;

	if (*last == NULL)
		*first = node;
	else
		(*last)->next = node;
	*last = node;
}

/**
 * dequeue - For dequeing tree nodes in the queue
 * @first: Exit point of queue
 * @last: Entry point of queue
 */
void dequeue(queue **first, queue **last)
{
	queue *temp;

	temp = *first;
	*first = (*first)->next;
	free(temp);

	if (*first == NULL)
		*last = NULL;
}

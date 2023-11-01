#include "binary_trees.h"

queue *create_node(const binary_tree_t *tree);
void enqueue(queue **first, queue **last, const binary_tree_t *tree);
void dequeue(queue **first, queue **last);


/**
 * binary_tree_is_complete - Function checks if a binary tree is complete
 * @tree: Pointer to the root node of the tree to check
 * Return: 1 if complete, 0 if otherwise
 * If tree is NULL, your function must return 0
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	queue *first, *last;
	int count;

	count = 0;
	first = NULL, last = NULL;
	enqueue(&first, &last, tree);
	while (first != NULL && last != NULL)
	{
		if (first->tree->left != NULL)
		{
			enqueue(&first, &last, first->tree->left);
			if (count)
				return (0);
		}
		else
			count++;
		if (first->tree->right != NULL)
		{
			enqueue(&first, &last, first->tree->right);
			if (count)
				return (0);
		}
		else
			count++;

		dequeue(&first, &last);
	}
	return (1);
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

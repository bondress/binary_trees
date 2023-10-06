#include "binary_trees.h"

/**
 * bst_insert - inserts a value in a Binary Search Tree
 * @tree: double pointer to the root node of the BST
 * @value: value to store in the node to be inserted
 * Return: pointer to the created node, NULL on failure;
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *t = NULL;
	bst_t *sec = NULL;
	bst_t *nw = NULL;

	if (!tree)
		return (NULL);
	if (*tree == NULL)
		return (*tree = binary_tree_node(NULL, value));

	t = *tree;
	while (t)
	{
		sec = t;
		if (value < t->n)
			t = t->left;
		else if (value > t->n)
			t = t->right;
		else if (value == t->n)
			return (NULL);
	}

	nw = binary_tree_node(NULL, value);
	if (sec == NULL)
		sec = nw;
	else if (value < sec->n)
	{
		sec->left = nw;
		nw->parent = sec;
	}
	else
	{
		sec->right = nw;
		nw->parent = sec;
	}

	return (nw);
}

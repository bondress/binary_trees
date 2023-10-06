#include "binary_trees.h"

/**
 * binary_tree_rotate_left - performs a left-rotation on a binary tree.
 * @tree: root node of the tree
 * Return: pointer node of the new node
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *pvt;

	if (tree == NULL || tree->right == NULL)
	{
		return (NULL);
	}
	pvt = tree->right;
	tree->right = pvt->left;
	if (pvt->left != NULL)
	{
		pvt->left->parent = tree;
	}
	pvt->left = tree;
	pvt->parent = tree->parent;
	tree->parent = pvt;
	return (pvt);
}

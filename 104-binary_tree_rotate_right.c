#include "binary_trees.h"

/**
 * binary_tree_rotate_right - performs a right-rotation on a binary tree.
 * @tree: root node of the tree
 * Return: pointer node of the new node
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *pvt;

	if (tree == NULL || tree->left == NULL)
	{
		return (NULL);
	}
	pvt = tree->left;
	tree->left = pvt->right;
	if (pvt->right != NULL)
	{
		pvt->right->parent = tree;
	}
	pvt->right = tree;
	pvt->parent = tree->parent;
	tree->parent = pvt;
	return (pvt);
}

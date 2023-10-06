#include "binary_trees.h"

/**
 * binary_tree_is_bst - checks if a binary tree is a valid Binary Search Tree
 * @tree: pointer to root node of tree to check
 *
 * Return: 1 if tree is a valid BST, 0 if otherwise.
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (helper_3(tree, INT_MIN, INT_MAX));
}

/**
 * helper_3 - checks if a binary tree is a valid Binary Search Tree
 * @tree: pointer to root node of tree to check
 * @min: lower bound of checked nodes
 * @max: upper bound of checked nodes
 *
 * Return: 1 if tree is a valid BST, 0 if otherwise.
 */
int helper_3(const binary_tree_t *tree, int min, int max)
{
	if (!tree)
		return (1);

	if (tree->n < min || tree->n > max)
		return (0);

	return (helper_3(tree->left, min, tree->n - 1) &&
		helper_3(tree->right, tree->n + 1, max));
}

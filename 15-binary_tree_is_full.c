#include "binary_trees.h"

/**
 * binary_tree_is_full - checks if a binary tree is full
 * @tree: pointer to root node of tree to check
 *
 * Return: 1 if the tree is full, 0 if the tree is not full
 * and 0 if tree is NULL
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	if (!tree->left && !tree->right)
		return (1);

	if (tree->right && tree->left)
		return (binary_tree_is_full(tree->right) &&
			binary_tree_is_full(tree->left));

	return (0);
}

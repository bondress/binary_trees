#include "binary_trees.h"

/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: pointer to root node of tree to check
 *
 * Return: 1 if the tree is complete, 0 if the tree is not complete
 * or 0 if tree is NULL.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t sz;

	if (!tree)
		return (0);
	sz = binary_tree_size(tree);

	return (helper_2(tree, 0, sz));
}

/**
 * helper_2 - checks if a binary tree is complete
 * @tree: pointer to root node of tree to check
 * @index: node index to check
 * @size: number of nodes in the tree
 *
 * Return: 1 if the tree is complete, 0 if the tree is not complete
 * or 0 if tree is NULL
 */
int helper_2(const binary_tree_t *tree, size_t index, size_t size)
{
	if (!tree)
		return (1);

	if (index >= size)
		return (0);

	return (helper_2(tree->left, 2 * index + 1, size) &&
		helper_2(tree->right, 2 * index + 2, size));
}

/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: the tree to be measured
 *
 * Return: size of the tree; 0 if tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}

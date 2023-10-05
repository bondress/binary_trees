#include "binary_trees.h"

/**
 * binary_tree_nodes - counts the nodes with at least one child
 * in a binary tree
 * @tree: the tree whose nodes will be counted
 *
 * Return: number of nodes counted, 0 if tree is NULL.
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	if ((!tree->left && !tree->right) || !tree)
		return (0);

	return (binary_tree_size(tree) - binary_tree_leaves(tree));
}

/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: the tree to be measured
 *
 * Return: size of the tree; 0 if tree is NULL.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (binary_tree_size(tree->right) + binary_tree_size(tree->left) + 1);
}

/**
 * binary_tree_leaves - counts the leaves in a binary tree
 * @tree: the tree whose leaves will be counted
 *
 * Return: number of leaves; 0 if tree is NULL.
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	if (!tree->right && !tree->left)
		return (1);

	return (binary_tree_leaves(tree->right) + binary_tree_leaves(tree->left));
}

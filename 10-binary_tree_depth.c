#include "binary_trees.h"

/**
 * binary_tree_depth - measures the depth of a node in a binary tree
 * @tree: the node to calculate the depth of
 *
 * Return: depth of the node; 0 if tree is NULL
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t dpt = 0;

	if (!tree)
		return (0);

	while (tree->parent)
	{
		dpt++;
		tree = tree->parent;
	}

	return (dpt);
}

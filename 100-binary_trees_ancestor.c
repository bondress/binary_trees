#include "binary_trees.h"

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: pointer to the first node
 * @second: pointer to the second node
 *
 * Return: pointer to the ancestor node; NULL if there is no ancestor node
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
const binary_tree_t *second)
{
	size_t f_dpt, s_dpt;

	if (!first || !second)
		return (NULL);

	f_dpt = binary_tree_depth(first);
	s_dpt = binary_tree_depth(second);

	while (f_dpt > s_dpt)
	{
		first = first->parent;
		f_dpt--;
	}
	while (s_dpt > f_dpt)
	{
		second = second->parent;
		s_dpt--;
	}
	while (first && second)
	{
		if (first == second)
			return ((binary_tree_t *)first);
		first = first->parent;
		second = second->parent;
	}
	return ((binary_tree_t *)first);
}

/**
 * binary_tree_depth - measures the depth of a node in a binary tree
 * @tree: the node to measure
 *
 * Return: depth of the node; 0 if tree is NULL.
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

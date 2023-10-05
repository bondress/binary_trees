#include "binary_trees.h"

/**
 * binary_tree_height_b - measures height of a binary tree
 * @tree: tree to go through
 * Return: the height
 */

size_t binary_tree_height_b(const binary_tree_t *tree)
{
	size_t lft = 0;
	size_t rgt = 0;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		if (tree)
		{
			lft = tree->left ? 1 + binary_tree_height_b(tree->left) : 1;
			rgt = tree->right ? 1 + binary_tree_height_b(tree->right) : 1;
		}
		return ((lft > rgt) ? lft : rgt);
	}
}

/**
 * binary_tree_balance - measures balance factor of a binary tree
 * @tree: the tree to go through
 * Return: the balanced factor of the
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	int rgt = 0, lft = 0, res = 0;

	if (tree)
	{
		lft = ((int)binary_tree_height_b(tree->left));
		rgt = ((int)binary_tree_height_b(tree->right));
		res = lft - rgt;
	}
	return (res);
}

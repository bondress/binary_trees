#include "binary_trees.h"

/**
 * binary_tree_levelorder - traverse a binary tree using level-order traverse
 * @tree: the tree to traverse
 * @func: pointer to a function to call for each node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t lvl, mx_lvl;

	if (!tree || !func)
		return;

	mx_lvl = binary_tree_height(tree) + 1;

	for (lvl = 1; lvl <= mx_lvl; lvl++)
		helper_1(tree, func, lvl);
}

/**
 * helper_1 - goes through a binary tree using post-order traverse
 * @tree: tree to traverse
 * @func: pointer to a function to call for each node
 * @level: the level of the tree to call func upon
 */
void helper_1(const binary_tree_t *tree, void (*func)(int), size_t level)
{
	if (level == 1)
		func(tree->n);
	else
	{
		helper_1(tree->left, func, level - 1);
		helper_1(tree->right, func, level - 1);
	}
}

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: the tree to measure
 *
 * Return: height of the tree, 0 if tree is NULL.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t l_h = 0;
	size_t r_h = 0;

	if (!tree)
		return (0);

	l_h = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	r_h = tree->right ? 1 + binary_tree_height(tree->right) : 0;
	return (l_h > r_h ? l_h : r_h);
}

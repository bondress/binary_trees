#include "binary_trees.h"

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to root node of tree to check
 *
 * Return: 1 if the tree is perfect, 0 if the tree is not perfect
 * and 0 if tree is NULL.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t hgt = 0;
	size_t nds = 0;
	size_t pwr = 0;

	if (!tree)
		return (0);

	if (!tree->right && !tree->left)
		return (1);

	hgt = binary_tree_hgt(tree);
	nds = binary_tree_size(tree);

	pwr = (size_t)_exponentiate(2, hgt + 1);
	return (pwr - 1 == nds);
}

/**
 *_exponentiate - returns the value of x raised to the power of y
 *@x: the value to exponentiate
 *@y: the power to raise x to
 *Return: x to the power of y, or -1 if y is negative
 */

int _exponentiate(int x, int y)
{
	if (y < 0)
		return (-1);
	if (y == 0)
		return (1);
	else
		return (x * _exponentiate(x, y - 1));

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
 * binary_tree_height - measures the height of a binary tree
 * @tree: the tree to be measured
 *
 * Return: height of the tree; 0 if tree is NULL.
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

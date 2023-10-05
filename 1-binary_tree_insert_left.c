#include "binary_trees.h"

/**
 * binary_tree_insert_left -  inserts a node as the left-child of another node
 *
 * @parent: pointer to the node to insert the left-child in
 * @value:  value to store in the new node
 *
 * Return: pointer to the created node, or NULL on failure or if
 * parent is NULL
 */

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *n_node;

	if (!parent)
		return (NULL);

	n_node = malloc(sizeof(binary_tree_t));
	if (!n_node)
		return (NULL);

	n_node->n = value;
	n_node->parent = parent;
	n_node->right = NULL;
	n_node->left = parent->left;
	parent->left = n_node;
	if (n_node->left)
		n_node->left->parent = n_node;
	return (n_node);
}

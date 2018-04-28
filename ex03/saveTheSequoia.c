#include "header.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void	swap_nodes_left(struct s_node *node1, struct s_node **node2, int *swap)
{
	struct s_node *tmp;
	struct s_node *tmp1left;
	struct s_node *tmp1right;
	struct s_node *tmp2left;
	struct s_node *tmp2right;

	if (!node1 || !(*node2))
		return ;
	*swap = 1;
	tmp1left = node1->left;
	tmp1right = node1->right;
	tmp2left = (*node2)->left;
	tmp2right = (*node2)->right;

	tmp = node1;
	node1 = *node2;
	*node2 = tmp;
	(*node2)->right = tmp2right;
	node1->right = tmp1right;
	(*node2)->left = node1;
	node1->left = tmp1left;

}

void	swap_nodes_right(struct s_node *node1, struct s_node **node2, int *swap)
{
	struct s_node *tmp;
	struct s_node *tmp1left;
	struct s_node *tmp1right;
	struct s_node *tmp2left;
	struct s_node *tmp2right;

	if (!node1 || !(*node2))
		return ;
	*swap = 1;
	tmp1left = node1->left;
	tmp1right = node1->right;
	tmp2left = (*node2)->left;
	tmp2right = (*node2)->right;

	tmp = node1;
	node1 = *node2;
	*node2 = tmp;
	(*node2)->left = tmp2left;
	node1->left = tmp1left;
	(*node2)->right = node1;
	node1->right = tmp1right;
}

void	maxHeap(struct s_node **root, int *swap)
{
	if (!(*root) || (!(*root)->left && !(*root)->right) || *swap == 1)
		return ;
	if ((*root)->left)
		maxHeap(&(*root)->left, swap);
	if ((*root)->right)
		maxHeap(&(*root)->right, swap);
	if ((*root)->left && (*root)->left->value > (*root)->value)
		swap_nodes_left((*root)->left, root, swap);
	if ((*root)->right && (*root)->right->value > (*root)->value)
		swap_nodes_right((*root)->right, root, swap);
}

void saveTheSequoia(struct s_node **root)
{
	int swap = 1;

	while (swap)
	{
		swap = 0;
		printf("1\n");
		maxHeap(root, &swap);
	}
}

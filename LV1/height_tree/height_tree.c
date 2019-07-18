/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   height_tree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchiang- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 11:12:13 by jchiang-          #+#    #+#             */
/*   Updated: 2019/07/18 11:29:53 by jchiang-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

typedef struct s_node{
	int value;
	struct s_node **nodes;
} t_node;

int height_tree(struct s_node *root){

	if (!root)
		return (-1);
	int max = 0;
	while (*root->nodes){
		int tmp = 1 + height_tree(*root->nodes);
		if (max < tmp)
			max = tmp;
		root->nodes++;
	}
	return (max);
}

t_node		*allocate_node(int n){

	t_node *new = malloc(sizeof(t_node));
	new->value = n;
	new->nodes = malloc(sizeof(t_node) * 1000);
	return (new);
}

int main(void)
{
	t_node *n = allocate_node(94);
	n->nodes[0] = allocate_node(34);
	n->nodes[1] = allocate_node(52);
	n->nodes[0]->nodes[0] = allocate_node(1);
	n->nodes[0]->nodes[1] = allocate_node(99);
	n->nodes[0]->nodes[2] = allocate_node(11);
	n->nodes[0]->nodes[1]->nodes[0] = allocate_node(13);
	printf("height_tree == %d\n", height_tree(n));
	return (0);
}

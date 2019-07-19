/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_looping.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchiang- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 10:00:58 by jchiang-          #+#    #+#             */
/*   Updated: 2019/07/19 10:23:03 by jchiang-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

typedef struct s_node {
	int value;
	struct s_node *next;
}t_node;

int is_looping(struct s_node *node){

	t_node *n1 = node;
	t_node *n2 = node;

	while (n1 && n2){
		n1 = n1->next;
		n2 = n2->next;
		if (n2)
			n2 = n2->next;
		if (n1 && n2 && n1 == n2)
			return (1);
	}
	return (0);
}

t_node *allocate_node(int nb){

	t_node *n = malloc(sizeof(t_node));
	n->value = nb;
	n->next = NULL;
	return (n);
}

int main(void)
{
	t_node *n = allocate_node(1);
	n->next = allocate_node(2);
	n->next->next = allocate_node(3);
	n->next->next->next = allocate_node(4);
	n->next->next->next = n;
	printf("is it looop? %d\n", is_looping(n));
	
	t_node *n1 = allocate_node(1);
	n1->next = allocate_node(2);
	n1->next->next = allocate_node(3);
	n1->next->next->next = allocate_node(4);
	n1->next->next->next = allocate_node(5);
	printf("is it looop? %d\n", is_looping(n1));
	return (0);
}

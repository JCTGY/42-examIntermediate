/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longest_sequence.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchiang- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 10:25:17 by jchiang-          #+#    #+#             */
/*   Updated: 2019/07/19 11:09:06 by jchiang-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

typedef struct s_node{
	int value;
	struct s_node *left;
	struct s_node *right;
}t_node;

int compare(t_node *n, int len){

    int tmp = 0;
    int result = len;

    if (n->right){
        if (n->right->value == n->value + 1)
            tmp = compare(n->right, result + 1);
        else
           tmp =  compare(n->right, 1);
        if (result < tmp)
            result = tmp;
    }
    if (n->left){
        if (n->left->value == n->value + 1)
            tmp = compare(n->left, result + 1);
        else
           tmp =  compare(n->left, 1);
        if (result < tmp)
            result = tmp;
    }
    return (result);
}

int longest_sequence(struct s_node *node){

    if (!node)
        return (0);
    return (compare(node, 1));
}

t_node *allocate(int nb){

    t_node *n = malloc(sizeof(t_node));
    n->value = nb;
    n->left = NULL;
    n->right = NULL;
    return (n);
}

int main(void)
{
    t_node *begin = allocate(1);
    t_node *n = begin;
    n->left = allocate(4);
    for (int i = 2; i < 8; i++){
        n->right = allocate(i);
        n = n->right;
    }
    t_node *lol = NULL;
    printf("longest == %d\n", longest_sequence(begin));
    printf("is it empty = %d\n", longest_sequence(lol));
    return (0);
}

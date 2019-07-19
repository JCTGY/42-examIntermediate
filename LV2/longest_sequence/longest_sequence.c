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

#include <stdilb.h>
#include <stdio.h>

typedef struct s_node{
	int value;
	struct s_node *left;
	struct s_node *right;
}t_node;

# define Max(a, b) ((a > b) ? a : b)

int compare(t_node *n, int len){



int longest_sequence(struct s_node *node){
	



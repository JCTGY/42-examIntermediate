/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_doublo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchiang- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 10:37:12 by jchiang-          #+#    #+#             */
/*   Updated: 2019/07/18 10:50:09 by jchiang-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void print_doublon(int *a, int na, int *b, int nb){

	int ai = 0;
	int bi = 0;
	int f = 1;
	while (ai < na && bi < nb){
		if (a[ai] > b[bi])
			bi++;
		else if (a[ai] < b[bi])
			ai++;
		else if (a[ai] == b[bi]){
			if (f){
				printf("%d", a[ai]);
				f = 0;
			}
			else
				printf(" %d", a[ai]);
			ai++;
			bi++;
		}
	}
	printf("\n");
}

int main(void)
{
	int a1[] = { -5,  2, 10, 15, 50, 70, 100, 200, 300, 1200, 5000 };
	int b1[] = {  2,  4,  5,  6,  7, 10,  40,  70 } ;
	print_doublon(a1, 11, b1, 8);
	int a2[] = { 1,  2, 10, 15 };
	int b2[] = { 2, 20, 40, 70 };
	print_doublon(a2, 4, b2, 4);
	int a3[] = {100,  200, 300};
	int b3[] = {1, 2, 3, 4};
	print_doublon(a3, 3, b3, 4);
	return (0);
}
			

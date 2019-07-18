/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_pivot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchiang- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 10:13:35 by jchiang-          #+#    #+#             */
/*   Updated: 2019/07/18 10:24:15 by jchiang-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int find_pivot(int *arr, int n){

	int sum = 0;
	for (int i = 0; i < n; i++)
		sum += arr[i];
	int tmp = 0;
	for (int i = 0; i < n; i++){
		if (tmp == sum - tmp - arr[i])
			return (i);
		tmp += arr[i];
	}
	return (-1);
}

int main(void)
{
	int	a1[] = {-5, 10, 2, 5};
	int a2[] = {1, 100, 0, 0, 1};
	int a3[] = {7, 9, 8};
	int a4[] = {1, 2};
	int a5[] = {8, 3, 4, 5, 7, 2, 0};
	int a6[] = {1, 2, 3, 4, 0, 6};
	printf("a1 == %d\n", find_pivot(a1, 4));
	printf("a2 == %d\n", find_pivot(a2, 5));
	printf("a3 == %d\n", find_pivot(a3, 3));
	printf("a4 == %d\n", find_pivot(a4, 2));
	printf("a5 == %d\n", find_pivot(a5, 7));
	printf("a6 == %d\n", find_pivot(a6, 6));
	return (0);
}		

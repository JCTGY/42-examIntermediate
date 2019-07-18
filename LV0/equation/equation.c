/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchiang- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 10:05:07 by jchiang-          #+#    #+#             */
/*   Updated: 2019/07/18 10:10:48 by jchiang-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

void equation(int n){

	for (int a = 0; a <= 9; a++){
		for (int b = 0; b <= 9; b++){
			for (int c = 0; c <= 9; c++){
				if (11 * a + 10 * c + b == n)
					printf("A = %d, B = %d, C = %d\n", a, b, c);
			}
		}
	}
}

int main(int argc, char **argv)
{
	if (argc == 2)
		equation(atoi(argv[1]));
	return (0);
}

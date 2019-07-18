/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_alpha.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchiang- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 10:53:25 by jchiang-          #+#    #+#             */
/*   Updated: 2019/07/18 11:04:29 by jchiang-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int is_alpha(char c){

	if (c >= 'a' && c <= 'z')
		return (1);
	return (0);
}

void revers_case(char *a){

	for (int i = 0; a[i]; i++){
		if (a[i] >= 'A' && a[i] <= 'Z')
			a[i] = a[i] + 32;
	}
}

void count_alpha(char *a){

	int tab[127] = {0};
	int f = 1;
	revers_case(a);
	for (int i = 0; a[i]; i++){
		if (is_alpha(a[i]))
			tab[(int)a[i]]++;
	}
	for (int i = 0; a[i]; i++){
		if (tab[(int)a[i]]){
			if (f){
				printf("%d%c", tab[(int)a[i]], a[i]);
				f = 0;
				tab[(int)a[i]] = 0;
			}
			else {
				printf(", %d%c", tab[(int)a[i]], a[i]);
				tab[(int)a[i]] = 0;
			}
		}
	}
}

int main(int argc, char **argv)
{
	if (argc == 2)
		count_alpha(argv[1]);
	printf("\n");
	return (0);
}

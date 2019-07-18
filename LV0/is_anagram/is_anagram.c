/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_anagram.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchiang- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 10:25:39 by jchiang-          #+#    #+#             */
/*   Updated: 2019/07/18 10:33:20 by jchiang-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int is_anagram(char *a, char *b){

	int tab[126] = {0};
	for (int i = 0; a[i]; i++)
		tab[(int)a[i]]++;
	for (int i = 0; b[i]; i++)
		tab[(int)b[i]]--;
	for (int i = 0; i < 126; i++){
		if (tab[i] != 0)
			return (0);
	}
	return (1);
}


int main(int argc, char **argv)
{
	if (argc == 3){
		if (is_anagram(argv[1], argv[2]))
			printf("Is an anagram");
		else
			printf("Not an anagram");
	}
	printf("\n");
	return (0);
}		

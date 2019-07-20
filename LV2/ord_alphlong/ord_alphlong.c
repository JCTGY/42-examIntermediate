/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ord_alphlong.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchiang- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 10:38:19 by jchiang-          #+#    #+#             */
/*   Updated: 2019/07/20 11:28:35 by jchiang-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

# define MAX(a, b) ((a > b) ? a : b);

void ft_putchar(char c){
    write(1, &c, 1);
}

void ft_putstr(char *str){
    for (int i = 0; str[i]; i++)
        ft_putchar(str[i]);
}

int ft_strlen(char *str){
    int i = 0;
    while (str[i])
        i++;
    return (i);
}

int is_space(char c){
	return (c == ' ' || c == '\t');
}

int word_maxlen(char *s){

	int max_len = 0;
	int tmp = 0;
	for (int i = 0; s[i]; i++){
		if (!is_space(s[i]))
			tmp++;
		else if (s[i + 1] == '\0') {
			if (tmp > max_len)
				max_len = tmp;
		}
		else {
			if (tmp > max_len)
				max_len = tmp;
			tmp = 0;
		}
	}
	return (max_len);
}

int word_count(char *s){

	int count = 0;
	for (int i = 0; s[i]; i++){
		if (!is_space(s[i]) && (is_space(s[i + 1]) || s[i + 1] == '\0'))
			count++;
	}
	return (count);
}

char *word_sep(char *s, int *i, int max_len){

	char *tmp;
	int p = 0;
	int x = *i;

	tmp = malloc(sizeof(*tmp) * max_len);
	while (is_space(s[x]))
		x++;
	while (!is_space(s[x]) && s[x])
		tmp[p++] = s[x++];
	tmp[p] = '\0';
	*i = x;
	printf("waht is tmp = %s\n", tmp);
	return (tmp);
}

void ft_strcpy(char *s1, char *s2){

	int p = 0;
	for (int i = 0; s2[i]; i++)
		s1[p++] = s2[i];
	s1[p] = '\0';
}

void ord_alph(char *s){

	int word = word_count(s);
	int max_len = word_maxlen(s) + 1;
	printf("word_count = %d\n", word);
	printf("max_len = %d\n", max_len);
	char **arr = malloc(sizeof(*arr) * word + 1);
	arr[word] = NULL;
	for (int w = 0; w < word; w++){
		for (int i = 0; s[i]; i++){
			arr[w] = malloc(sizeof(**arr) * max_len);
			char *tmp = word_sep(s, &i, max_len);
			ft_strcpy(arr[w], tmp);
			if (s[i] == '\0')
				break ;
		}
	}
	for (int i = 0; arr[i]; i++){
		ft_putstr(arr[i]);
		ft_putchar('\n');
	}
}	

int main(int argc, char **argv)
{
	if (argc == 2)
		ord_alph(argv[1]);
	ft_putchar('\n');
	return (0);
}

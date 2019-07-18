/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_of_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchiang- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 10:03:41 by jchiang-          #+#    #+#             */
/*   Updated: 2019/07/18 11:07:12 by jchiang-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<stdlib.h>

int count_of_2(int n){

    int count = 0;
    for (int i = 0; i <= n; i++){
        for (int x = i; x > 0; x /= 10){
            if (x % 10 == 2)
                count++;
        }
    }
    return (count);
}

int main(int argc, char **argv){

    if (argc == 2)
        printf("number of 2 == %d", count_of_2(atoi(argv[1])));
    printf("\n");
    return (0);
}

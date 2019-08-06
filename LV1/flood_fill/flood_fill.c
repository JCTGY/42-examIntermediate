#include "flood_fill.h"

void flood_fill(char **tab, t_point size, t_point begin){

    t_point n;
    char c = tab[begin.x][begin.y];
    tab[begin.x][begin.y] = 'F';
    if (begin.y > 0 && tab[begin.x][begin.y - 1] == c){
        n.x = begin.x;
        n.y = begin.y - 1;
        flood_fill(tab, size, n);
    }
    if (begin.y < (size.y - 1) && tab[begin.x][begin.y + 1] == c){
        n.x = begin.x;
        n.y = begin.y + 1;
        flood_fill(tab, size, n);
    }
    if (begin.x > 0 && tab[begin.x - 1][begin.y] == c){
        n.x = begin.x - 1;
        n.y = begin.y;
        flood_fill(tab, size, n);
    }
    if (begin.x < size.x -1 && tab[begin.x + 1][begin.y] == c){
        n.x = begin.x + 1;
        n.y = begin.y;
        flood_fill(tab, size, n);
    }
}

#include <stdio.h>
#include <stdlib.h>
#include "flood_fill.h"

void print_tab(char **area, t_point size){

    for (int i = 0; i < size.y; i++){
        for (int j = 0; j < size.x; j++){
            printf(" %c", area[i][j]);
        }
        printf("\n");
    }
}

char **make_area(char **zone, t_point size){

    char **r;
    r = malloc(sizeof(char *) * size.y + 1);
    for (int i = 0; i < size.y; i++){
        r[i] = malloc(sizeof(char) * size.x + 1);
    }
    for (int y = 0; y < size.y; y++){
        for (int x = 0; x < size.x; x++){
            r[y][x] = zone[y][x * 2];
        }
    }
    return r;
}
int main(void)
{
	t_point size = {8, 5};
	t_point begin = {2, 2};
    char **area;
	char *zone[] = {
		"1 1 1 1 1 1 1 1",
		"1 0 0 0 1 0 0 1",
		"1 0 0 1 0 0 0 1",
		"1 0 1 1 0 0 0 1",
		"1 1 1 0 0 0 0 1",
	};
    area = make_area((char **)zone, size);
	print_tab(area, size);
	flood_fill(area, size, begin);
	printf("\n");
	print_tab(area, size);
	return (0);
}


#include <unistd.h>
#include <stdlib.h>

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

# define MAX(a, b) ((a > b) ? a : b);

//typedef struct s_word{
//    int len;
//    char *str;
//    struct s_word *next;
//}t_word;;



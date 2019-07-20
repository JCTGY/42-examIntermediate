#include <stdio.h>
#include <stdlib.h>

typedef struct s_node{
    int value;
    struct s_node *right;
    struct s_node *left;
}t_node;

void reverse_tree(struct s_node *root){

    t_node *tmp = root->left;
    root->left = root->right;
    root->right = tmp;

    if (root->right)
        reverse_tree(root->right);
    if (root->left)
        reverse_tree(root->left);
}

t_node *allocate(int nb){

    t_node *n = malloc(sizeof(t_node));
    n->value = nb;
    n->right = NULL;
    n->left = NULL;
    return (n);
}

int main(void)
{
    t_node *begin = allocate(1);
    t_node *n = begin;
    for (int i = 2; i < 8; i++){
        n->right = allocate(i);
        n = n->right;
    }
    t_node *r = begin;
    reverse_tree(begin);
    while (r){
        printf("left re == %d\n", r->value);
        r = r->left;
    }
}

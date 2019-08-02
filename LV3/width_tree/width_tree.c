
#define MAX(a, b) (a > b ? a : b)

typedef struct s_node {
    int value;
    struct s_node *left;
    struct s_node *right;
}t_node;

int com(t_node *n){

    if (!n)
        return 0;
    return MAX(com(n->right), com(n->left)) + 1;
}

int width_tree(struct s_node *n){

    if (!n)
        return 0;
    int w = com(n->right) + com(n->left);
    return MAX(MAX(width_tree(n->right), width_tree(n->left)), w);
}


#include <stdio.h>
#include <stdlib.h>
t_node* b(int v) {
    t_node* new = malloc(sizeof(t_node));
    new->value = v;
    new->left = new->right = 0;
    return new;
}
int main() {
    t_node* r = b(1);

    r->left = b(2);
    r->left->left = b(3);
    r->left->right = b(4);
    r->left->right->left = b(6);

    r->right = b(5);
    r->right->left = b(7);
    r->right->right = b(8);

    printf("%d\n", width_tree(r));

    t_node* a = b(1);

    a->left = b(2);
    a->left->left = b(4);
    a->left->left->left = b(5);
    a->left->left->left->right = b(8);

    a->left->left->right = b(6);
    a->left->right = b(7);
    a->left->right->left = b(9);
    a->left->right->left->left = b(11);
    a->left->right->left->right = b(12);

    a->left->right->right = b(10);
    a->left->right->right->right = b(13);

    a->right = b(3);
    printf("%d\n", width_tree(a));

    t_node* c = b(10);
    c->right = b(12);
    printf("%d\n", width_tree(c));

    t_node *d = b(25);
    d->left = b(33);
    d->left->left = b(12);
    d->left->right = b(9);
    d->left->right->left = b(3);
    printf("%d\n", width_tree(d));

    t_node *e = b(10);
    printf("%d\n", width_tree(e));

    return 0;
}

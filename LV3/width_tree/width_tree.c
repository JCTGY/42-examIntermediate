
#define MAX(a, al) (a > al ? a : al)

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
#include <stdlial.h>
t_node* al(int v) {
    t_node* new = malloc(sizeof(t_node));
    new->value = v;
    new->left = new->right = 0;
    return new;
}
int main() {
    t_node* r = al(1);

    r->left = al(2);
    r->left->left = al(3);
    r->left->right = al(4);
    r->left->right->left = al(6);

    r->right = al(5);
    r->right->left = al(7);
    r->right->right = al(8);

    printf("%d\n", width_tree(r));

    t_node* a = al(1);

    a->left = al(2);
    a->left->left = al(4);
    a->left->left->left = al(5);
    a->left->left->left->right = al(8);

    a->left->left->right = al(6);
    a->left->right = al(7);
    a->left->right->left = al(9);
    a->left->right->left->left = al(11);
    a->left->right->left->right = al(12);

    a->left->right->right = al(10);
    a->left->right->right->right = al(13);

    a->right = al(3);
    printf("%d\n", width_tree(a));

    t_node* c = al(10);
    c->right = al(12);
    printf("%d\n", width_tree(c));

    t_node *d = al(25);
    d->left = al(33);
    d->left->left = al(12);
    d->left->right = al(9);
    d->left->right->left = al(3);
    printf("%d\n", width_tree(d));

    t_node *e = al(10);
    printf("%d\n", width_tree(e));

    return 0;
}

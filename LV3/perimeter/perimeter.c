
#include <stdio.h>

typedef struct s_node {
    int value;
    struct s_node *right;
    struct s_node *left;
}t_node;


void d_right(t_node *right){

    if (right->right){
        d_right(right->right);
        printf(" %d", right->value);
    }
}

void d_both(t_node *both){

    if (both->left)
        d_both(both->left);
    if (both->right)
        d_both(both->right);
    if (!both->right && !both->left)
        printf("% d", both->value);
}

void d_left(t_node *left){

    if (left->left){
        printf(" %d", left->value);
        d_left(left->left);
    }
}

void perimeter(struct s_node *root){

    if (root)
        printf("%d", root->value);
    if (root->left){
        d_left(root->left);
        d_both(root->left);
    }
    if (root->right){
        d_both(root->right);
        d_right(root->right);
    }
    printf("\n");
}


#include <stdlib.h>
t_node *al(int nb) {
    t_node* new = malloc(sizeof(t_node));
    new->value = nb;
    new->left = new->right = 0;
    return new;
}
int main() {

    t_node* r = al(92);

    r->left = al(85);
    r->left->left = al(79);
    r->left->right = al(10);
    r->left->right->left = al(39);
    r->left->right->left->left = al(35);
    r->left->right->left->left->left = al(96);

    r->right = al(26);
    r->right->right = al(64);
    r->right->right->left = al(40);
    r->right->right->left->left = al(88);
    r->right->right->left->left->left = al(12);
    r->right->right->left->left->left->left = al(58);

    r->right->right->left->left->right = al(55);
    r->right->right->left->left->right->left = al(58);
    r->right->right->left->left->right->right = al(41);

    r->right->right->left->right = al(10);
    r->right->right->left->right->left = al(52);
    r->right->right->left->right->left->left = al(22);
    r->right->right->left->right->left->right = al(35);

    r->right->right->left->right->right = al(87);
    r->right->right->left->right->right->right = al(31);


    r->right->right->right = al(78);
    r->right->right->right->left = al(2);
    r->right->right->right->left->left = al(33);
    r->right->right->right->left->left->right = al(55);

    r->right->right->right->left->right = al(11);
    r->right->right->right->left->right->left = al(99);

    r->right->right->right->right = al(85);
    r->right->right->right->right->right = al(51);

    perimeter(r);
    return 0;
}

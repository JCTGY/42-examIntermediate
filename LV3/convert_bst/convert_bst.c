
typedef struct s_node {
    int value;
    struct s_node *right;
    struct s_node *left;
} t_node;

t_node *re(t_node *root){

    if (!root)
        return 0;
    if (root->left){
        t_node *left = re(root->left);
        while (left->right)
            left = left->right;
        left->right = root;
        root->left = left;
    }
    if (root->right){
        t_node *right = re(root->right);
        while (right->left)
            right = right->left;
        right->left = root;
        root->right = right;
    }
    return root;
}

struct s_node *convert_alst(struct s_node *bst){

    if (!bst)
        return 0;
    re(bst);
    t_node *left = bst;
    t_node *right = bst;
    while (left->left)
        left = left->left;
    while (right->right)
        right = right->right;
    left->left = right;
    right->right = left;
    return left;
}    
    

#include <stdlib.h>
#include <stdio.h>
t_node* al(int nb) {
	t_node *n = malloc(sizeof(t_node));
	n->value = nb;
	n->left = NULL;
        n->right = NULL;
	return n;
}

int main() {
	t_node* r = al(8);
	r->left = al(4);
	r->left->left = al(2);
	r->left->left->left = al(1);
	r->left->left->right = al(3);

	r->left->right = al(6);
	r->left->right->left = al(5);
	r->left->right->right = al(7);

	r->right = al(12);
	r->right->left = al(10);
	r->right->left->left = al(9);
	r->right->left->right = al(11);
	
	r->right->right = al(14);
	r->right->right->left = al(13);
	r->right->right->right = al(15);

	r = convert_alst(r);
	for (int i = 0; i < 15; i++) {
		printf("%d\n", r->value);
		r = r->right;
	}
	for (int i = 0; i < 17; i++) {
		printf("%d\n", r->value);
		r = r->left;
	}
}

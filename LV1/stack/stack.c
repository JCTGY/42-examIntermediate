#include <stdio.h>
#include <stdlib.h>

typedef struct s_node{
    void *content;
    struct s_node *next;
}t_node;

typedef struct s_stack{
    struct s_node *top;
}t_stack;

struct s_stack *init(void){

    t_stack *s = malloc(sizeof(t_stack));
    s->top = 0;
    return (s);
};

void *pop(struct s_stack *stack){

    if (!stack)
        return NULL;
    if (!stack->top)
        return NULL;
    t_node *tmp = stack->top;
    void *content = tmp->content;
    stack->top = stack->top->next;
    free(tmp);
    return (content);
};

void push(struct s_stack *stack, void *content){

    t_node *n = malloc(sizeof(t_node));
    n->content = content;
    n->next = NULL;
    if (!stack->top)
        stack->top = n;
    else{
        n->next = stack->top;
        stack->top = n;
    }
};

void *peek(struct s_stack *stack){

    if (!stack->top)
        return NULL;
    return (stack->top->content);
};

int isEmpty(struct s_stack *stack){

    if (!stack->top)
        return (1);
    return (0);
}


int main(void)
{
    t_stack *s = init();
    printf("is it empty == %d\n", isEmpty(s));
    push(s, "waklwfgj");
    printf("content == %s\n", peek(s));
    push(s, "gakki");
    printf("content == %s\n", peek(s));
    push(s, "toda");
    printf("is it empty == %d\n", isEmpty(s));
    printf("content == %s\n", peek(s));
    printf("remove == %s\n", pop(s));
    printf("remove == %s\n", pop(s));
    printf("remove == %s\n", pop(s));
    printf("remove == %s\n", pop(s));
    printf("is it empty == %d\n", isEmpty(s));
    return (0);
}

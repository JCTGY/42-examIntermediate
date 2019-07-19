#include <stdlib.h>
#include <stdio.h>

typedef struct s_node{
    void *content;
    struct s_node *next;
}t_node;

typedef struct s_queue{
    struct s_node *first;
    struct s_node *last;
}t_queue;

struct s_queue *init(void){
    t_queue *q = malloc(sizeof(t_queue));
    q->first = 0;
    q->last = 0;
    return (q);
};

void enqueue(struct s_queue *queue, void *content){
    if (!queue)
        return ;
    t_node *n = malloc(sizeof(t_node));
    n->content = content;
    n->next = NULL;
    if (!queue->first)
        queue->first = n;
    if (queue->last)
        queue->last->next = n;
    queue->last = n;
};

void *dequeue(struct s_queue *queue){
    if (!queue->first)
        return NULL;
    t_node *tmp = queue->first;
    void *content = queue->first->content;
    queue->first = queue->first->next;
    free(tmp);
    return (content);
}

void *peek(struct s_queue *queue){
    if (!queue->first)
        return NULL;
    return (queue->first->content);
}

int isEmpty(struct s_queue *queue){
    if (!queue->first)
        return (1);
    return (0);
}

int main(void)
{
    t_queue *q = init();
    printf("is it empty? == %d\n", isEmpty(q));
    enqueue(q, "lol");
    printf("is it empty? == %d\n", isEmpty(q));
    printf("content == %s\n", peek(q));
    enqueue(q, "wahahah");
    printf("content == %s\n", peek(q));
    enqueue(q, "gakkiergea");
    printf("content == %s\n", peek(q));
    printf("what is in == %s\n", dequeue(q));
    printf("what is in == %s\n", dequeue(q));
    printf("content == %s\n", peek(q));
    printf("what is in == %s\n", dequeue(q));
    printf("content == %s\n", peek(q));
    printf("what is in == %s\n", dequeue(q));

    return (0);
}

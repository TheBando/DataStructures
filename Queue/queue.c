#include "queue.h"


struct Queue * create_queue(){
    struct Queue * ret = (struct Queue *) malloc (sizeof(ret));
    ret->front = NULL;
    ret->rear = NULL;
}


struct Node * create_node(int i){
    struct Node * ret = (struct Node *) malloc (sizeof(ret));
    ret->data = i;
    ret->next = NULL;
    return ret;
}

int is_empty(struct Queue * q){
    return (q->front == NULL);
}

void enqueue(struct Queue * q, int i){
    struct Node * new = create_node(i);

    if (is_empty(q)){
        q->front = new;
        q->rear = new;
    } else {
        q->rear->next = new;
        q->rear = new;
    }
}

int dequeue(struct Queue ** q){
    if (is_empty((*q))){
        fprintf(stderr, "Warning: %s\n", "\x1b[33m""Queue is empty, dequeue failed""\x1b[0m");
        return -1;
    }
    int ret = (*q)->front->data;
    struct Node * old = (*q)->front;
    (*q)->front = (*q)->front->next;

    if ((*q)->front == NULL){
        (*q)->rear = NULL;
    }

    free(old);
    return ret;
}

int delete_queue(struct Queue ** q){
    while( is_empty((*q)) == 0){
        struct Node * old = (*q)->front;
        (*q)->front = (*q)->front->next;
        free(old);
    }
    free(*q);
}

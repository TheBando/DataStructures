#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

struct Node {
    int data;
    struct Node* next;
};

struct Queue{
        struct Node * front;
        struct Node * rear;
};

struct Queue * create_queue();

struct Node * create_node(int);

int is_empty(struct Queue *);

void enqueue(struct Queue *, int);

int dequeue(struct Queue **);

int delete_queue(struct Queue **);

#endif

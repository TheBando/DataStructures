#ifndef STACK_H
#define STACK_H
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node * next;
};

struct Stack {
    struct Node * top;
    int size;
};

struct Stack * create_stack();

struct Node * create_node(int i);

int is_empty(struct Stack *);

void push(struct Stack *, int);

int pop(struct Stack *);

int peek(struct Stack *);

void delete_node(struct Node *);

void delete_stack(struct Stack *);


#endif

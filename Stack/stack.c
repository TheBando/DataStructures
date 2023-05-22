#include "stack.h"

struct Stack * create_stack(){
    struct Stack * ret = (struct Stack *) malloc (sizeof(ret));
    ret->top = NULL;
    ret->size = 0;
    return ret;
}

struct Node * create_node(int i){
    struct Node * ret = (struct Node *) malloc (sizeof(ret));
    ret->data = i;
    ret->next = NULL;
    return ret;
}

int is_empty(struct Stack * s){
    if (s->size > 0){return 0;}
    else {return 1;}
}

void push(struct Stack * s, int i){
    struct Node * new = create_node(i);
    new->next = s->top;
    s->top = new;
    s->size = s->size + 1;
}

int pop(struct Stack * s){
    if (is_empty(s)){
        fprintf(stderr, "Warning: %s\n", "\x1b[33m""Stack is empty, pop failed""\x1b[0m");
        return -1;
    }
    int ret = s->top->data;
    struct Node * old = s->top;
    s->top = s->top->next;
    delete_node(old);
    s->size = s->size - 1;
    return ret;
}

int peek(struct Stack * s){
    if (is_empty(s)){
        fprintf(stderr, "Warning: %s\n", "\x1b[33m""Stack is empty, peek failed""\x1b[0m");
        return -1;
    }
    return s->top->data;
}

void delete_node(struct Node * n){
    free(n);
}

void delete_stack(struct Stack * s){

    while(!is_empty(s)){
        pop(s);
    }
    free(s);
}

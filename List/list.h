#include <stdio.h>
#include <errno.h>
#include <stdlib.h>


struct Node {
    int val;
    struct Node * next;
};

struct Node * create_node(int);

struct Node * append(struct Node *, int);

int delete_index(struct Node **, int);

int delete_val(struct Node *, int);

int size(struct Node *);

void print_list(struct Node *);

void delete_list(struct Node *);

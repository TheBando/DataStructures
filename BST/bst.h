#include <stdio.h>
#include <errno.h>
#include <stdlib.h>






struct Node {
    int val;
    struct Node * left;
    struct Node * right;
};

/* Creates and returns root Node */
struct Node * create_node(int);

/* inserts Node of value int */
struct Node * insert(struct Node *, int);

/* returns Node matching value int */
struct Node * search(struct Node *, int);

/* returns Node with smallest value */
struct Node * find_min(struct Node *);

/* returns Node with highest value */
struct Node * find_max(struct Node *);


/* delete node of value int */
struct Node * delete(struct Node *, int);



void in_order_print(struct Node *);



/* Frees up any memory allocated for the tree */
void delete_tree(struct Node *);

void deallocate_node(struct Node *);

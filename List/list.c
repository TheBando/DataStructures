#include "list.h"

struct Node * create_node(int i){
    struct Node * ret = (struct Node *) malloc (sizeof(ret));
    ret->val = i;
    return ret;
}

struct Node * append(struct Node * n, int i){
    while(n->next != NULL){
        n = n->next;
    }
    n->next = create_node(i);
}

int delete_index(struct Node ** n, int i){
    int s = size(*n);
    if (i >= s || i < 0){
        fprintf(stderr, "Error: %s\n", "\x1b[31m""Index out of bounds""\x1b[0m");
        return 1;
    } else {
        struct Node * temp = *n;
        if ( i == 0 ) {
            *n = (*n)->next;
            free(temp);
            return 0;
        }
        else {
            int index = 0;
            temp = *n;
            struct Node * temp2 = *n;
            while (index < i){
                index ++;
                temp2 = temp;
                temp = temp->next;
            }
            temp2->next = temp->next;
            free(temp);
            return 0;
        }
        return 0;

    }
}

int delete_val(struct Node * n, int i){
    struct Node * temp = n;
    if (n->val == i){
        n = n->next;
        free(temp);
        return 0;
    }
    else {
        while(temp->next != NULL){
            temp = temp->next;
            if (temp->next->val == i){
                struct Node * temp2 = temp->next;
                temp->next = temp->next->next;
                free(temp2);
                return 0;
            }
        }
        return 1;

    }
}


/*int delete_val(struct Node * n, int i){

    if (n->val == i){
        struct Node * temp = n;
        n = n->next;
        free(temp);
        return 0;
    }
    else{
        delete_val(n->next, i);
        return 0;
    }
    return 1;
}*/


int size(struct Node * n){
    int ret = 0;
    while (n != NULL){
        ret ++;
        n = n->next;
    }
    return ret;
}

void print_list(struct Node * n){
    while (n != NULL){
        printf("%d\n",n->val);
        n = n->next;
    }
}

void delete_list(struct Node * n){
    struct Node * temp;
    while (n != NULL){
        temp = n->next;
        free(n);
        n = temp;
    }
}

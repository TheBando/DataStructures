#include "bst.h"

int main(){


    struct Node * ptr;
    struct Node * cur;
    ptr = create_node(12);
    insert(ptr, 7);
    insert(ptr, 3);
    insert(ptr, 9);
    in_order_print(ptr);
    cur = find_min(ptr);
    printf("Min element = %d\n", cur->val);
    cur = find_max(ptr);
    printf("Max element = %d\n", cur->val);
    delete(ptr, 7);
    in_order_print(ptr);


    delete_tree(ptr);
    return 0;
}

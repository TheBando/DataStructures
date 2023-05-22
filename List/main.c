#include "list.h"

int main(){
    struct Node * ptr;
    ptr = create_node(12);
    append(ptr, 13);
    append(ptr, 99);
    append(ptr, 6);
    append(ptr, 7);
    append(ptr, 13);

    print_list(ptr);
    int s = size(ptr);
    printf("size: %d\n", s);      /* expected outcome:
                                    12
                                    13
                                    99
                                    6
                                    7
                                    13
                                    size: 6
                                    */


    delete_index(&ptr, 2);
    delete_val(ptr, 7);
    printf("\n");



    print_list(ptr);
    s = size(ptr);
    printf("size: %d\n", s);    /* expected outcome:
                                    12
                                    13
                                    6
                                    13
                                    size: 4
                                    */

    delete_index(&ptr, 0);


    print_list(ptr);
    s = size(ptr);
    printf("size: %d\n", s);    /* expected outcome:
                                    13
                                    6
                                    13
                                    size: 3
                                    */


    /* these should fail */
    delete_index(&ptr, -2);
    delete_index(&ptr, 10);


    delete_list(ptr);

    return 0;
}

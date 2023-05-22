#include "stack.h"

int main(){

    struct Stack * ptr = create_stack();

    for (int i = 0; i < 10; i++){
        push(ptr, i * 10);
    }

    while (!is_empty(ptr)){
        printf("popped: %d\n", pop(ptr) );
    }

    push(ptr, 2);
    push(ptr, 5);
    push(ptr, 7);

    printf("peeked: %d\n", peek(ptr));

    delete_stack(ptr);
    return 0;

}

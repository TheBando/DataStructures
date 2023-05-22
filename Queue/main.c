#include "queue.h"

int main(){
    struct Queue * ptr = create_queue();

    enqueue(ptr, 3);
    enqueue(ptr, 8);
    enqueue(ptr, 4);

    while ( is_empty(ptr) == 0){
        printf("dequeue: %d\n", dequeue(&ptr));
    }
    printf("Finished dequeue\n");

    delete_queue(&ptr);


    return 0;
}

#include "queue.h"

#include <stdio.h>

int main() {
    Queue *queue = queue_create();

    queue_enqueue(queue, 1);
    queue_enqueue(queue, 2);
    queue_enqueue(queue, 3);
    queue_enqueue(queue, 4);
    queue_enqueue(queue, 5);

    queue_print(queue);

    element_print(queue_dequeue(queue));
    printf("\n");
    element_print(queue_dequeue(queue));
    printf("\n");

    queue_print(queue);

    queue_destroy(queue);

    return 0;
}
#include "queue.h"
#include "/Users/renansan/Desktop/Codes/UFABC/Algoritmos e Estrutura de Dados/p1/stack/stack.h"

#include <stdio.h>

int main() {
    Queue *queue1 = queue_create();
    Queue *queue2 = queue_create();

    queue_enqueue(queue1, 1);
    queue_enqueue(queue1, 2);
    queue_enqueue(queue1, 3);
    queue_enqueue(queue1, 4);
    queue_enqueue(queue1, 5);

    queue_print(queue1);

    queue_enqueue(queue2, 1);
    queue_enqueue(queue2, 2);
    queue_enqueue(queue2, 3);
    queue_enqueue(queue2, 4);
    queue_enqueue(queue2, 3);
    queue_print(queue2);

    printf("%d\n", queue_equals(queue1, queue2));

    queue_destroy(queue1);
    queue_destroy(queue2);


    return 0;
}
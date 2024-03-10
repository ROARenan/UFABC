#include "queue.h"
#include "/Users/renansan/Desktop/Codes/UFABC/Algoritmos e Estrutura de Dados/p1/stack/stack.h"

#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
    Element element;
    struct Node* next;
} Node;

struct Queue {
    Node* front;
    Node* back;
    int size;
};

Queue* queue_create() {
    Queue* queue = malloc(sizeof(Queue));

    queue->front = NULL;
    queue->back = NULL;
    queue->size = 0;

    return queue;
}

void queue_destroy(Queue* queue) {
    while (!queue_isEmpty(queue)) {
        queue_dequeue(queue);
    }
    free(queue);
}

void queue_enqueue(Queue* queue, Element element) {
    Node* newNode = malloc(sizeof(Node));

    newNode->element = element;
    newNode->next = NULL;
    if (queue->front == NULL) { // empty queue
        queue->front = newNode;
        queue->back = newNode;
    } else { // non-empty queue
        queue->back->next = newNode;
        queue->back = newNode;
    }
    queue->size++;
}

Element queue_dequeue(Queue* queue) {
    if (queue_isEmpty(queue)) {
        return ELEMENT_NULL;
    }

    Element res = queue->front->element;
    Node* trash = queue->front;

    queue->front = queue->front->next;
    free(trash);
    queue->size--;

    return res;
}

Element queue_front(Queue* queue) {
    if (queue_isEmpty(queue)) {
        return ELEMENT_NULL;
    }

    return queue->front->element;
}

Element queue_back(Queue* queue) {
    if (queue_isEmpty(queue)) {
        return ELEMENT_NULL;
    }

    return queue->back->element;
}

int queue_size(Queue* queue) {
    return queue->size;
}

bool queue_isEmpty(Queue* queue) {
    return queue->front == NULL;
}

void queue_print(Queue* queue) {
    Node* cur = queue->front;

    while (cur != NULL) {
        element_print(cur->element);
        printf(" ");
        cur = cur->next;
    }
    printf("\n");
}

Queue* reverse(Stack* s){
    
}
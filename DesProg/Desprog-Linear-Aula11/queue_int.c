#include <stdlib.h>

#include "queue_int.h"

typedef struct _queue_int {
    int capacity;
    int *data;
    int begin;
    int end;
    int size;
} queue_int;

queue_int *queue_int_new(int capacity) {
    queue_int *q = malloc(sizeof(queue_int));
    q->capacity = capacity;
    q->data = malloc(capacity * sizeof(int));
    q->begin = capacity - 1;
    q->end = 0;
    q->size = 0;
    return q;
}

void queue_int_delete(queue_int **_q) {
    queue_int *q = *_q;
    free(q->data);
    free(q);
    *_q = NULL;
}

int queue_int_empty(queue_int *q) {
    return (q->size == 0);
}

int queue_int_full(queue_int *q) {
    return (q->size == q->capacity);
}

void queue_int_put(queue_int *q, int value) {
    q->data[q->end] = value; // escreve o novo valor no novo final
    if (q->end == q->capacity - 1){
        q->end = 0;
    } else{
        q->end++;                // move o topo para a direita

    }
    q->size++;               // aumenta o tamanho
}

int queue_int_get(queue_int *q) {
    q->size--;                // diminui o tamanho

    if (q->begin == q->capacity - 1){
        q->begin = 0;
    } else {
        q->begin++;               // move o início para a direita
    }
    
    return q->data[q->begin]; // devolve o valor do início atual
}

// a ? b : c se condição a, vai pra b. Se não, vai pra c
#include <stdlib.h>

#include "queue_int.h"

struct _node {
    int value;
    struct _node *next;
};

typedef struct _node node;

struct _queue_int {
    node *first;
    node *last;
};

queue_int *queue_int_new() {
    queue_int *q = malloc(sizeof(queue_int));
    q->first = NULL;
    q->last = NULL;
    return q;
}

void queue_int_delete(queue_int **_q) {
    queue_int *q = *_q;
    node *n = q->first;
    while (n != NULL) {
        node *next = n->next;
        free(n);
        n = next;
    }
    free(q);
    *_q = NULL;
}

int queue_int_empty(queue_int *q) {
    return q->last == NULL;
}

void queue_int_put(queue_int *q, int value) {
    node *n = malloc(sizeof(node));
    n->value = value;
    n->next = NULL;
    if (q->last != NULL){
        q->last->next = n;
    } else {
        q->first = n;
    }

    q->last = n;
}

int queue_int_get(queue_int *q) {
    node *n = q->first;
    q->first = n->next;
    if (q->first == NULL){
        q->last = NULL;
    }

    int value = n->value;
    free(n);

    return value;
}



// PILHA

// depois de new(3):   ? ? ?
// depois de push(1):  1 ? ?
// depois de push(2):  1 2 ?
// depois de pop():    1 ? ?
// depois de push(3):  1 3 ?
// depois de pop():    1 ? ?
// depois de push(4):  1 4 ?
// depois de push(5):  1 4 5
// depois de pop():    1 4 ?


// ----------------------------------

// FILA

// depois de new(3):   ? ? ?
// depois de put(1):   1 ? ?
// depois de put(2):   1 2 ?
// depois de get():    ? 2 ?
// depois de put(3):   ? 2 3
// depois de get():    ? ? 3
// depois de put(4):   4 ? 3
// depois de put(5):   4 5 3
// depois de get():    4 5 ?

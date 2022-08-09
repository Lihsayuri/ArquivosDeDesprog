#include <stdlib.h>
#include <stdlib.h>

#include <stdlib.h>


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

void queue_int_genput(queue_int *q, int value, int index){
    int prev;
    int i;
    for (i = q->end; i != ((q->end - index) % q->capacity);){
        prev = (i-1)%q->capacity;
        q->data[i] = q->data[prev];
        i = prev;
    }

    q->data[i] = value;
    q->size++;
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


// ----------------------------------------------------------------------------------------------





struct _node {
    int value;
    struct _node *next;
};

typedef struct _node node;

typedef struct _queue_int {
    node *first;
    node *last;
} queue_int2;

queue_int2 *queue_int2_new() {
    queue_int2 *q = malloc(sizeof(queue_int2));
    q->first = NULL;
    q->last = NULL;
    return q;
}

void queue_int2_delete(queue_int2 **_q) {
    queue_int2 *q = *_q;
    node *n = q->first;
    while (n != NULL) {
        node *next = n->next;
        free(n);
        n = next;
    }
    free(q);
    *_q = NULL;
}

int queue_int2_empty(queue_int2 *q) {
    return q->last == NULL;
}

void queue_int2_put(queue_int2 *q, int value) {
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

void queue_int_genput(queue_int2 *q, int value, int index){
    int size = 0;
    node *n;

    for (n = q->first; n != NULL; n = n->next){
        size++;
    }

    n = q->first;
    node *p = NULL; 

    for (int i = 0; i < size - index; i++){
        p = n;
        n = n->next;
    }

    n = malloc(sizeof(node));
    n->value = value;

    if (p != NULL){
        n->next = p->next;  // não perde pq o valor do index tá salvo no p.next
        p->next = n;
    } else {
        n->next = q->first;
        q->first = n;
    }

    if (index == 0){
        q->last = n;
    }

}




int queue_int2_get(queue_int2 *q) {
    node *n = q->first;
    q->first = n->next;
    if (q->first == NULL){
        q->last = NULL;
    }

    int value = n->value;
    free(n);

    return value;
}



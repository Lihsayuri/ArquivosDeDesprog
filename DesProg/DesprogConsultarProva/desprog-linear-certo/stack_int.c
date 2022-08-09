#include <stdlib.h>

#include "stack_int.h"

struct _node {
    int value;
    struct _node *next;
};

typedef struct _node node;

struct _stack_int {
    node *top;
};

stack_int *stack_int_new() {
    stack_int *s = malloc(sizeof(stack_int));
    s->top = NULL;
    return s;
}

// void stack_int_delete(stack_int **_s) {
//     stack_int *s = *_s;

//     for (node *n = s->top; n != NULL; n = n->next){
//         node *next = n->next;
//         free(n);
//         n = next;
//     }

//     free(s);
//     *_s = NULL;
// }


void stack_int_delete(stack_int **_s) {
    stack_int *s = *_s;
    node *n = s->top;
    while (n != NULL) {
        node *next = n->next; // primeiro fazemos um "backup" do next
        free(n);              // aí estamos livres para liberar o n
        n = next;             // e usamos o "backup" para "andar"
    }
    free(s);
    *_s = NULL;
}

int stack_int_empty(stack_int *s) {
    return s->top == NULL;
}

void stack_int_push(stack_int *s, int value) {
    node *n = malloc(sizeof(node));
    n->value = value;
    n->next = s->top;
    s->top = n;
}

int stack_int_pop(stack_int *s) {
    node *n = s->top;
    s->top = n->next;
    int value = n->value;
    free(n);
    return value;
}

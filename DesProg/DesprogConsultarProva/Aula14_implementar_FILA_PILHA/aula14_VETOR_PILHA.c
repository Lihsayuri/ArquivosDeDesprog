#include <stdio.h>
#include <stdlib.h>

typedef struct _stack_int {
    int capacity;
    int *data;
    int size;
} stack_int;

stack_int *stack_int_new(int capacity) {
    stack_int *s = malloc(sizeof(stack_int));
    s->capacity = capacity;
    s->data = malloc(capacity * sizeof(int));
    s->size = 0;
    return s;
}

void stack_int_delete(stack_int **_s) {
    stack_int *s = *_s;
    free(s->data);
    free(s);
    *_s = NULL;
}

int stack_int_empty(stack_int *s) {
    return (s->size == 0);
}

int stack_int_full(stack_int *s) {
    return (s->size == s->capacity);
}

void stack_int_push(stack_int *s, int value) {
    s->data[s->size] = value; // escreve o novo valor no novo topo
    s->size++;                // move o topo para a direita (sobe)
}

int stack_int_pop(stack_int *s) {
    s->size--;                    // move o topo para a esquerda (desce)
    int value = s->data[s->size]; // guarda o valor do topo atual

    return value;
}

int stack_int_genpop(stack_int *s, int index){ // para remover shifta para esquerda, logo o loop é pra direita.
    int value = s->data[index];
    s->size--;

    for (int i = index; i < s->size; i++){  
        s->data[i] = s->data[i+1];
    }

    return value;
}

void stack_int_push(stack_int *s, int value, int index){
    int i;
    for (i = s->size; i > s->size - index; i--){
        s->data[i] = s->data[i-1];
    }

    s->data[i] = value;
    s->size++;
}

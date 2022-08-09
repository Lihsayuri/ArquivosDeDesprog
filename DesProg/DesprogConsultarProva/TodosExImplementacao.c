#include <stdlib.h>


// PILHA EM VETOR:

// Você sabia que o pop das listas do Python aceita um índice como parâmetro? Se você chamar pop(0), o método remove e devolve 
// o elemento mais fundo da pilha (ou seja, mais longe do topo). Se você chamar pop(1), o método remove e devolve o segundo elemento
// mais fundo da pilha e assim em diante.

// Adicione à implementação original uma função

typedef struct _stack_int {
    int capacity;
    int *data;
    int size;
} stack_int;

int stack_int_genpop(stack_int *s, int index){
    int value = s->data[index];  // não esquecer de guardar o valor que vou retornar;
    s->size--; // já diminui o tamanho já que vamos dar um pop;

    for (int i = index; i < s->size; i++){
        s->data[i]  = s->data[i+1];  // se queremos remover um valor e o shift é para esquerda, então o loop é para a direita;

    return value;
}

// Considere uma generalização do método push que, além do valor a ser inserido, recebe também um índice não-negativo.

// Se o índice for 0, esse método faz a mesma coisa que o push original, ou seja, insere o valor no topo. Se ele for 1, o método insere 
// o valor de forma que seja o primeiro depois do topo (deslocando elementos para a direita conforme necessário). Se for 2, ele insere 
// o valor de forma que seja o segundo depois do topo (deslocando elementos para a direita conforme necessário). Se 3, insere o valor 
// de forma que seja o terceiro depois do topo (deslocando elementos para a direita conforme necessário). E assim em diante.


// desloca elementos para direita, então o loop é para esquerda [--]

void stack_int_push(stack_int *s, int value, int index);{
    int i; 
    for (i = s->size; i > s->size - index; i--){
        s->data[i] = s->data[i-1]; // vai guardando o anterior no próximo.
    }

    s->data[i] = value;
    s->size++;
}


// --------------------------------------------------------------------------------------------------------------------------
// --------------------------------------------------------------------------------------------------------------------------



// LISTA LIGADA EM PILHA

// Considere a implementação de pilha baseada em lista ligada que foi vista em aula.
// que faça a mesma versão especial do pop da questão anterior

// Você sabia que o pop das listas do Python aceita um índice como parâmetro? Se você chamar pop(0), o método remove e 
// devolve o elemento mais fundo da pilha (ou seja, mais longe do topo). Se você chamar pop(1), o método remove e devolve o 
// segundo elemento mais fundo da pilha e assim em diante.


typedef struct _node {
    int value;
    struct _node *next;
} node;

typedef struct _stack_int2 {
    node *top;
} stack_int2;

int genpop_ligada(stack_int2 *s, int index);{
    node *n;
    int size = 0;
    for (n = s->top; n != NULL; n = n->next){
        size++;
    }

    node *p;
    node *n = s->top;

    for (int i = 0; i < size - index - 1; i--){
        p = n;
        n = n->next; // guardando exatamente quem tá no index agora
    }


    // Se o anterior não for NULL, significa que ele não é o primeiro;
    if (p != NULL){
        p->next = n->next; // o next do index;
    } else {
        s->top = n->next;
    }

    int value = n->value;
    free(n);
    return value;
}

// Se o índice for 0, esse método faz a mesma coisa que o push original, ou seja, insere o valor no topo. Se ele for 1, o 
// método insere o valor de forma que seja o primeiro depois do topo (deslocando elementos para a direita conforme necessário). 
// Se for 2, ele insere o valor de forma que seja o segundo depois do topo (deslocando elementos para a direita conforme necessário). 
// Se 3, insere o valor de forma que seja o terceiro depois do topo (deslocando elementos para a direita conforme necessário). E assim
// em diante.


void push_ligada(stack_int2 *s, int value, int index){
    // 2 depois do topo 
    node *n = s->top;
    node *p = NULL;
    for (int i = 0; i < index; i++){
        p = n;
        n = n->next;
    }

    n = malloc(sizeof(node));
    n->value = value;  // não perde pq o valor do index tá salvo no p.next

    if (p != NULL){
        n->next = p->next;
        p->next = n;
    } else {
        n->next = s->top; // next do meu top atual vai ser o antigo top
        s->top = n; // novo top, vai ser meu n inserido
    }

}


// --------------------------------------------------------------------------------------------------------------------------
// --------------------------------------------------------------------------------------------------------------------------

// FILA EM VETOR:

typedef struct _queue_int {
    int capacity;
    int *data;
    int size;
    int begin;
    int end;
} queue_int;

// Se o índice for 0, esse método faz a mesma coisa que o put original, ou seja, insere o valor como último da fila. Se ele for 1,
// o método insere o valor como penúltimo da fila (deslocando elementos para a direita conforme necessário). Se for 2, ele insere
// o valor como antepenúltimo da fila (deslocando elementos para a direita conforme necessário). E assim em diante.

void queue_int_genput(queue_int *q, int value, int index) {
    int i = q->end;
    while (i != (q->end - index) % q->capacity) {
        int prev = (i - 1) % q->capacity;
        q->data[i] = q->data[prev];
        i = prev;
    }
    q->data[i] = value;
    q->end = (q->end + 1) % q->capacity; // eu tinha esquecido desta linha
    q->size++;
}

int queue_int_genpop(queue_int *q, int index){
    int i = (q->begin + index + 1) % q->capacity;

    int value = q->data[i];
    q->size--; // já diminui o tamanho já que vamos dar um pop;


    q->begin = (q->begin + 1) % q->capacity;

    while (i != q->begin){
        int prev = (i-1) % q->capacity;
        q->data[i] = q->data[prev];
        i = prev;
    }

    return value;
}

// -----------------------------------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------------------------------------


// Se o índice for 0, esse método faz a mesma coisa que o put original, ou seja, insere o valor como último da fila. Se ele for 1, 
// o método insere o valor como penúltimo da fila (deslocando elementos para a direita conforme necessário). Se for 2, ele insere o 
// valor como antepenúltimo da fila (deslocando elementos para a direita conforme necessário). E assim em diante.


// FILA EM LISTA LIGADA

typedef struct _node node;

typedef struct _node {
    int value;
    struct _node *next;
} node;


struct _queue_int {
    node *first;
    node *last;
};

typedef struct _queue_int {
    node *first;
    node *last;
} queue_int2;

void queue_int_genput(queue_int *q, int value, int index) {
    node *n;
    int size = 0;

    for (n = q->first; n != NULL; n = n->next){
        size++;
    }

    node *p = NULL;
    n = q->first;
    for (int i = 0 ; i < (size- index); i++){
        p = n; // next do previous é o q tá no meu index agora
        n = n->next;
    }

    n = malloc(sizeof(node));
    n->value = value;

    if (p != NULL){    // garante que não é o primeiro. Mas pode ser o último também;
        n->next = p->next;
        p->next = n;
    } else {
        n->next = q->first;
        q->first = n;
    }

    if (index == 0){
        q->last = n;
    }
}


int queue_int_genpop(queue_int2 *q, int index){
    node *n;
    int size = 0;

    for (n = q->first; n != NULL; n = n->next){
        size++;
    }

    node *p = NULL;
    node *n = q->first;
    for (int i = 0 ; i < index; i++){
        p = n; // next do previous é o q tá no meu index agora
        n = n->next;
    }

    if (p != NULL){
        p->next = n->next;

    } else {
        q->first = n->next;
    }

    if (index == size - 1){
        q->last = p;
    }

    int value = n->value;
    free(n);
    return value;
}
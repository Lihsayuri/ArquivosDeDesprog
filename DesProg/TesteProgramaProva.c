#include <stdio.h>

typedef struct _node {
    int value;
    struct _node *next;
} node;

typedef struct _stack_int {
    node *top;
} stack_int;


int genpop_ligada(stack_int *s, int index){
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

main(){
    node n1;
    node n2;
    node n3;
    node n4;

    n4.next = NULL;
    n4.value = 5;

    n3.value = 2;
    n3.next = &n4;

    n2.value = 3;
    n2.next = &n3;

    n1.value = 1;
    n1.next = &n2;

    stack_int s;
    s.top = &n1;

    node *n = s.top;

    while (n != NULL){
        printf("%d \n", n->value);
        n = n->next;
    }



}




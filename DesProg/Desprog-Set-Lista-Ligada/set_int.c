#include <stdlib.h>

#include "set_int.h"

struct _node {
    int value;
    struct _node *next;
};

typedef struct _node node;

struct _set_int {
    node *first;
};

set_int *set_int_new() {
    set_int *s = malloc(sizeof(set_int));
    s->first = NULL;
    return s;
}

void set_int_delete(set_int **_s) {
    set_int *s = *_s;
    node *n = s->first;
    while (n != NULL) {
        node *next = n->next;
        free(n);
        n = next;
    }
    free(s);
    *_s = NULL;
}

int set_int_empty(set_int *s) {
    return s->first == NULL;
}

int set_int_has(set_int *s, int value) {
    node *n;
    for (n = s->first; n != NULL; n = n->next){
        if (n->value == value){
            return 1;
        }
    }

    return 0;
}

void set_int_insert(set_int *s, int value) {
    node *n;
    for (n = s->first; n != NULL; n = n->next){
        if (n->value == value){
            return;
        }
    }

    n = malloc(sizeof(node));
    n->value = value;
    n->next = s->first;

    s->first = n;

}

void set_int_remove(set_int *s, int value) {
    node *n;
    node *p = NULL; //começa null pois o anterior do n que começa no first não existe
    for (n = s->first; n != NULL; n = n->next){
        if (n->value == value){
            break;
        }
        p = n;
    }

    if (n == NULL){
        return;
    }

    if (p != NULL){
        p->next = n->next; // se p é NULL e n não é NULL, é porque queremos remover o first;
    } else {
        s->first = n->next;
    }
 
}



// void set_int_insert(set_int *s, int value) {
//     node *p = NULL;
//     node *n;
//     for (n = s->first; n != NULL; n = n->next) {
//         if (n->value == value) {
//             return;
//         }
//         if (n->value > value) {
//             break;
//         }
//         p = n;
//     }
//     n = malloc(sizeof(node));
//     n->value = value;
//     if (p != NULL) {
//         n->next = p->next;
//         p->next = n;
//     } else {
//         n->next = s->first;
//         s->first = n;
//     }
// }

//Lista ordenada

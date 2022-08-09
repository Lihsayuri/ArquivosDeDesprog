#include <stdlib.h>

#include "set_int.h"

typedef struct _node
{
    int value;
    struct _node *left;
    struct _node *right;
} node;

typedef struct _set_int
{
    node *root;
} set_int;

node *maximum(set_int *s)
{

    node *n = s->root;

    while (n != n->right)
    {
        n = n->right;
    }

    return n;
}

int set_int_has(set_int *s, int value)
{
    node *n = s->root;

    while (n != NULL)
    {
        if (value == n->value)
        {
            return 1;
        }

        if (value < n->value)
        {
            n = n->left;
        }
        else
        {
            n = n->right;
        }
    }

    return 0;
}

void set_int_insert(set_int *s, int value)
{
    node *p = NULL;
    node *n = s->root;

    while (n != NULL)
    {
        if (value == n->value)
        {
            return;
        }

        p = n;
        if (value < n->value)
        {
            n = n->left;
        }
        else
        {
            n = n->right;
        }
    }

    n = malloc(sizeof(node));
    n->value = value;
    n->left = NULL;
    n->right = NULL;

    if (p != NULL) {
        if (value < p->value) {
            p->left = n;
        } else {
            p->right = n;
        }
    } else {
        s->root = n;
    }

    // Cria novo nó e pendura em p.
}


void set_int_remove(set_int *s, int value) {
    node *p = NULL;
    node *n = s->root;

    while (n != NULL) {
        if (value == n->value) {
            break; // Se encontramos, vamos interromper.
        }

        p = n;
        if (value < n->value) {
            n = n->left;
        } else {
            n = n->right;
        }
    }
    if (n == NULL) {
        return;
    }

    // Se chegamos aqui, o loop foi interrompido.
    // Se o loop foi interompido, value está em s
    // e é justamente o valor do nó apontado por n.
    // Falta escrever aqui o código de remoção.
}
#include <stdio.h>
#include <stdlib.h>
#include "LISTA.h"

/* definição da estrutura */
struct lista {
    int info;
    struct lista* prox;
};

/* cria uma lista vazia */
Lista* lst_cria(void) {
    return NULL;
}

/* libera toda a lista */
void lst_libera(Lista* l) {
    Lista* p = l;
    while (p != NULL) {
        Lista* t = p->prox;
        free(p);
        p = t;
    }
}

/* insere um elemento no início da lista */
Lista* lst_insere(Lista* l, int i) {
    Lista* novo = (Lista*) malloc(sizeof(Lista));
    if (novo == NULL) {
        return l; // falha de alocação
    }
    novo->info = i;
    novo->prox = l;
    return novo;
}

/* retira da lista a primeira ocorrência do valor v */
Lista* retira(Lista* l, int v) {
    Lista* ant = NULL;
    Lista* p = l;

    while (p != NULL && p->info != v) {
        ant = p;
        p = p->prox;
    }

    if (p == NULL) {
        return l; // elemento não encontrado
    }

    if (ant == NULL) {
        l = p->prox; // remove o primeiro elemento
    } else {
        ant->prox = p->prox;
    }

    free(p);
    return l;
}

/* verifica se a lista está vazia */
int lst_vazia(Lista* l) {
    return (l == NULL);
}

/* busca um elemento na lista */
Lista* lst_busca(Lista* l, int v) {
    Lista* p;
    for (p = l; p != NULL; p = p->prox) {
        if (p->info == v) {
            return p;
        }
    }
    return NULL;
}

/* imprime os elementos da lista */
Lista* lst_imprime(Lista* l) {
    Lista* p;
    for (p = l; p != NULL; p = p->prox) {
        printf("%d -> ", p->info);
    }
    printf("NULL\n");
    return l;
}

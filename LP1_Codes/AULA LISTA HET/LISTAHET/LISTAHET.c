#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LISTAHET.h"

ListaHet* cria_lista() {
    ListaHet* l = (ListaHet*) malloc(sizeof(ListaHet));
    if (l == NULL) return NULL;

    l->inicio = NULL;
    l->fim = NULL;
    l->tamanho = 0;

    return l;
}

static No* cria_no(Tipo tipo) {
    No* novo = (No*) malloc(sizeof(No));
    if (novo == NULL) return NULL;

    novo->tipo = tipo;
    novo->prox = NULL;
    return novo;
}

int insere_int(ListaHet* l, int valor) {
    if (l == NULL) return 0;

    No* novo = cria_no(INT);
    if (novo == NULL) return 0;

    novo->dado.i = valor;

    if (l->fim == NULL)
        l->inicio = l->fim = novo;
    else {
        l->fim->prox = novo;
        l->fim = novo;
    }

    l->tamanho++;
    return 1;
}

int insere_float(ListaHet* l, float valor) {
    if (l == NULL) return 0;

    No* novo = cria_no(FLOAT);
    if (novo == NULL) return 0;

    novo->dado.f = valor;

    if (l->fim == NULL)
        l->inicio = l->fim = novo;
    else {
        l->fim->prox = novo;
        l->fim = novo;
    }

    l->tamanho++;
    return 1;
}

int insere_char(ListaHet* l, char valor) {
    if (l == NULL) return 0;

    No* novo = cria_no(CHAR);
    if (novo == NULL) return 0;

    novo->dado.c = valor;

    if (l->fim == NULL)
        l->inicio = l->fim = novo;
    else {
        l->fim->prox = novo;
        l->fim = novo;
    }

    l->tamanho++;
    return 1;
}

int insere_string(ListaHet* l, const char* valor) {
    if (l == NULL) return 0;

    No* novo = cria_no(STRING);
    if (novo == NULL) return 0;

    novo->dado.s = (char*) malloc(strlen(valor) + 1);
    if (novo->dado.s == NULL) {
        free(novo);
        return 0;
    }

    strcpy(novo->dado.s, valor);

    if (l->fim == NULL)
        l->inicio = l->fim = novo;
    else {
        l->fim->prox = novo;
        l->fim = novo;
    }

    l->tamanho++;
    return 1;
}

void imprime_lista(ListaHet* l) {
    if (l == NULL) return;

    No* atual = l->inicio;

    while (atual != NULL) {

        switch (atual->tipo) {
            case INT:
                printf("[INT: %d]", atual->dado.i);
                break;
            case FLOAT:
                printf("[FLOAT: %.2f]", atual->dado.f);
                break;
            case CHAR:
                printf("[CHAR: %c]", atual->dado.c);
                break;
            case STRING:
                printf("[STRING: %s]", atual->dado.s);
                break;
        }

        printf(" -> ");
        atual = atual->prox;
    }

    printf("NULL\n");
}

void libera_lista(ListaHet* l) {
    if (l == NULL) return;

    No* atual = l->inicio;

    while (atual != NULL) {
        No* temp = atual;
        atual = atual->prox;

        if (temp->tipo == STRING)
            free(temp->dado.s);

        free(temp);
    }

    free(l);
}
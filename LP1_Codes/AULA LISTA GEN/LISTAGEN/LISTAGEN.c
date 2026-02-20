#include <stdio.h>
#include <stdlib.h>
#include "LISTAGEN.h"

ListaGen* cria_lista() {
    ListaGen* l = (ListaGen*) malloc(sizeof(ListaGen));
    if (l == NULL) return NULL;

    l->inicio = NULL;
    l->fim = NULL;
    l->tamanho = 0;

    return l;
}

int insere_inicio(ListaGen* l, void* dado) {
    if (l == NULL) return 0;

    No* novo = (No*) malloc(sizeof(No));
    if (novo == NULL) return 0;

    novo->dado = dado;
    novo->prox = l->inicio;

    l->inicio = novo;

    if (l->fim == NULL)
        l->fim = novo;

    l->tamanho++;
    return 1;
}

int insere_fim(ListaGen* l, void* dado) {
    if (l == NULL) return 0;

    No* novo = (No*) malloc(sizeof(No));
    if (novo == NULL) return 0;

    novo->dado = dado;
    novo->prox = NULL;

    if (l->fim == NULL) {
        l->inicio = novo;
        l->fim = novo;
    } else {
        l->fim->prox = novo;
        l->fim = novo;
    }

    l->tamanho++;
    return 1;
}

int remove_inicio(ListaGen* l, void (*libera_dado)(void*)) {
    if (l == NULL || l->inicio == NULL) return 0;

    No* temp = l->inicio;
    l->inicio = temp->prox;

    if (l->inicio == NULL)
        l->fim = NULL;

    if (libera_dado != NULL)
        libera_dado(temp->dado);

    free(temp);
    l->tamanho--;
    return 1;
}

int lista_vazia(ListaGen* l) {
    if (l == NULL) return 1;
    return (l->tamanho == 0);
}

int tamanho_lista(ListaGen* l) {
    if (l == NULL) return -1;
    return l->tamanho;
}

void imprime_lista(ListaGen* l, void (*imprime)(void*)) {
    if (l == NULL) return;

    No* atual = l->inicio;
    while (atual != NULL) {
        imprime(atual->dado);
        printf(" -> ");
        atual = atual->prox;
    }
    printf("NULL\n");
}

void libera_lista(ListaGen* l, void (*libera_dado)(void*)) {
    if (l == NULL) return;

    No* atual = l->inicio;
    while (atual != NULL) {
        No* temp = atual;
        atual = atual->prox;

        if (libera_dado != NULL)
            libera_dado(temp->dado);

        free(temp);
    }

    free(l);
}
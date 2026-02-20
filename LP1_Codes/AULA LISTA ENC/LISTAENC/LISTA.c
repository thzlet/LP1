#include <stdio.h>
#include <stdlib.h>
#include "LISTA.h"

Lista* cria_lista() {
    Lista* l = (Lista*) malloc(sizeof(Lista));
    if (l == NULL) return NULL;

    l->inicio = NULL;
    l->fim = NULL;
    l->tamanho = 0;

    return l;
}

int insere_inicio(Lista* l, int valor) {
    if (l == NULL) return 0;

    No* novo = (No*) malloc(sizeof(No));
    if (novo == NULL) return 0;

    novo->dado = valor;
    novo->prox = l->inicio;

    l->inicio = novo;

    if (l->fim == NULL)
        l->fim = novo;

    l->tamanho++;
    return 1;
}

int insere_fim(Lista* l, int valor) {
    if (l == NULL) return 0;

    No* novo = (No*) malloc(sizeof(No));
    if (novo == NULL) return 0;

    novo->dado = valor;
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

int insere_posicao(Lista* l, int valor, int pos) {
    if (l == NULL || pos < 0 || pos > l->tamanho) return 0;

    if (pos == 0) return insere_inicio(l, valor);
    if (pos == l->tamanho) return insere_fim(l, valor);

    No* novo = (No*) malloc(sizeof(No));
    if (novo == NULL) return 0;

    No* atual = l->inicio;
    for (int i = 0; i < pos - 1; i++)
        atual = atual->prox;

    novo->dado = valor;
    novo->prox = atual->prox;
    atual->prox = novo;

    l->tamanho++;
    return 1;
}


int remove_inicio(Lista* l) {
    if (l == NULL || l->inicio == NULL) return 0;

    No* temp = l->inicio;
    l->inicio = temp->prox;

    if (l->inicio == NULL)
        l->fim = NULL;

    free(temp);
    l->tamanho--;
    return 1;
}

int remove_fim(Lista* l) {
    if (l == NULL || l->inicio == NULL) return 0;

    if (l->inicio == l->fim) {
        free(l->inicio);
        l->inicio = NULL;
        l->fim = NULL;
    } else {
        No* atual = l->inicio;
        while (atual->prox != l->fim)
            atual = atual->prox;

        free(l->fim);
        l->fim = atual;
        l->fim->prox = NULL;
    }

    l->tamanho--;
    return 1;
}

int remove_valor(Lista* l, int valor) {
    if (l == NULL || l->inicio == NULL) return 0;

    No* atual = l->inicio;
    No* anterior = NULL;

    while (atual != NULL) {
        if (atual->dado == valor) {
            if (anterior == NULL) {
                l->inicio = atual->prox;
            } else {
                anterior->prox = atual->prox;
            }

            if (atual == l->fim)
                l->fim = anterior;

            free(atual);
            l->tamanho--;
            return 1;
        }

        anterior = atual;
        atual = atual->prox;
    }

    return 0;
}

int busca(Lista* l, int valor) {
    if (l == NULL) return 0;

    No* atual = l->inicio;
    while (atual != NULL) {
        if (atual->dado == valor)
            return 1;
        atual = atual->prox;
    }

    return 0;
}

int elemento_posicao(Lista* l, int pos, int* valor) {
    if (l == NULL || pos < 0 || pos >= l->tamanho) return 0;

    No* atual = l->inicio;
    for (int i = 0; i < pos; i++)
        atual = atual->prox;

    *valor = atual->dado;
    return 1;
}

int tamanho_lista(Lista* l) {
    if (l == NULL) return -1;
    return l->tamanho;
}

int lista_vazia(Lista* l) {
    if (l == NULL) return 1;
    return (l->tamanho == 0);
}

void imprime_lista(Lista* l) {
    if (l == NULL) return;

    No* atual = l->inicio;
    while (atual != NULL) {
        printf("[%d] -> ", atual->dado);
        atual = atual->prox;
    }
    printf("NULL\n");
}

void libera_lista(Lista* l) {
    if (l == NULL) return;

    No* atual = l->inicio;
    while (atual != NULL) {
        No* temp = atual;
        atual = atual->prox;
        free(temp);
    }

    free(l);
}

void inverte_lista(Lista* l) {
    if (l == NULL || l->inicio == NULL) return;

    No* anterior = NULL;
    No* atual = l->inicio;
    No* proximo = NULL;

    l->fim = l->inicio;

    while (atual != NULL) {
        proximo = atual->prox;
        atual->prox = anterior;
        anterior = atual;
        atual = proximo;
    }

    l->inicio = anterior;
}

void ordena_lista(Lista* l) {
    if (l == NULL || l->inicio == NULL) return;

    for (No* i = l->inicio; i != NULL; i = i->prox) {
        for (No* j = i->prox; j != NULL; j = j->prox) {
            if (i->dado > j->dado) {
                int temp = i->dado;
                i->dado = j->dado;
                j->dado = temp;
            }
        }
    }
}

int maior_elemento(Lista* l, int* maior) {
    if (l == NULL || l->inicio == NULL) return 0;

    No* atual = l->inicio;
    *maior = atual->dado;

    while (atual != NULL) {
        if (atual->dado > *maior)
            *maior = atual->dado;
        atual = atual->prox;
    }

    return 1;
}
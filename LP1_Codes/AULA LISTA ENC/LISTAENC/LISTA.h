#ifndef LISTA_H
#define LISTA_H

typedef struct no {
    int dado;
    struct no* prox;
} No;

typedef struct {
    No* inicio;
    No* fim;
    int tamanho;
} Lista;

Lista* cria_lista();

int insere_inicio(Lista* l, int valor);
int insere_fim(Lista* l, int valor);
int insere_posicao(Lista* l, int valor, int pos);

int remove_inicio(Lista* l);
int remove_fim(Lista* l);
int remove_valor(Lista* l, int valor);

int busca(Lista* l, int valor);
int elemento_posicao(Lista* l, int pos, int* valor);
int tamanho_lista(Lista* l);
int lista_vazia(Lista* l);

void imprime_lista(Lista* l);
void libera_lista(Lista* l);
void inverte_lista(Lista* l);
void ordena_lista(Lista* l);
int maior_elemento(Lista* l, int* maior);

#endif
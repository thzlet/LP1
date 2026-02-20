#ifndef LISTAGEN_H
#define LISTAGEN_H

typedef struct no {
    void* dado;
    struct no* prox;
} No;

typedef struct {
    No* inicio;
    No* fim;
    int tamanho;
} ListaGen;

ListaGen* cria_lista();
void libera_lista(ListaGen* l, void (*libera_dado)(void*));

int insere_inicio(ListaGen* l, void* dado);
int insere_fim(ListaGen* l, void* dado);

int remove_inicio(ListaGen* l, void (*libera_dado)(void*));

int lista_vazia(ListaGen* l);
int tamanho_lista(ListaGen* l);

void imprime_lista(ListaGen* l, void (*imprime)(void*));

#endif
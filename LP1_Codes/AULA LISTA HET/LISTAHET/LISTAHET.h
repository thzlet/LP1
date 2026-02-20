#ifndef LISTAHET_H
#define LISTAHET_H

typedef enum {
    INT,
    FLOAT,
    CHAR,
    STRING
} Tipo;

typedef union {
    int i;
    float f;
    char c;
    char* s;
} Dado;

typedef struct no {
    Tipo tipo;
    Dado dado;
    struct no* prox;
} No;

typedef struct {
    No* inicio;
    No* fim;
    int tamanho;
} ListaHet;

ListaHet* cria_lista();
void libera_lista(ListaHet* l);

int insere_int(ListaHet* l, int valor);
int insere_float(ListaHet* l, float valor);
int insere_char(ListaHet* l, char valor);
int insere_string(ListaHet* l, const char* valor);

void imprime_lista(ListaHet* l);

#endif
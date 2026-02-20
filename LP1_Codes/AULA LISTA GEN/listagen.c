#include <stdio.h>
#include <stdlib.h>
#include "LISTAGEN.h"

void imprime_int(void* dado) {
    printf("[%d]", *(int*)dado);
}

void libera_int(void* dado) {
    free(dado);
}

void imprime_float(void* dado) {
    printf("[%.2f]", *(float*)dado);
}

void libera_float(void* dado) {
    free(dado);
}

typedef struct {
    char nome[30];
    int idade;
} Pessoa;

void imprime_pessoa(void* dado) {
    Pessoa* p = (Pessoa*) dado;
    printf("[%s - %d]", p->nome, p->idade);
}

void libera_pessoa(void* dado) {
    free(dado);
}

int main() {

    printf("=== TESTE COM INTEIROS ===\n");
    ListaGen* listaInt = cria_lista();

    for (int i = 1; i <= 3; i++) {
        int* valor = (int*) malloc(sizeof(int));
        *valor = i * 10;
        insere_fim(listaInt, valor);
    }

    imprime_lista(listaInt, imprime_int);
    libera_lista(listaInt, libera_int);

    printf("\n=== TESTE COM FLOAT ===\n");
    ListaGen* listaFloat = cria_lista();

    for (int i = 1; i <= 3; i++) {
        float* valor = (float*) malloc(sizeof(float));
        *valor = i * 1.5;
        insere_inicio(listaFloat, valor);
    }

    imprime_lista(listaFloat, imprime_float);
    libera_lista(listaFloat, libera_float);

    printf("\n=== TESTE COM STRUCT ===\n");
    ListaGen* listaPessoa = cria_lista();

    Pessoa* p1 = (Pessoa*) malloc(sizeof(Pessoa));
    sprintf(p1->nome, "Ana");
    p1->idade = 20;

    Pessoa* p2 = (Pessoa*) malloc(sizeof(Pessoa));
    sprintf(p2->nome, "Carlos");
    p2->idade = 25;

    insere_fim(listaPessoa, p1);
    insere_fim(listaPessoa, p2);

    imprime_lista(listaPessoa, imprime_pessoa);
    libera_lista(listaPessoa, libera_pessoa);

    return 0;
}
#include <stdio.h>
#include "LISTAHET.h"

int main() {

    ListaHet* lista = cria_lista();

    insere_int(lista, 10);
    insere_float(lista, 3.14);
    insere_char(lista, 'A');
    insere_string(lista, "Estrutura");
    insere_string(lista, "de Dados");
    insere_int(lista, 99);

    printf("Lista Heterogênea:\n");
    imprime_lista(lista);

    libera_lista(lista);

    return 0;
}
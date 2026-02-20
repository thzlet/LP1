#include <stdio.h>
#include "LISTA.h"

int main() {

    Lista* l = cria_lista();

    if (l == NULL) {
        printf("Erro ao criar lista.\n");
        return 1;
    }

    insere_fim(l, 10);
    insere_fim(l, 20);
    insere_inicio(l, 5);
    insere_posicao(l, 15, 2);

    printf("Lista inicial:\n");
    imprime_lista(l);

    printf("\nRemovendo 20...\n");
    remove_valor(l, 20);
    imprime_lista(l);

    printf("\nInvertendo lista...\n");
    inverte_lista(l);
    imprime_lista(l);

    printf("\nOrdenando lista...\n");
    ordena_lista(l);
    imprime_lista(l);

    int maior;
    if (maior_elemento(l, &maior))
        printf("\nMaior elemento: %d\n", maior);

    libera_lista(l);

    return 0;
}
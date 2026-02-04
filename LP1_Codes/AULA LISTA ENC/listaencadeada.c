#include <stdio.h>
#include "LISTA.h"

int main (void) {
    Lista* l;
    l = lst_cria();
    l = lst_insere (l, 23);
    l = lst_insere(l, 45);
    l = lst_insere(l, 56);
    lst_imprime(l);
    // l = lst_retira(l, 45);
    lst_imprime(l);
    lst_libera(l);

    return 0;
}
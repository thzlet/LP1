/*TAD: lista de inteiros */

typedef struct lista Lista;
Lista* lst_cria (void);
void lst_libera (Lista* l);

Lista* lst_insere (Lista* l, int i);
Lista* retira (Lista* l, int v);

int lst_vazia (Lista* l);
Lista* lst_busca (Lista* l, int v);
Lista* lst_imprime (Lista* l);
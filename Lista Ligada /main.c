#include <stdio.h>
#include <stdbool.h>
#include "lista.h"

int main() {
    LISTA lista;
    inicializarLista(&lista);

    REGISTRO r1 = {10};
    REGISTRO r2 = {20};
    REGISTRO r3 = {15};
    REGISTRO r4 = {10}; 

    inserirElemListaOrd(&lista, r1);
    inserirElemListaOrd(&lista, r2);
    inserirElemListaOrd(&lista, r3);

    exibirLista(&lista);       
    exibirListaReversa(&lista); 

    bool sucesso = inserirElemListaOrd(&lista, r4);
    if (!sucesso) {
        printf("Elemento duplicado não inserido: %d\n", r4.chave);
    }

    exibirLista(&lista); 

    return 0;
}

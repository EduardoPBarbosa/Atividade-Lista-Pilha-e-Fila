#ifndef LISTA_H
#define LISTA_H

typedef int TIPOCHAVE;

typedef struct {
    TIPOCHAVE chave;
    // outros campos...
} REGISTRO;

typedef struct aux {
    REGISTRO reg;
    struct aux *ant, *prox;
} ELEMENTO;

typedef ELEMENTO* PONT;

typedef struct {
    PONT inicio;
} LISTA;

// Funções para manipulação da lista
void inicializarLista(LISTA* l);
bool inserirElemListaOrd(LISTA* l, REGISTRO reg);
void exibirLista(LISTA* l);
void exibirListaReversa(LISTA* l);

#endif // LISTA_H

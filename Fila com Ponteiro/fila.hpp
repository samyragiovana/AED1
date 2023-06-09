#ifndef FILA_H
#define FILA_H

/* Registro para representar os valores de cada elemento */
typedef struct TipoItem {
    int valor;
} TipoItem;

/* Registro pra representar cada elemento */
typedef struct TipoElemento {
    TipoItem item;
    struct TipoElemento *prox;
} TipoElemento;

/* Ponteiro auxiliar */
typedef struct TipoElemento *Apontador;

typedef struct TipoFila {
    Apontador inicio, fim;
    int tamanho;
} TipoFila;

void InicializaFila(TipoFila *fila);

bool VerificaFilaVazia(TipoFila *fila);

void Enfileira(TipoFila *fila, TipoItem item);

void Desenfileira(TipoFila *fila);

void EsvaziaFila(TipoFila *fila);

void ImprimeFila(TipoFila *fila);

#endif
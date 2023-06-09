#include <iostream>
#include <windows.h>
 
using namespace std;

typedef struct TipoItem{
    int valor;
} TipoItem;

typedef struct TipoElemento *Apontador;

typedef struct TipoElemento{ //Célula
    TipoItem item;
    struct TipoElemento *prox;
} TipoElemento;

typedef struct TipoPilha {
    Apontador topo;
    int tamanho;
} TipoPilha;

void fazPilhaVazia(TipoPilha *pilha);
bool verificaPilhaVazia(TipoPilha *pilha);
void empilha(TipoPilha *pilha, TipoItem item);
void desempilha(TipoPilha *pilha, TipoItem *item);
void exibePilha (TipoPilha *pilha);
int getTamanho(TipoPilha *pilha);


int main() {
    TipoPilha pilha;
    TipoItem binario;
    
    fazPilhaVazia(&pilha);
    int numerador, resto;

    cout << "Digite um numero inteiro: ";
    cin >> numerador;

    while (numerador != 0) {          // 13           // 6          // 3           // 1 
        resto = numerador % 2;        // r: 1         // r: 0       // r: 1        // r: 1
        binario.valor = resto;        // v: 1         // v: 0       // v: 1        // v: 1
        empilha(&pilha, binario);     // 1            // 0          // 1           // 1
        numerador = numerador / 2;    // 6            // 3          // 1           // 0
    }

    exibePilha(&pilha);

    return 0;
}

void fazPilhaVazia(TipoPilha *pilha) {
    pilha->topo = NULL;
    pilha->tamanho = 0;
}

bool verificaPilhaVazia(TipoPilha *pilha) {
    if (pilha->topo == NULL) {
        return true;
    } else return false;
}

void empilha(TipoPilha *pilha, TipoItem item) {
    Apontador novo;
    novo = new TipoElemento;
    novo->item = item;
    novo->prox = pilha->topo;
    pilha->topo = novo;
    pilha->tamanho++;
}

void desempilha(TipoPilha *pilha, TipoItem *item) {
    Apontador aux; /* celula a ser removida */
    
    if (verificaPilhaVazia(pilha)) {
        return ;
    }
 
    if (pilha->tamanho == 1) {
        aux = pilha->topo;
        *item = aux->item;
        pilha->topo = NULL;
        free(aux);
        pilha->tamanho--;
    } else {
        aux = pilha->topo;
        pilha->topo = aux->prox; //pilha->topo->prox
        *item = aux->item;
        free(aux);
        pilha->tamanho--;
    }
}

void exibePilha (TipoPilha *pilha) {
    Apontador x;
    x = pilha->topo;
    int cont = pilha->tamanho;
    while (cont > 0) {
        cout << x->item.valor;
        cont--;
        x = x->prox;
    }
}

int getTamanho(TipoPilha *pilha) {
    return pilha->tamanho;
}
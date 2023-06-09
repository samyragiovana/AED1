#include <iostream>
#include <windows.h>
 
using namespace std;

typedef struct TipoItem{
    string valor,naipe;
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
    TipoItem carta1,carta2,carta3;
    
    fazPilhaVazia(&pilha);

    carta1.valor = "Sete";
    carta1.naipe = "Copas";
    carta2.valor = "Quatro";
    carta2.naipe = "Ouros";
    carta3.valor = "Dama";
    carta3.naipe = "Espadas";

    empilha(&pilha,carta1);
    empilha(&pilha,carta2);
    empilha(&pilha,carta3);
    
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
        cout << x->item.valor << " de " << x->item.naipe << endl;
        cont--;
        x = x->prox;
    }
}

int getTamanho(TipoPilha *pilha) {
    return pilha->tamanho;
}
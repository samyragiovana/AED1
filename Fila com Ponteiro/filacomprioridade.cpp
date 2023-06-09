#include <iostream>
#include <windows.h>
using namespace std;

typedef struct TipoItem {
    int valor;
    bool prioridade = false;
} TipoItem;

typedef struct TipoElemento {
    TipoItem item;
    struct TipoElemento *prox;
} TipoElemento;

typedef struct TipoElemento *Apontador;

typedef struct TipoFilaPrioridade {
    Apontador inicio, fim;
    int tamanho;
} TipoFilaPrioridade;

void InicializaFila(TipoFilaPrioridade *fila);
bool VerificaFilaVazia(TipoFilaPrioridade *fila);
void EnfileiraPrioridade(TipoFilaPrioridade *fila, TipoItem item);
void Desenfileira(TipoFilaPrioridade *fila);
void ImprimeFila(TipoFilaPrioridade *fila);

int main() {
    TipoFilaPrioridade f;
    TipoItem i;

    InicializaFila(&f);

    if (VerificaFilaVazia(&f)) {
        cout << "Fila vazia.";
    }

    i.valor = 35;
    EnfileiraPrioridade(&f, i);
    ImprimeFila(&f);
    cout << "Tamanho: " << f.tamanho << endl;

    i.valor = 56;
    EnfileiraPrioridade(&f, i);
    ImprimeFila(&f);
    cout << "Tamanho: " << f.tamanho << endl;

    i.valor = 68;
    i.prioridade = true;
    EnfileiraPrioridade(&f, i);
    ImprimeFila(&f);
    cout << "Tamanho: " << f.tamanho << endl;

    i.valor = 65;
    i.prioridade = true;
    EnfileiraPrioridade(&f, i);
    ImprimeFila(&f);
    cout << "Tamanho: " << f.tamanho << endl;

    i.valor = 71;
    i.prioridade = true;
    EnfileiraPrioridade(&f, i);
    ImprimeFila(&f);
    cout << "Tamanho: " << f.tamanho << endl;

    i.valor = 24;
    i.prioridade = false;
    EnfileiraPrioridade(&f, i);
    ImprimeFila(&f);
    cout << "Tamanho: " << f.tamanho << endl;

    Desenfileira(&f);
    ImprimeFila(&f);
    cout << "Tamanho: " << f.tamanho << endl;

    return 0;
}

void InicializaFila(TipoFilaPrioridade *fila) {
    fila->inicio = NULL;
    fila->fim = NULL;
    fila->tamanho = 0;
}

bool VerificaFilaVazia(TipoFilaPrioridade *fila) {
    if (fila->inicio == NULL) {
        return true;
    } else return false;
}

void EnfileiraPrioridade(TipoFilaPrioridade *fila, TipoItem i) { 
    Apontador novo, aux;
    novo = new TipoElemento;
    novo->item = i;
    novo->prox = NULL;

    /* Se a fila estiver vazia, elemento será inserido no início */
    if (VerificaFilaVazia(fila)) {
        fila->inicio = novo;
        fila->fim = novo;
    } else {
        // É prioridade?
        if (i.prioridade) {
            // Não existe ninguém com prioridade na fila?
            if (!fila->inicio->item.prioridade) {
                // Insere no começo da fila
                aux = fila->inicio;
                fila->inicio = novo;
                fila->inicio->prox = aux;
            }
            // Já existe alguém com prioridade na fila?
            else {
                // Percorre a fila de prioridade
                aux = fila->inicio;
                while (aux->prox->item.prioridade) {
                    aux = aux->prox;
                }
                novo->prox = aux->prox;
                aux->prox = novo;
            }
        }
        else {
            // Enfileira normalmente
            fila->fim->prox = novo;
            fila->fim = novo;
        }
    }
    cout << endl << novo->item.valor << " inserido na fila.\n";
    fila->tamanho++;
}

void Desenfileira(TipoFilaPrioridade *fila) {
    Apontador aux;
    if (VerificaFilaVazia(fila)) {
        cout << "\nFila vazia.";
        return;
    }

    aux = fila->inicio;
    cout << endl << fila->inicio->item.valor << " removido da fila.\n";
    fila->inicio = fila->inicio->prox;
    free(aux);
    fila->tamanho--;
}

void ImprimeFila(TipoFilaPrioridade *fila) {
    Apontador aux;
    if (VerificaFilaVazia(fila)) {
        cout << "\nFila vazia.";
    } else {
        aux = fila->inicio;
        cout << "Fila: ";
        do {
            cout << aux->item.valor << " ";
            aux = aux->prox;
        } while (aux != NULL);
    }
}
#include <iostream>
#include <windows.h>

#define MAXTAM 5
 
using namespace std;

typedef struct {
    int inicio, fim;
    int Fila[MAXTAM];
    int tamanho;
} TFila;

/* Funções básicas de verificação: 
   [x] Inicializar a fila: necessária para criação da struct TFila
   [x] Verificar se a Fila está Vazia: necessária ao Desenfileirar um valor 
   [x] Verificar se a Fila está Cheia: necessária ao Enfileirar um novo valor
*/

void TFila_Inicializa(TFila *f);
bool TFila_Vazia(TFila *f);
bool TFila_Cheia(TFila *f);

/* Funções básicas de manipulação: 
   [x] Enfileirar um valor no fim da fila: necessário verificar se há espaço
   [x] Desenfileirar um valor do inicio da fila: necessário verificar se há valor na fila 
*/

void TFila_Enfileira(TFila *f, int x);
int TFila_Desenfileira(TFila *f);

/* Funções complementares: 
   [x] Imprimir a fila
   [x] Tamanho da fila: calculado pelo f.tamanho 
*/

void TFila_Imprime(TFila *f);
 
int main() {
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);
    system("cls");

    TFila f;
    TFila_Inicializa(&f);

    TFila_Enfileira(&f, 2);
    TFila_Enfileira(&f, 5);
    TFila_Enfileira(&f, 7);
    TFila_Enfileira(&f, 6);
    TFila_Enfileira(&f, 4);
    TFila_Enfileira(&f, 1);
    
    TFila_Imprime(&f);
    cout << "Tamanho: " << f.tamanho << endl;

    cout << "Valor desenfileirado: " << TFila_Desenfileira(&f) << endl;

    TFila_Imprime(&f);
    cout << "Tamanho: " << f.tamanho << endl;

    if (TFila_Vazia(&f)) { // 1 vazia, 0 nao 
        cout << "Fila vazia.\n";
    }

    if (TFila_Cheia(&f)) { // 1 cheia, 0 nao cheia
        cout << "Fila cheia.\n";
    }

    TFila_Imprime(&f);
    cout << "Tamanho: " << f.tamanho << endl;

    return 0;
}

void TFila_Inicializa(TFila *f) {
    f->inicio = 0;
    f->fim = -1;
    f->tamanho = 0;
}

bool TFila_Vazia(TFila *f) {
    if (f->inicio > f->fim) {   // 0 é maior que -1 no começo
        return true; // 1
    } else {
        return false; // 0 fila não vazia 
    }
}

bool TFila_Cheia(TFila *f) {
    if (f->fim == MAXTAM-1) {
        return true; // fila cheia
    } else {
        return false; // 0 fila não cheia
    }
}

void TFila_Enfileira(TFila *f, int x) {
    if (TFila_Cheia(f)) {
        cout << "\nFila Cheia.\n";
    } else {
        f->fim++;
        f->Fila[f->fim] = x;
        f->tamanho++;
        cout << "Valor enfileirado: " << x << endl;
    }
}

int TFila_Desenfileira(TFila *f) {
    int aux;
    if (TFila_Vazia(f)) {
        cout << "Fila vazia.\n";
        
    } else {
        aux = f->Fila[f->inicio];
        f->inicio++;
        f->tamanho--;
        return aux;       
    }
}

void TFila_Imprime(TFila *f) {
    if (TFila_Vazia(f)) { 
        cout << "Fila vazia.\n";
    } else {
        cout << "Fila: ";
        for (int i = f->inicio; i <= f->fim; i++) {
            cout << f->Fila[i] << " ";
        }
        cout << endl;
    }
}
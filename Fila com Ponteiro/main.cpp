#include <iostream>
#include "fila.cpp"

using namespace std;

int main() {
    TipoFila f;
    TipoItem i;
    
    InicializaFila(&f);
    
    if (VerificaFilaVazia(&f)) {
        cout << "Fila vazia.\n\n";
    }
    
    i.valor = 5;
    Enfileira(&f, i);
    
    i.valor = 6;
    Enfileira(&f, i);
    
    i.valor = 8;
    Enfileira(&f, i);
    
    ImprimeFila(&f);
    cout << "Tamanho: " << f.tamanho;
    
    Desenfileira(&f);
    ImprimeFila(&f);
    cout << "Tamanho: " << f.tamanho;
    
    EsvaziaFila(&f);
    
    for (int n=1; n<=5; n++) {
        i.valor = n;
        Enfileira(&f, i);
    }
    
    ImprimeFila(&f);
    cout << "Tamanho: " << f.tamanho;

    return 0;
}

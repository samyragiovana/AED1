#include <iostream>
#include "Pilha.cpp"

using namespace std;

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
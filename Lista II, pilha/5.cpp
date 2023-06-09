#include <iostream>
#include <windows.h>
#include <stack>
using namespace std;

/*5- Implemente uma função chamada TPilha, que receba um vetor de inteiros com 15 elementos.
Para cada um deles, faça o que se pede:
• se o número for par, insira-o na pilha;
• se o número lido for ímpar, retire um número da pilha;
• Ao final, esvazie a pilha imprimindo os elementos. */
 
#define MAXTAM 15

int main() {
      UINT CPAGE_UTF8 = 65001;
      UINT CPAGE_DEFAULT = GetConsoleOutputCP();
      SetConsoleOutputCP(CPAGE_UTF8);
    
      stack <int> pilha;
      int v[] = {10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25};

        cout << "Pilha de Pares:\n";
        for (int i=0;i<MAXTAM; i++){
            if((v[i]%2) == 0){
                pilha.push(v[i]);
            }
        }
        
        while (!pilha.empty()){
            cout << pilha.top() << endl;
            pilha.pop();
        }
      
      system("pause");
      return 0;
}
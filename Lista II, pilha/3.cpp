#include <iostream>
#include <windows.h>
#include <stack>
using namespace std;

/*3- Escreva uma função que preencha uma pilha passada como parâmetro com os elementos de um
vetor passado como parâmetro*/

#define MAXTAM 5

int main() {
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);
    
    stack <int> pilha;

    int vetor[] = {5,10,15,20,25};

    for (int i=0;i<MAXTAM;i++){
        pilha.push(vetor[i]);  
    }
  
    while(!pilha.empty()){
    cout << pilha.top() << "\n";
    pilha.pop(); 
    }

  system("pause");
  return 0;
}

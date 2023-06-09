#include <iostream>
#include <windows.h>
#include <stack>
using namespace std;

/*6- Escreva uma função chamada TPilha2 que receba como parâmetro 2 pilhas (P e N) e um 
vetor de inteiros. Para cada inteiro, verifique:
• se positivo, insira na pilha P;
• se negativo, insira na pilha N;
Mostre as duas pilhas. */

#define MAXTAM 12
 
void TPilha2 (stack <int> pilhaP, stack <int> pilhaN);

int main() {
      UINT CPAGE_UTF8 = 65001;
      UINT CPAGE_DEFAULT = GetConsoleOutputCP();
      SetConsoleOutputCP(CPAGE_UTF8);
      system("cls");

      stack <int> pilhaP;
      stack <int> pilhaN;
      
      TPilha2(pilhaP,pilhaN);

      system("pause");
      return 0;
}

void TPilha2 (stack <int> pilhaP, stack <int> pilhaN){
    int v[]={1,2,3,4,5,6,-1,-2,-3,-4,-5,-6};

    for (int i = 0; i < MAXTAM; i++){
        if(v[i] > 0){
            pilhaP.push(v[i]);
        }else{
            pilhaN.push(v[i]);
        }
   }
   

    cout << "Pilha de Numeros Positivos: \n";
      while (!pilhaP.empty()){
          cout << pilhaP.top() << endl;
          pilhaP.pop();
      }

      cout << endl << endl;

      cout << "Pilha de Numeros Negativos: \n";
      while (!pilhaN.empty()){
          cout << pilhaN.top() << endl;
          pilhaN.pop();
      }
}
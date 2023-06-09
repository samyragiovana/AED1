#include <iostream>
#include <windows.h>
 
using namespace std;

int aloca(int tam, int* &ptr);
 
int main() {
  UINT CPAGE_UTF8 = 65001;
  UINT CPAGE_DEFAULT = GetConsoleOutputCP();
  SetConsoleOutputCP(CPAGE_UTF8);

  int tam;
  int *ptr;
  bool ret;

  cout << "Digite o tamanho do vetor: ";
  cin >> tam;

  ret = aloca(tam,ptr);

  if (ret == 1){
    cout << "Vetor alocado com sucesso\n";
  } else{
    cout << "Nao foi possivel alocar o vetor\n";
  }
 
  cout << endl << endl;
  system("pause");
  return 0;
}

int aloca(int tam, int* &ptr){
  ptr = new int[tam];

  for(int i=0;i<tam;i++){
    cout << &ptr[i] << "\n";
    if(ptr == NULL){
      cout << "Memoria insuficiente.\n";
      return 0;
    }
  }
}
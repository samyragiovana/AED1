#include <iostream>
#include <windows.h>
 
using namespace std;

void preenchevetor(int* vet, int i, int tam,int n);
void imprimevetor(int* vet,int i,int tam);
 
int main() {
  UINT CPAGE_UTF8 = 65001;
  UINT CPAGE_DEFAULT = GetConsoleOutputCP();
  SetConsoleOutputCP(CPAGE_UTF8);

  int *ptr;
  int v[10];
  ptr = &v[0];
 
  preenchevetor(ptr,0,10,1);

  cout << "Vetor: ";
 
  imprimevetor(ptr,0,10);
  
  cout << endl << endl;
  system("pause");
  return 0;
}

void preenchevetor(int* vet, int i, int tam,int n){
    for(i=0;i<tam;i++){
        *(vet + i) = n++;
    }
    cout << endl;
}

void imprimevetor(int* vet,int i,int tam){
    for(i=0;i<tam;i++){
        cout << *(vet + i) << " ";
    }
    cout << endl;
}
#include <iostream>
#include <windows.h>
 
using namespace std;
 
int main() {
  UINT CPAGE_UTF8 = 65001;
  UINT CPAGE_DEFAULT = GetConsoleOutputCP();
  SetConsoleOutputCP(CPAGE_UTF8);
 
 int tamanho;
 cin >> tamanho;
 int *vetor;
 vetor = new int [tamanho];

 for (int i=0;i<tamanho;i++){
     cout << i << " ";
 }

 
  cout << endl << endl;
  system("pause");
  return 0;
}
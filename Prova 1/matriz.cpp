#include <iostream>
#include <windows.h>
 
using namespace std;
 
int main() {
  UINT CPAGE_UTF8 = 65001;
  UINT CPAGE_DEFAULT = GetConsoleOutputCP();
  SetConsoleOutputCP(CPAGE_UTF8);
  
  system("cls");

  int t, i, M[3][4];

  for(t = 0; t < 3; t++)
      for(i = 0; i < 4; i++)
          M[t][i] = (t*4) + i + 1;
      
  

  for(t = 0; t < 3; t++){
      for(i = 0; i < 4; ++i){
          cout << "\t" << M[t][i];
      }
      cout << "\n";
  }
  
  system("pause");
  return 0;
}
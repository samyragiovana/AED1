#include <iostream>
#include <windows.h>
#include <queue>
 
using namespace std;
 

int main() {
  UINT CPAGE_UTF8 = 65001;
  UINT CPAGE_DEFAULT = GetConsoleOutputCP();
  SetConsoleOutputCP(CPAGE_UTF8);

  queue<int>a;
  a.push(10);
  a.push(20);
  a.push(30);
  a.push(40);
  a.push(50);


  cout << "Primeiro elemento " << a.front() << endl;
  cout << "ultimo elemento " << a.back() << endl;
  cout << "tamanho " << a.size() << endl;
 

  while(!a.empty()){
    cout << a.front() << " ";
    a.pop();
  }


   if(!a.empty()){
    cout << "fila vazia" << endl;
  } else{
    cout << "tamanho" << a.size() << endl;
  }


  return 0;
}

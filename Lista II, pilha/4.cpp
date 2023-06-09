#include <iostream>
#include <windows.h>
#include <stack>
using namespace std;

/*4- Dada uma sequência contendo N números reais em uma pilha, escreva uma função que 
imprima a ordem reversa dessa pilha.*/

#define MAXTAM 5

void Pilha(stack<int>Pilha);
void PilhaReversa(stack<int>PilhaReversa);

int main(){
	UINT CPAGE_UTF8 = 65001;
	UINT CPAGE_DEFAULT = GetConsoleOutputCP();
	SetConsoleOutputCP(CPAGE_UTF8);
	system("cls");

	stack<int> pilha;
	int n=0;

    cout << "Digite os numeros da pilha:" << endl;
	for (int i = 0; i<MAXTAM; i++){
		cin >> n;
		pilha.push(n);
	}
	system("cls");

	Pilha(pilha);
	PilhaReversa(pilha);

	system("pause");
	return 0;
}

void Pilha(stack<int> Pilha){
	cout << "Pilha Digitada:" << endl;
	while (!Pilha.empty()){
		cout << Pilha.top() << "\n";
		Pilha.pop();
	}
}

void PilhaReversa(stack<int> PilhaReversa){
	stack<int> auxiliar;

	cout << "\n\n";
	cout << "Pilha Reversa: " << endl;
	while (!PilhaReversa.empty()){
		auxiliar.push(PilhaReversa.top());
		PilhaReversa.pop();
	}

	while (!auxiliar.empty()){
		cout << auxiliar.top() << "\n";
		auxiliar.pop();
	}
	cout << "\n\n";
}
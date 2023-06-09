#include <iostream>
#include <windows.h>

using namespace std;

struct DISCENTE
{
    char nome[15];
    char matricula[15];
    float nota;
};

int main()
{
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);

    DISCENTE aluno;
    cout << "Nome: ";
    cin >> aluno.nome;

    cout << "Matricula: ";
    cin >> aluno.matricula;

    cout << "Nota: ";
    cin >> aluno.nota;

    system("cls");

    cout << "Dados do aluno \n\n";
    cout << "Nome: " << aluno.nome;
    cout << "\nMatricula: " << aluno.matricula;
    cout << "\nNota: " << aluno.nota;

    cout << endl
         << endl;
    system("pause");
    return 0;
}
#include <iostream>
#include <windows.h>

using namespace std;

void recebeNumero();
void inverteNumero(int);

int main()
{
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);

    recebeNumero();

    cout << endl
         << endl;
    system("pause");
    return 0;
}

void recebeNumero()
{
    int numero;
    cout << "Digite um número:";
    cin >> numero;
    inverteNumero(numero);
}

void inverteNumero(int numero)
{
    int i = 0;
    while (numero > 0)
    {                         // 1235 // 123 // 12 // 1 // 0
        i *= 10;              // i = 0 // 50 // 530 // 5320
        i += numero % 10;     // i = 5 // 50 + 3 // 53 // 530 + 2 // 532 // 5320 + 1 // 5321
        numero = numero / 10; // 123 // 12 // 1 // 0
    }

    cout << "O número invertido é:" << i;
}
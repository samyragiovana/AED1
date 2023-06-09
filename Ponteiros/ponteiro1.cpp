#include <iostream>
#include <windows.h>

using namespace std;

/*1 Crie um programa que contenha um array de float contendo 10 elementos. 
Imprima o endereço de cada posição desse array.*/

int main()
{
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);

    float a[10];

    for (int i = 0; i < 10; i++)
    {
        cout << &a[i] << " ";
    }

    cout << endl << endl;
    system("pause");
    return 0;
}
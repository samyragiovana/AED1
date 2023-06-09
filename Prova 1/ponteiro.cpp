#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);

    int a, b, *p1, *p2;
    a = 4;
    b = 3;
    p1 = &a;
    p2 = p1;
    *p2 = *p1 + 3;
    b = b * (*p1);
    (*p2)++;
    p1 = &b;

    cout << "\n\n *p1: " << *p1 << " *p2: " << *p2;
    cout << "\n a: " << a << " b: " << b;

    cout << endl << endl;
    system("pause");
    return 0;
}
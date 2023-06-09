#include <iostream>
#include <windows.h>
using namespace std;

/*3- Para um dado número inteiro n > 1, o menor inteiro d > 1 que divide n é chamado de fator primo.
E possível determinar a fatoração prima de n achando-se o fator primo de substituindo n pelo
quociente n / d, repetindo essa operação até que n seja igual a 1. Utilizando um dos TADs vistos
em sala (Lista, Pilha ou Fila) para auxiliá-lo na manipulação de dados, implemente uma função
que compute a fatoração prima de um número imprimindo os seus fatores em ordem crescente.
Por exemplo, para n = 3960, deverá ser impresso: 2 * 2 * 2 * 3 * 3 * 5 * 11. Justifique a escolha
do TAD utilizado*/

typedef struct lista
{
    int Fator;
    int Interacao;
    struct lista *Prox;
} lista;

void InserirLista(lista **f, int x, int y);
void Resultado(lista *f);

int main()
{
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);
    system("cls");

    int n, p, q, NPrimo, Div;
    lista *f = NULL;

    cout << "Qual número deseja fatorar? ";
    cin >> n;
    p = 2;

    while (n > 1)
    {
        q = 0;
        while (n % p == 0)
        {
            q++;
            n = n / p;
        }

        if (q > 0)
            InserirLista(&f, p, q);

        NPrimo = 0;
        while (!NPrimo)
        {
            p++;
            Div = 2;
            NPrimo = 1;

            while ((Div <= (p / 2)) && NPrimo)
            {
                if (p % Div == 0)
                    NPrimo = 0;
                else
                    Div = Div + 1;
            }
        }
    }

    Resultado(f);
    return 0;
}

void InserirLista(lista **f, int x, int y)
{
    lista *Aux = new lista;

    Aux->Fator = x;
    Aux->Interacao = y;
    Aux->Prox = NULL;

    while (*f != NULL)
        f = &(*f)->Prox;

    *f = Aux;
}

void Resultado(lista *f)
{
    lista *p = f;

    while (p != NULL)
    {
        cout << "\nNúmero " << p->Fator << " é multiplicado: " << p->Interacao << " vez(es)"
             << "\n";
        p = p->Prox;
    }
}

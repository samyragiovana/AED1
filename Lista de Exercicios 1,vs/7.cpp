#include <iostream>
#include <string.h>
#include <time.h>
#include <windows.h>

using namespace std;

/*7 Baseado em um “baralho tradicional” (cada carta tem seu naipe e seu valor), através de struct e
funções implemente a parte de distribuição (sorteio) de cartas para 2 jogadores de truco, 
considerando que cada jogador irá receber 3 cartas. Exiba na tela as cartas que cada um dos jogadores
recebeu.*/

struct partida //estrutura com variáveis
{
    string naipe_sorteado[6]; // Paus Espadas e Ouros , Copas Espadas e Paus
    int cartas[6];            // Excluindo 8, 9 e 10: Temos 10 cartas! 0-9 { 4, 5, 6, 7, Q, J, K, As, 2, 3 }
};                            // 4 Espadas, As ouros, 3 Copas - Espadilha, ZAP, 6 ouros

void sorteia();        //escopo da função para sortear as cartas
void imprime(partida); //escopo da função para imprimir o resultado
string naipe(int);
string carta(string, int);

int main()
{
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);
    sorteia(); //chamando a função sorteia   //junção de todas as funções em uma só
    return 0;
}

void sorteia()
{
    partida p;
    int i = 0, num_naipe, num_carta;

    while (i < 6)
    { // 0, 1, 2, 3, 4, 5
        bool repetido = false;
        // Sorteia o naipe
        srand(time(NULL));
        num_naipe = rand() % 4;
        p.naipe_sorteado[i] = naipe(num_naipe);

        // Sorteia a carta
        srand(time(NULL));
        num_carta = rand() % 10;
        p.cartas[i] = num_carta;

        // Verifica repetição
        for (int j = 0; j < i; j++)
        {
            if (p.naipe_sorteado[i] == p.naipe_sorteado[j] && p.cartas[i] == p.cartas[j])
            {
                repetido = true;
            }
        }

        if (!repetido)
        {
            i++;
        }
    }
    // Imprimir mãos
    imprime(p);
}

string naipe(int num_naipe)
{
    string nome;
    switch (num_naipe)
    {
    case 0:
        nome = "Ouros";
        break;
    case 1:
        nome = "Copas";
        break;
    case 2:
        nome = "Paus";
        break;
    case 3:
        nome = "Espadas";
        break;
    }
    return nome;
}

string carta(string naipe, int n)
{
    string carta;
    // rand: { 0, 1, 2, 3, 4, 5, 6, 7,  8, 9 }
    //       { 4, 5, 6, 7, Q, J, K, As, 2, 3 }
    switch (n)
    {
    case 0:
        if (naipe.compare("Paus") == 0)
        {
            carta = "ZAP";
        }
        else
        {
            carta = "4 de " + naipe;
        }
        break;
    case 1:
        carta = "5 de " + naipe;
        break;
    case 2:
        carta = "6 de " + naipe;
        break;
    case 3:
        carta = "7 de " + naipe;
        break;
    case 4:
        carta = "Dama de " + naipe;
        break;
    case 5:
        carta = "Valete de " + naipe;
        break;
    case 6:
        carta = "Rei de " + naipe;
        break;
    case 7:
        if (naipe.compare("Espadas") == 0)
        {
            carta = "Espadilha";
        }
        else
        {
            carta = "Ás de " + naipe;
        }
        break;
    case 8:
        carta = "2 de " + naipe;
        break;
    case 9:
        carta = "3 de " + naipe;
        break;
    }
    return carta;
}

void imprime(partida p)
{
    system("cls");
    string nome;

    cout << "Jogador 1: " << endl
         << endl;
    for (int i = 0; i < 3; i++)
    {
        nome = carta(p.naipe_sorteado[i], p.cartas[i]);
        cout << nome << endl;
    }

    cout << "\n\nJogador 2: " << endl
         << endl;
    for (int i = 3; i < 6; i++)
    {
        nome = carta(p.naipe_sorteado[i], p.cartas[i]);
        cout << nome << endl;
    }
}
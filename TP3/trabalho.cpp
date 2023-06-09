#include <iostream>
#include <windows.h>
#include <time.h>
using namespace std;

/*1.Novo aluno na fila: Deve acionar funções para inserir aleatoriamente um aluno (pré-definido ou
não) em uma Fila. Um aluno deverá ter pelo menos RA e Nome.

2.Atende aluno da fila: Aciona a função para desenfileirar. O primeiro da fila será atendido e não fará parte da
mesma.

3.Exibe fila: Imprima nesta opção toda a fila com a respectiva posição de cada aluno e seu RA.*/
/* Registro para representar os valores de cada elemento */

#define MAXTAM 50

typedef struct
{
    int RA;
    char nome[30];
} Aluno;

typedef struct
{
    Aluno Fila[MAXTAM];
    int inicio, fim;
    int quantidade;
} TFila;

void TFila_Inicializa(TFila *f);
bool TFila_Vazia(TFila *f);
bool TFila_Cheia(TFila *f);
void TFila_Enfileira(TFila *f, Aluno x);
Aluno TFila_Desenfileira(TFila *f);
void TFila_Imprime(TFila *f);
void Menu();

int main()
{
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);
    system("cls"); // limpa tela

    TFila Fila; // nome dado a TFila
    Aluno f;    // nome dado a struct Aluno

    TFila_Inicializa(&Fila); // inicia fila

    int op; // ler opcao

    do
    {
        system("cls");
        Menu();    // mostra menu
        cin >> op; // ler opcão

        system("cls"); // limpa tela

        srand(time(NULL));
        int id = 3569 + (rand() % 100); // sorteia os RA

        switch (op)
        {
        case 1:
            cout << "Digite o nome do Aluno: "; // nome do aluno que irá entrar na fila
            cin.ignore();
            gets(f.nome);
            f.RA = id; // colocndo um RA para este aluno

            TFila_Enfileira(&Fila, f); // coloca aluno na fila

            system("cls"); // limpa tela
            cout << f.nome << " entrou na fila!\n\n"; // aluno na fila
            system("pause");                          // pausa para leitura
            break;
        case 2:
            TFila_Desenfileira(&Fila);
            cout << "Aluno atendido!\n\n";
            system("pause"); // pausa para leitura
            break;
        case 3:
            TFila_Imprime(&Fila);
            system("pause"); // pausa para leitura
            break;
        case 4:
            return 0;
        }
    } while (op != 4);

    return 0;
}

void Menu()
{
    cout << "************************" << endl;
    cout << "   MENU PRINCIPAL     *\n";
    cout << "   1 - Novo aluno     *\n";
    cout << "   2 - Atende aluno   *\n";
    cout << "   3 - Exibe fila     *\n";
    cout << "   4 - Sair           *\n";
    cout << "************************" << endl
         << endl;
    cout << "Escolha a opção:";
}

void TFila_Inicializa(TFila *f)
{
    f->inicio = 0;
    f->fim = -1;
    f->quantidade = 0;
}

bool TFila_Vazia(TFila *f)
{
    if (f->inicio > f->fim)
    {
        return true; // 1
    }
    else
    {
        return false; // 0 fila não vazia
    }
}

bool TFila_Cheia(TFila *f)
{
    if (f->fim == MAXTAM - 1)
    {
        return true; // fila cheia
    }
    else
    {
        return false; // 0 fila não cheia
    }
}

void TFila_Enfileira(TFila *f, Aluno x)
{
    if (TFila_Cheia(f))
    {
        cout << "\nFila Cheia.\n"; // não cabe mais alunos, fila está cheia
    }
    else
    {
        f->fim++;
        f->Fila[f->fim] = x; // recebe aluno
        f->quantidade++;     // adiciona aluno a fila
    }
}

Aluno TFila_Desenfileira(TFila *f)
{
    system("cls"); // limpa tela
    Aluno aux;
    if (TFila_Vazia(f))
    {
        cout << "Fila vazia.\n"; // não há mais alunos na fila para atender
    }
    else
    {
        aux = f->Fila[f->inicio];
        f->inicio++;
        f->quantidade--; // retira o primeiro aluno da fila
        return aux;
    }
}

void TFila_Imprime(TFila *f)
{
    system("cls"); // limpa tela
    if (TFila_Vazia(f))
    {
        cout << "Fila vazia.\n"; // fala que a fila está vazia
    }
    else
    {
        for (int i = f->inicio; i <= f->fim; i++)
        {
            cout << "NOME: " << f->Fila[i].nome << "\n"; // mostra os nomes dos alunos na fila
            cout << "RA: " << f->Fila[i].RA << "\n";     // mostra os Ra dos alunos

            cout << endl;
        }
        cout << "\n\n";
    }
}

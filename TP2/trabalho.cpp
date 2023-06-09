#include <iostream>
#include <windows.h>
using namespace std;

/*1.) Inclusão de um novo pedido: Neste caso, deve-se entrar com o(s) código(s) dos produtos referentes
ao pedido. Implemente uma forma para que o código do pedido seja gerado automaticamente. Na
estrutura do pedido, crie uma variável do tipo float chamada distancia. Preencha um valor qualquer
no momento de registro do pedido, correspondendo à distância entre o cliente e a lanchonete.

2.) Listar Pedidos: Liste todos os pedidos gerados com seus respectivos produtos e preço final.

3.) Ver Cardápio: Imprima nesta opção todos os produtos da lanchonete disponíveis para serem incluídos no pedido
(não é necessário cadastro de novos produtos no sistema). Estes produtos podem ser pré-definidos em uma matriz ou
 vetor, já estando disponíveis para consulta no início do programa.

4.) Consultar Pedido: Mostra os dados de um pedido através da busca pelo seu código.

5.) Imprimir Lista de Entrega: Considere uma Estrutura de Dados Pilha para a criação da Lista de
Entrega. Organize a TPilha Mochila para que os pedidos sejam inseridos por ordem decrescente da
distancia do pedido, ou seja, no topo ficarão os pedidos mais próximos da lanchonete. Mostre a
Lista de Entrega.

6.) Lançar Entrega: Remova do topo da Mochila o pedido entregue.
*/

#define MAXTAM 50 // quantidade de pedidos
#define MAX_ENTREGA 11

typedef struct
{
    int codigo;
    float ValorTotal = 0.00;
} Pedido;

typedef struct
{
    Pedido Pilha[MAX_ENTREGA];
    int Topo;
} TPilha;

void TPilha_Inicializa(TPilha *p);        // inicia a pilha
int TPilha_Vazia(TPilha *p);              // pilha vazia
int TPilha_Cheia(TPilha *p);              // pilha cheia
void TPilha_Empilha(TPilha *p, Pedido x); // empilha elementos
int TPilha_Desempilha(TPilha *p);         // desempilha elementos
void TPilha_Imprime(TPilha *p);           // imprime a pilha
int TPilha_Tamanho(TPilha *p);            // tamanho da pilha
void Menu();                              // menu que será mostrado ao usuário
void Cardapio();                          // opções do cardápio

int main()
{
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);

    TPilha p;  // nome da variável tpilha
    Pedido x;  // nome da struct pedido
    int op, n; // variáveis

    TPilha_Inicializa(&p); // inicando a pilha

    do // faça enquanto opção for diferente de 4
    {
        system("cls");                            // limpa tela
        Menu();                                   // mostra menu
        cout << "\n\nDigite sua opção: " << endl; // pede para usuário digitar a opção que deseja ver
        cin >> op;                                // ler a opção do usuário

        system("cls"); // limpa tela

        switch (op) // escolha do cliente
        {
        case 1:
            Cardapio();     // mostra cardápio
            int quant, cod; // variáveis
            cout << "\n\nDigite o código do produto que você quer: ";
            cin >> cod;
            cout << "\nDigite a quantidade que você quer: ";
            cin >> quant;
            while (quant <= 0) // se o usuário digitar uma opção menor que zero
            {
                cin >> quant;
                cout << "\n";
            }

            if (cod == 1) // opções que o usuário deve escolher
            {
                cout << "Refrigerante";
                x.codigo = 1;
                x.ValorTotal += 3 * quant;
                TPilha_Empilha(&p, x);
            }
            else if (cod == 2)
            {
                cout << "Hamburguer";
                x.codigo = 2;
                x.ValorTotal += 10 * quant;
                TPilha_Empilha(&p, x);
            }

            else if (cod == 3)
            {
                cout << "Coxinha";
                x.codigo = 3;
                x.ValorTotal += 4 * quant;
                TPilha_Empilha(&p, x);
            }

            else
            {
                cout << "Empada";
                x.codigo = 4;
                x.ValorTotal += 3.50 * quant;
                TPilha_Empilha(&p, x);
            }
            break;
        case 2:
            TPilha_Imprime(&p); // imprime pedidos
            system("pause");    // pausa para leitura
            break;

        case 3:
            Cardapio();      // mostra somente o cardápio
            system("pause"); // pausa para leitura
            break;

        case 4:
            return 0; // sair do programa
            break;
        }
    } while (op != 4);
    return 0;
}

void TPilha_Inicializa(TPilha *p) // inicia a pilha
{
    p->Topo = 0;
}

int TPilha_Vazia(TPilha *p)
{
    if (p->Topo == 0)
    {
        return true; // avisa se a pilha está vazia
    }
    else
        return false;
}

int TPilha_Cheia(TPilha *p)
{
    if (p->Topo == MAXTAM)
    {
        cout << "Pilha cheia!"; // caso a pilha esteja cheia (50 pedidos)
    }
}

void TPilha_Empilha(TPilha *p, Pedido x)
{
    if (TPilha_Cheia(p) == 1)
    {
        cout << "\nPilha cheia\n"; // caso a pilha estija cheia, não empilhará mais
    }
    else
    {
        p->Topo++;
        p->Pilha[p->Topo] = x; // empilha produtos
    }
}

int TPilha_Desempilha(TPilha *p)
{
    int aux; // Receber o valor da pilha que será desempilhado
    if (TPilha_Vazia(p) == 1)
    {
        cout << "\nImpossível desempilhar. Pilha vazia\n"; // se a pilha estiver vazia, não há como desempilhar
    }
    else
    {
        p->Topo--; // desempilha produtos
        return aux;
    }
}

void TPilha_Imprime(TPilha *p)
{
    if (TPilha_Vazia(p) == 1)
    {
        cout << "\nPilha vazia\n"; // caso a pilha esteja vazia
        return;
    }
    for (int i = p->Topo; i >= 0; i--)
    {
        cout << "\nCódigo do produto: " << p->Pilha[i].codigo;         // mostra o código do produto pedido
        cout << "\nValor total: " << p->Pilha[i].ValorTotal << "\n\n"; // mostra o total em valor do produto pedido
    }
}

int TPilha_Tamanho(TPilha *p)
{
    return p->Topo + 1; // tamanho da pilha
}

void Menu() // menu para a escolha do usuário
{
    cout << " +++++++++++++++++++++++++++\n";
    cout << " |                         |\n";
    cout << " |      MENU PRINCIPAL     |\n";
    cout << " |                         |\n";
    cout << " | [1] Fazer Pedido        |\n";
    cout << " | [2] Listar Pedidos      |\n";
    cout << " | [3] Ver Cardápio        |\n";
    cout << " | [4] Sair                |\n";
    cout << " |                         |\n";
    cout << "  ++++++++++++++++++++++++++\n";
}

void Cardapio() // produtos do cardápio
{
    cout << "\n\n\t\tProdutos disponíveis \n\n";

    cout << "Produtos\tCódigo do produto\t\t Preços\n";
    cout << "Refrigerante\t\t 1 \t\t\t R$ 3,00" << endl;
    cout << "Hambúrguer.\t\t 2 \t\t\t R$ 10,00" << endl;
    cout << "Coxinha......\t\t 3 \t\t\t R$ 4,00" << endl;
    cout << "Empada......\t\t 4 \t\t\t R$ 3,50" << endl;
}

#include <iostream>
#include <windows.h>
#include <conio.h>
#include <time.h>
using namespace std;

# define MAXTAM 10
# define MAX_ENTREGA 7

typedef struct {
    int codigo = 0;
    int produtos [MAXTAM];
    float valor_pedido = 0.00;
    float distancia;
} Pedido;

typedef struct {
    Pedido Pilha[MAX_ENTREGA];
    int Topo;
} TPilha;

void TPilha_Inicializa (TPilha *p);
int TPilha_Vazia (TPilha *p);
int TPilha_Cheia (TPilha *p);
void TPilha_Empilha (TPilha *p, Pedido x);
int TPilha_Desempilha (TPilha *p, Pedido x);
void TPilha_Imprime (TPilha *p);
int TPilha_Tamanho (TPilha *p);
void Menu(Pedido *pi, TPilha *pilha);
void cardapio();
void listagem(Pedido *pi, TPilha *p);
void finalizaPedido();
void consulta(Pedido *p,TPilha *pi);

int main() {
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);

    system("cls"); // limpa tela

    TPilha pilha; // struct Tpilha sendo definido como pilha
    Pedido pi; // struct Tpedido sendo definido como pi
    TPilha_Inicializa(&pilha);
    
    Menu(&pi, &pilha);
    
    return 0;
}

int id = 0;
TPilha mochila;

void TPilha_Inicializa(TPilha *p)
{ // pilha sendo inicializada
    p->Topo = 0;
}

int TPilha_Vazia(TPilha *p)
{ // verificando se a pilha esta vazia
    if (p->Topo == 0)
    {
        return 1;
    }
    else
        return 0;
}

int TPilha_Cheia(TPilha *p)
{ // verificando se a pilha esta cheia
    if (p->Topo == MAXTAM)
    {
        cout << "PILHA CHEIA !!!";
        return 1;
        system("pause");
    }
    return 0;
}

void TPilha_Empilha(TPilha *p, Pedido x)
{ // empilhando na pilha
    if (TPilha_Cheia(p) == 1)
    {
        cout << "\nPILHA CHEIA !!!\n";
    }
    else
    {
        p->Topo++;
        p->Pilha[p->Topo] = x;
    }
}

int TPilha_Desempilha(TPilha *p)
{
    int aux; // recebendo o valor da pilha desempilhado
    if (TPilha_Vazia(p) == 1)
    {
        cout << "\nIMPOSSIVEL DESEMPILHAR. PILHA VAZIA !!!\n";
    }
    else
    {
        aux = p->Topo;
        p->Topo--;
        cout << "PEDIDO ENTREGUE.\n\n";
        return aux;
    }
    return -1;
}

void TPilha_Imprime(TPilha *p)
{ // imprimindo a pilha caso nn tiver vazia
    if (TPilha_Vazia(p) == 1)
    {
        cout << "\nPILHA VAZIA !!!\n";
        return;
    }
    for (int i = p->Topo; i > 0; i--)
    {
        cout << "\nCODIGO: " << p->Pilha[i].codigo << "\n";
        cout << "QUANTIDADE: " << p->Pilha[i].valor_pedido << "\n";
        cout << "DISTANCIA: " << p->Pilha[i].distancia << "\n";
    }
}

int TPilha_Tamanho(TPilha *p)
{ // tamanho da pilha
    return p->Topo + 1;
}

void cardapio()
{ // funcao cardapio
    cout << "****************************************************************\n";
    cout << "*        LISTAGEM DE PRODUTOS DISPONIVEL NA LACHONETE          *\n";
    cout << "****************************************************************\n\n";
    cout << "PRODUTOS\tCODIGO DO PRODUTO\tPREÇOS\n";
    cout << "SUCO.......\t"
         << "1"
         << "\t\t\tR$ 3,00" << endl;
    cout << "HAMBURGUER.\t"
         << "2"
         << "\t\t\tR$ 7,00" << endl;
    cout << "PIZZA......\t"
         << "3"
         << "\t\t\tR$ 10,00" << endl;
    cout << "MISTO......\t"
         << "4"
         << "\t\t\tR$ 5,00" << endl
         << endl;
}

void listagem(TPilha *p)
{ // funcao listagem da pilha
    cout << "****************************************************************\n";
    cout << "*                  PEDIDO Nº " << id << "                      *\n";
    cout << "****************************************************************\n\n";
    for (int i = p->Topo; i > 0; i--)
    {
        cout << "CODIGO DO PEDIDO: " << p->Pilha[i].codigo << "\n";
        cout << "VALOR TOTAL DO PEDIDO: R$ " << p->Pilha[i].valor_pedido << "\n";
    }
}
void consulta(Pedido *pi, TPilha *p)
{ // funcao consulta na pilha
    int cod;
    cout << "DIGITE O CODIGO DO PEDIDO QUE VOCE ESTA PROCURANDO: ";
    cin >> cod;
    for (int i = p->Topo; i > 0; i--)
    {
        if (cod == pi->codigo)
        {
            cout << "CODIGO DO PEDIDO: " << pi->codigo << "\n";
            cout << "VALOR TOTAL DO PEDIDO: R$ " << p->Pilha[i].valor_pedido << "\n";
        }
    }
    cout << "PEDIDO NÃO ENCONTRADO" << endl
         << endl;
}

void imprimir_entrega(TPilha *lista_pedidos)
{
    // A Estrutura correta a ser utilizada inicialmente parece ser uma Fila,  porem podemos fazer uma alteração no funcionamento dela para que comporte como um fila. Pq tem que ser retirado do inicio os pedidos para entrega

    if (!TPilha_Vazia(&mochila))
    {
        cout << "\nTODOS PEDIDOS AINDA NÃO FORAM ENTREGUES !!!\n";
        TPilha_Imprime(&mochila);
        return;
    }

    TPilha_Inicializa(&mochila);
    Pedido aux_mochila[MAX_ENTREGA], aux;
    int qtd_itens = 0;
    int ret;
    for (int i = 0; i < MAX_ENTREGA; i++)
    {
        ret = TPilha_Desempilha(lista_pedidos);
        if (ret == -1)
        { // Nao Desempilhou
            break;
        }
        aux_mochila[i + 1] = lista_pedidos->Pilha[ret];
        qtd_itens++;
    }
    for (int i = 1; i <= qtd_itens; i++)
    {
        for (int j = 1; j <= qtd_itens; j++)
        {
            if (aux_mochila[i].distancia >= aux_mochila[j].distancia)
            {
                aux = aux_mochila[i];
                aux_mochila[i] = aux_mochila[j];
                aux_mochila[j] = aux;
            }
        }
    }
    for (int i = 1; i <= qtd_itens; i++)
    {
        TPilha_Empilha(&mochila, aux_mochila[i]);
    }
    TPilha_Imprime(&mochila);
}

void lancar_entrega(TPilha *lista_pedidos)
{

    int ret = TPilha_Desempilha(&mochila);
    if (ret == -1)
    {
        cout << "\nACABARAM OS PEDIDOS DA MOCHILA !!!\n";
        return;
    }
    cout << "\nPEDIDO ENTREGUE !!!\n";
}

void Menu(Pedido *pi, TPilha *pilha)
{ // funcao menu
    Pedido p;
    int opcao;

    system("color 0B"); // colocando cor no menu
    cout << "  \n        ����������������������������������������������������������������";
    cout << "  \n        �                                                              �";
    cout << "  \n        �                         MENU PRINCIPAL                       �";
    cout << "  \n        �                                                              �";
    cout << "  \n        ����������������������������������������������������������������";
    cout << "  \n        �                                                              �";
    cout << "  \n        � 1 - FAZER PEDIDO                                             �";
    cout << "  \n        �                                                              �";
    cout << "  \n        � 2-  LISTAR PEDIDOS                                           �";
    cout << "  \n        �                                                              �";
    cout << "  \n        � 3 - VER CARDÁPIO                                             �";
    cout << "  \n        �                                                              �";
    cout << "  \n        � 4 - CONSULTAR PEDIDO                                         �";
    cout << "  \n        �                                                              �";
    cout << "  \n        � 5 - IMPRIMIR ENTREGA                                         �";
    cout << "  \n        �                                                              �";
    cout << "  \n        � 6 - LANÇAR ENTREGA                                           �";
    cout << "  \n        �                                                              �";
    cout << "  \n        � 7 - SAIR                                                     �";
    cout << "  \n        �                                                              �";
    cout << "  \n        ����������������������������������������������������������������\n\n";

    cout << "ESCOLHA UMA OPÇÃO: " << endl;
    cin >> opcao;

    system("cls");

    switch (opcao)
    {
    case 1:
        cardapio();
        int quantidade, codigo;
        cout << "DIGITE O CODIGO DO PRODUTO QUE VOCE DESEJA: ";
        cin >> codigo;
        cout << "DIGITE A QUANTIDADE QUE VOCE DESEJA: ";
        cin >> quantidade;
        while (quantidade <= 0)
        { // Exige pelo menos 1 unidade
            cout << "SUA QUANTIDADE PRECISA SER MAIOR QUE ZERO\n";
            cout << "QUANTIDADE: ";
            cin >> quantidade;
            cout << "\n";
        }
        if (codigo >= 1 && codigo <= 4)
        {
            srand(time(NULL));
            p.codigo = codigo;
            p.distancia = (rand()%10) + 1; 
        }

        switch (codigo)
        {
        case 1:
            cout << "\n******************************************************** \n";
            cout << "  * " << quantidade << " SUCO(S) ADICIONADO(S) À SACOLA    *\n";
            cout << "******************************************************* \n";
            cout << "\n";
            p.valor_pedido += 3 * quantidade;

            system("pause");
            TPilha_Empilha(pilha, p);
            system("cls");
            break;

        case 2:
            cout << "\n*********************************************************** \n";
            cout << "  * " << quantidade << " HAMBURGUER(S) ADICIONADO(S) À SACOLA * \n";
            cout << "*********************************************************** \n";
            cout << "\n";
            p.valor_pedido += 7 * quantidade;

            system("pause");
            TPilha_Empilha(pilha, p);
            system("cls");
            break;

        case 3:
            cout << "\n******************************************************* \n";
            cout << "  * " << quantidade << " PIZZA(S) ADICIONADO(S) À SACOLA  * \n";
            cout << "******************************************************* \n";
            cout << "\n";
            p.valor_pedido += 10 * quantidade;

            system("pause");
            TPilha_Empilha(pilha, p);
            system("cls");
            break;

        case 4:
            cout << "\n******************************************************* \n";
            cout << "  * " << quantidade << " MISTO(S) ADICIONADO(S) À SACOLA  * \n";
            cout << "******************************************************* \n";
            cout << "\n";
            p.valor_pedido += 5 * quantidade;

            system("pause");
            TPilha_Empilha(pilha, p);
            system("cls");
            break;

        default:
            cout << "\nERRO CÓDIGO DE PRODUTO, INEXISTENTE \n";
            cout << "\n";
            system("cls");
            break;
        }
        return Menu(pi, pilha);
        break;
    case 2:
        listagem(pilha);
        system("pause");
        system("cls");
        Menu(pi, pilha);
        break;
    case 3:
        cardapio();
        system("pause");
        system("cls");
        Menu(pi, pilha);
    case 4:
        consulta(pi, pilha);
        system("pause");
        system("cls");
        Menu(pi, pilha);

    case 5:
        imprimir_entrega(pilha);
        system("pause");
        Menu(pi, pilha);
    case 6:
        lancar_entrega(pilha);
        system("pause");
        Menu(pi, pilha);
    }
    cout << "FECHANDO PROGRAMA"; // for percorrendo um slepp para imprimir os pontinhos
    for (int i = 0; i <= 5; i++)
    {
        cout << ".";
        //Sleep(500);
    }
    cout << "\n\nPRESIONE ENTER PARA ENCERRAR TOTALMENTE !!!";
    getch(); // função getch para parar antes do return
}

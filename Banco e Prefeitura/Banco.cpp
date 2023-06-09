#include <iostream>
#include <windows.h>
 
using namespace std;

/*1 Utilize a estrutura BANCO criada anteriormente, e faça um
programa que crie 5 contas. Atribua valores diferentes para os
saldos dessas contas e depois mostre os dados das contas com
menor e maior saldo.*/

#define PESSOAS 5   //constante com o número de pessoas

//estrutura
struct BANCO {
    int numeros;
    char titular[35];
    float saldo;
    bool maior = false;
    bool menor = false;
};

//escopo das funções
void contasbanco(BANCO[]);
float maior(BANCO[]);
float menor(BANCO[]);
void atualizaValores(BANCO[], float, float);
void Resultado(BANCO[]);

int main() {
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);
    system("cls");  //limpa tela 

    BANCO contas[PESSOAS];  //chamando a struct
    float ma, me;   //declaração de variáveis

    contasbanco(contas);    //chamando função
    
    system("cls");    //limpa tela 

    ma = maior(contas); //chamando função
    me = menor(contas); //chamando função

    atualizaValores(contas, ma, me);    //chamando função

    system("cls");   //limpa tela 

    Resultado(contas);        //chamando função

    cout << endl << endl;
    system("pause");
    return 0;
}


//funções
void contasbanco(struct BANCO contas[PESSOAS]) {            //pede os dados
    for (int i=0; i<PESSOAS; i++) {
        cout << "Numero: ";
        cin >> contas[i].numeros;
        cout << "Titular: ";
        cin >> contas[i].titular;
        cout << "Saldo: ";
        cin >> contas[i].saldo;
    }
}

float maior(struct BANCO contas[PESSOAS]) {     //maior saldo
    float maior_saldo;
    for (int i=0; i<PESSOAS; i++) {
        if (i== 0) {
            maior_saldo = contas[i].saldo;
        }
        else if (contas[i].saldo > maior_saldo) {
            maior_saldo = contas[i].saldo;
        }
    }
    return maior_saldo;
}

float menor(struct BANCO contas[PESSOAS]) {     //menor saldo
    float menor_saldo;
    for (int i=0; i<PESSOAS; i++) {
        if (i== 0) {
            menor_saldo = contas[i].saldo;
        }
        else if (contas[i].saldo < menor_saldo) {
            menor_saldo = contas[i].saldo;
        }
    }
    return menor_saldo;
}

void atualizaValores(struct BANCO contas[PESSOAS], float maior_saldo, float menor_saldo) {  //atualiza os valores do saldo
    for (int i=0; i<PESSOAS; i++) {
        if (contas[i].saldo == menor_saldo) {
            contas[i].menor = true;
        }
        if (contas[i].saldo == maior_saldo) {
            contas[i].maior = true;
        }
        if (contas[i].saldo != menor_saldo) {
            contas[i].menor = false;
        }
        if (contas[i].saldo != maior_saldo) {
            contas[i].maior = false;
        }
    }
}

void Resultado(struct BANCO contas[PESSOAS]) {  //imprime o resultado para o usuário
    cout << "\nResultado da Analise \n\n";
    for (int i=0; i<PESSOAS; i++) {
        if (contas[i].menor == true) {
            cout << "\nConta(s) com o(s) menor(es) saldo(s) \n";
            cout << "\nNumero: " << contas[i].numeros;
            cout << "\nTitular: " << contas[i].titular;
            cout << "\nSaldo: " << contas[i].saldo;    
        }
        if (contas[i].maior == true) {
            cout << "\n\nConta(s) com o(s) maior(es) saldo(s) \n";
            cout << "\nNumero: " << contas[i].numeros;
            cout << "\nTitular: " << contas[i].titular;
            cout << "\nSaldo: " << contas[i].saldo;    
        }
    }
}
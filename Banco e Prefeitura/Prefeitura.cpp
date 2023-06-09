#include <iostream>
#include <windows.h>
 
using namespace std;

/*2. A prefeitura de uma cidade fez uma pesquisa entre seus habitantes, coletando dados sobre salário, idade e 
número de filhos. Faça um programa que leia esses dados de 20 pessoas (dica: utilize constante para testar com número menor).
Armazene em uma estrutura, calcule e mostre:
a) a média de salário da população;
b) a média do número de filhos;
c) o maior salário;
d) o percentual de mulheres com salário superior a R$ 1.000,00.*/
 
#define TOTALPESSOAS 20 // constante para o número de pessoas da pesquisa

struct PESSOA{ // estrutura pessoa
  float Salario;
  char Sexo;
  int idade;
  int nFilhos;
}; 

int NUM_Mulheres(PESSOA[]); // função numero de mulheres
float Retorna_Maior_Salario(PESSOA[]); // função retorna maior salario
float Mulheres_RecebemMais_1000(PESSOA[]); // função mulheres que recebem mais de 1000$
void Retorna_Pesquisa(PESSOA[]); // função retorna a pesquisa feita

PESSOA p[TOTALPESSOAS]; //chamando a struct e denominado-a

int main() {
  UINT CPAGE_UTF8 = 65001;
  UINT CPAGE_DEFAULT = GetConsoleOutputCP();
  SetConsoleOutputCP(CPAGE_UTF8);
  system("cls"); // limpa tela

  //declaração de variáveis
  int Total_Filhos = 0; 
  float Media_Salarios, Media_Filhos, Percentual_Mulheres, Total_Salarios = 0;
  
  //pedindo o usuário os dados
  for(int i = 0; i < TOTALPESSOAS; i++){
      cout << "Informe seu Sexo(M/F): ";  
       cin >> p[i].Sexo;
      NUM_Mulheres(p);

      cout << "Informe sua Idade: "; 
      cin >> p[i].idade;

      cout << "Informe o Número de Filhos: ";
      cin >> p[i].nFilhos;         
      Total_Filhos += p[i].nFilhos;

      cout << "Informe seu Salário: ";  
      cin >> p[i].Salario;
      Total_Salarios += p[i].Salario;

      Retorna_Maior_Salario(p); 
      Mulheres_RecebemMais_1000(p);
      
      cout << endl << endl;
  }
  system("cls"); // limpa tela

  //a)média de salário da população
  Media_Salarios = Total_Salarios/TOTALPESSOAS;
  cout << "Média de salários da População: " << Media_Salarios;
  
  //b)média do número de filhos
  Media_Filhos = Total_Filhos/TOTALPESSOAS;
  cout << "\n\nMédia do número de Filhos: " << Media_Filhos;
 
  //c)Retorna o maior salário
  cout << "\n\nMaior Salário Obtido: " << Retorna_Maior_Salario(p);
 
  //d)percentual de mulheres com salário superior a 1000$
  Percentual_Mulheres = (Mulheres_RecebemMais_1000(p)/NUM_Mulheres(p))*100;
  cout << "\n\nPercentual de Mulheres com Salário Superior á R$1000,00: " << Percentual_Mulheres << "%";
 
  cout << endl << endl;
  system("pause");
  return 0;
}

int NUM_Mulheres(struct PESSOA p[TOTALPESSOAS]){  // Função retornando o numero de mulheres
    int Total_Mulheres;
    for(int i = 0; i < TOTALPESSOAS; i++){
        if(p[i].Sexo == 'F' || 'f'){
           Total_Mulheres++;
       }
    }
    return Total_Mulheres;
}
float Retorna_Maior_Salario(struct PESSOA p[TOTALPESSOAS]){ // função para retornar o maior salario
    float Maior_Salario;
    for(int i = 0; i < TOTALPESSOAS; i++){
        if(p[i].Salario > Maior_Salario){
           Maior_Salario = p[i].Salario;
        }
    }
    return Maior_Salario;
}
float Mulheres_RecebemMais_1000(struct PESSOA p[TOTALPESSOAS]){ // função aonde mostra quantas mulheres recebem + de $1000
    int Mulheres_RecebemMais_1000;
    for(int i = 0; i < TOTALPESSOAS; i++){
        if(p[i].Sexo == 'F' || 'f' && p[i].Salario > 1000){
           Mulheres_RecebemMais_1000++;
        }
    }
    return Mulheres_RecebemMais_1000;
}

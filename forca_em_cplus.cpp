#include <iostream>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

bool letras_usadas(char letras[], int contador);
bool desenha_palavra(char palavra[], char palavra_chave[], char letra);
bool censura_palavra(char palavra_chave[]);
void seleciona_palavra(char banco[3][30], char palavra[], char palavra_chave[]);

int main()
{
    char sentinela = 'y';
    int erros = 0, acertos = 0;
    int contador = 0;
    char letras[26];
    char letra;
    char banco[3][30] = {"Banana", "Morango", "Cachorro"};
    char palavra[30];
    char palavra_chave[30];
    int num;

    seleciona_palavra(banco, palavra, palavra_chave);
    censura_palavra(palavra_chave);

    do
    {
        if (erros == 5)
        {
            cout << "\n \n \n \n \n";
            cout << "------------------------------------------------\n";
            cout << "-         Você Perdeu                         -\n ";
            cout << "------------------------------------------------\n\n";
            cout << "Deseja Tentar novamente ? Y/N : ";
            cin >> sentinela;
            if (sentinela == 'Y')
            {
                erros = 0;
                acertos = 0;
            }
        }
        else
        {
            system("cls");
        }
        cout << "------------------------------------------------\n";
        cout << "-         Bem Vindo a Forca !                  -\n ";
        cout << "------------------------------------------------\n\n";

        cout << "\t--------------\n";
        cout << "\t|           |\n";
        cout << "\t|           |\n";
        if (erros >= 1)
        {
            cout << "\t|           0\n";
        }
        else
        {
            cout << "\t|             \n";
        }
        if (erros == 2)
        {
            cout << "\t|           |\n";
        }
        else if (erros == 3)
        {
            cout << "\t|          /| \n";
        }
        else if (erros == 4)
        {
            cout << "\t|          /|\\ \n";
        }
        if (erros >= 5)
        {
            cout << "\t|           /\\ \n";
        }
        else
        {
            cout << "\t|             \n";
        }
        cout << "\t|            \n";
        cout << "\t|            \n";
        cout << "\t|            \n";
        cout << "\t|            \n";
        cout << "\t|            \n";
        cout << "\t|            \n";
        cout << "-------------------            A palavra-chave e  : ";
        if (desenha_palavra(palavra, palavra_chave, letra))
        {
            acertos++;
        }
        else
        {
            erros++;
        }

        cout << "\n\n\n";
        cout << "Insira uma letra  \t\t\t\t  Letras Usadas : ";
        letras_usadas(letras, contador);
        cout << "\n";
        cin >> letra;
        letras[contador] = toupper(letra);
        contador++;

    } while (toupper(sentinela) != 'N');
}

bool desenha_palavra(char palavra[], char palavra_chave[], char letra)
{
    int verificador = 0;

    for (int i = 0; i <= strlen(palavra); i++)
    {
        if (toupper(palavra[i]) == toupper(letra))
        {
            palavra_chave[i] = toupper(letra);
            cout << palavra_chave[i];
            verificador++;
        }
        else
        {
            cout << palavra_chave[i];
        }
    }

    if (verificador == 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}
bool censura_palavra(char palavra_chave[])
{

    for (int i = 0; i < strlen(palavra_chave); i++)
    {
        palavra_chave[i] = '_';
    }
}
bool letras_usadas(char letras[], int contador)
{
    for (int i = 0; i < contador; i++)
    {
        cout << letras[i];
    }
}
void seleciona_palavra(char banco[3][30], char palavra[], char palavra_chave[])
{
    int num;
    srand(time(NULL));
    num = rand() % 3;

    for (int i = 0; i < 30; i++)
    {
        palavra[i] = banco[num][i];
        palavra_chave[i] = banco[num][i];
    }
}
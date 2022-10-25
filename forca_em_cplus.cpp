#include <iostream>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

bool letras_usadas(char letras[], int contador);
bool desenha_palavra(char palavra[], char palavra_chave[], char letra);
bool censura_palavra(char palavra_chave[]);

int main()
{
    int contador = 0;
    char letras[26];
    char letra;
    char palavra[30] = "Banana";
    char palavra_chave[30] = "Banana";

    censura_palavra(palavra_chave);

    do
    {
        if (desenha_palavra(palavra, palavra_chave, letra))
        {
            cout << "Insira uma letra  //  Letras Usadas :";
            letras_usadas(letras, contador);
            cout << "\n";
            cin >> letra;
            letras[contador] = letra;
            contador++;
            system("cls");
        }
        else
        {
            cout << "Insira uma letra  //  Letras Usadas :";
            letras_usadas(letras, contador);
            cout << "\n";
            cin >> letra;
            letras[contador] = letra;
            contador++;
            system("cls");
        }
    } while (true);
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
    cout << "\n";

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
        palavra_chave[i] = '-';
    }
}
bool letras_usadas(char letras[], int contador)
{
    for (int i = 0; i < contador; i++)
    {
        cout << letras[i];
    }
}
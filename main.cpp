#include <iostream>
#include <string>
#include "math.h"
#include <iomanip>
using namespace std;

double media(double vet[], int tam)
{
    double m = 0;

    if (tam == 1)
    {
        return vet[0];
    }

    if (tam == 0)
    {
        return 0;
    }

    for (int i = 0; i < tam; i++)
    {
        m += (vet[i] / tam);
    }

    return m;
}

double dpAmostral(double vet[], int tam)
{
    double m = media(vet, tam);
    double dpA = 0;
    for (int i = 0; i < tam; i++)
    {
        dpA += ((vet[i] - m) * (vet[i] - m)) / (tam - 1);
    }

    return sqrt(dpA);
}

double dpMedia(double vet[], int tam)
{
    double dpa = dpAmostral(vet, tam);

    return dpa / sqrt(tam);
}

double converteString(string s)
{
    int indice = -1;
    int j = 0;
    int contador = 0;
    double n = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] == ',' || s[i] == '.')
        {
            indice = i;
            break;
        }
        contador++;
    }

    if (indice == -1)
    {
        while (s[j] != '\0')
        {
            n += (s[j] - 48) * pow(10, contador - j - 1);
            j++;
        }
        return n;
    }

    for (int i = indice - 1; i >= 0; i--)
    {
        if (s[i] >= '0' && s[i] <= '9')
            n += (s[i] - 48) * pow(10, indice - i - 1);
    }

    for (int i = indice + 1; s[i] != '\0'; i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
            n += (s[i] - 48) * pow(10, indice - i);
    }

    return n;
}

int main()
{
    string s;
    int status = 1;
    int n = 0;
    cout << setprecision(12) << "Bem vindo ao auxilio emergencial\n";
    double *vet;

    while (status == 1)
    {
        cout << "\nInsira a quantidade de valores: ";
        cin >> n;
        vet = new double[n];
        cout << endl
             << "Insira os valores" << endl;

        for (int i = 0; i < n; i++)
        {
            cin >> s;
            vet[i] = converteString(s);
        }

        cout << endl
             << "Valores inseridos: \n";

        for (int i = 0; i < n; i++)
        {
            cout << vet[i] << endl;
        }

        cout << endl
             << "Media aritmetica: " << media(vet, n) << endl;

        cout << endl
             << "Desvio padrao da amostra: " << dpAmostral(vet, n) << endl;

        cout << endl
             << "Desvio padrao da media: " << dpMedia(vet, n) << endl;

        delete[] vet;

        status=0;
        cout << endl
             << "Insira 0 para sair ou 1 para reiniciar: ";

        cin >> status;
    }

    return 0;
}

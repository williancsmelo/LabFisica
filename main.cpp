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
    int n;
    cout << setprecision(12) << "Bem vindo ao auxilio emergencial\nDigite a quantidade de valores: ";
    cin >> n;
    double *vet = new double[n];

    for (int i = 0; i < n; i++)
    {
        cin >> s;
        vet[i] = converteString(s);
    }

    cout << "\nValores convertidos: \n";

    for (int i = 0; i < n; i++)
    {
        cout << vet[i] << endl;
    }

    cout << endl
         << "A media dos valores eh: " << media(vet, n) << endl;

    cout << endl
         << "O desvio padrão da amostra eh: " << dpAmostral(vet, n) << endl;

    cout << endl
         << "O desvio padrão da media eh: " << dpMedia(vet, n) << endl;

    cout << "\n Pressione qualquer tecla para fechar!" <<endl;
    cin >> s;
    return 0;
}

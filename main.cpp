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

void desviopadrao()
{
    string s;
    int status = 1;
    int n = 0;
    double *vet;

    while (status == 1)
    {
        cout << "\n\nInsira a quantidade de valores: ";
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
}

void mmqCalc(double x[], double y[], int n)
{
    double somaX = 0;
    double somaX2 = 0;
    double somaY = 0;
    double somaY2 = 0;
    double somaXY = 0;
    double aux1 = 0;
    double aux2 = 0;
    double a = 0;
    double b = 0;
    double r = 0;
    double ua = 0;
    double ub = 0;
    for (int i = 0; i < n; i++)
    {
        somaX += x[i];
        somaX2 += x[i] * x[i];
        somaY2 += y[i] * y[i];
        somaY += y[i];
        somaXY += x[i] * y[i];
    }

    ///coeficiente a
    aux1 = (somaX * somaY) - (n * somaXY);
    aux2 = (somaX * somaX) - (n * somaX2);
    a = aux1 / aux2;

    ///coeficiente b
    aux1=(somaX*somaXY)-(somaX2*somaY);
    aux2=(somaX*somaX)-(n*somaX2);
    b = aux1/aux2;

    ///coeficiente de correlação linear
    aux1 = (n*somaXY)-(somaX*somaY);
    aux2 = ((n*somaX2)-somaX*somaX)*((n*somaY2)-(somaY*somaY));
    r = aux1/sqrt(aux2);

    ///incerteza de a
    aux1 = 1-r*r;
    aux2 = (n-2)*(r*r);
    ua = abs(a)*sqrt(aux1/aux2);

    ///incerteza de b
    aux1 = somaX2/n;
    ub = ua*sqrt(aux1);

    cout << "\nOs pares ordenados inseridos foram:\n";

    for(int i=0;i<n;i++)
    {
        cout << "( " << x[i] << " ; " << y[i] << " ) \n";
    }

    cout << "\nCoeficiente angular (a) = " << a;
    cout << "\nIncerteza de a (u(a)) = " << ua;
    cout << "\n\nCoeficiente linear (b) = " << b;
    cout << "\nIncerteza de b (u(b)) = " << ub;
    cout << "\n\nCoeficiente de correlacao linear (r) = " << r << endl << endl;
}

void mmq()
{
    string s;
    int n;
    int status = 1;
    while(status == 1)
    {
        cout << "\n\nInsira o numero de pares ordenados: ";
        cin >> n;

        double *x = new double[n];
        double *y = new double[n];

        cout << "\n\nInsira os valores de x: \n";
        for (int i = 0; i < n; i++)
        {
            cin >> s;
            x[i]=converteString(s);
        }

        cout << "\n\nInsira os valores de y: \n";
        for (int i = 0; i < n; i++)
        {
            cin >> s;
            y[i]=converteString(s);
        }

        mmqCalc(x,y,n);

        delete [] x;
        delete [] y;

        status=0;
        cout << endl
             << "Insira 0 para sair ou 1 para reiniciar: ";

        cin >> status;
    }

    return;
}

int main()
{
    int choice = 0;

    cout << setprecision(12) << "\t\t\tMenu \n";
    cout << "1 - Desvio padrao da media ou desvio padrao amostral\n";
    cout << "2 - Regressao Linear (MMQ)\n";
    cout << "3 - Sair\n";

    cin >> choice;

    switch (choice)
    {
    case 1:
        desviopadrao();
        break;
    case 2:
        mmq();
        break;
    default:
        break;
    }

    return 0;
}

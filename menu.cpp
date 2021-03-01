#include <stdio.h>

#include "Methods/ModifiedNewthonRaphson.cpp"
#include "Methods/NewtonRaphson.cpp"
#include "Methods/Secant.cpp"

float getFunction(float d);
float getDerivative(float x);
float getDerivativeOfDerivative(float x);
float getA();

int n;
float a;
float ERROR;

int iterMax;

int main()
{
    float d0 = 0.5;
    float d1 = 1;

    int option = 0;

    do
    {
        system("clear||cls");
        cout << "\n******** MÉTODOS NUMÉRICOS ********\n";
        cout << "\t1. Newton-Raphson\n";
        cout << "\t2. Newton Modificado\n";
        cout << "\t3. Secante\n";
        cout << "\t4. Quadro comparativo\n";
        cout << "\t0. Sair\n";

        cout << "\nEscolha uma opcao: ";
        cin >> option;

        if (option == 0)
        {
            return 0;
        }

        system("clear||cls");
        cout << "Infome o valor de n: ";
        cin >> n;

        if (n <= 0)
        {
            exit(1);
        }

        cout << "Infome o valor do erro: ";
        cin >> ERROR;
        cout << "Interações Máximas: ";
        cin >> iterMax;

        if (option == 1) // NewtonRaphson
        {
            NewtonRaphson nr;
            int i = 0;
            while (i < n)
            {
                cout << "\nInfome o valor de a: ";
                cin >> a;
                nr.setInput(d0, iterMax, ERROR);
                nr.calculateRoot(getFunction, getDerivative);
                i++;
            }
        }

        else if (option == 2) // NewtonRaphson Modificado
        {
            ModifiedNewtonRaphson mnr;
            int i = 0;

            while (i < n)
            {
                cout << "\nInfome o valor de a: ";
                cin >> a;
                mnr.setInput(d0, iterMax);
                mnr.setError(ERROR);
                mnr.calculateRoot(getFunction, getDerivative, getDerivativeOfDerivative);
                i++;
            }
        }

        else if (option == 3) // Secante
        {
            Secant secant;
            int i = 0;

            while (i < n)
            {
                cout << "\nInfome o valor de a: ";
                cin >> a;
                secant.setInput(d0, d1, iterMax, ERROR);
                secant.calculateRoot(getFunction);
                i++;
            }
        }

        else if (option == 4) // Quadro Comparativo
        {
            NewtonRaphson nr;
            ModifiedNewtonRaphson mnr;
            Secant secant;

            int i = 0;

            while (i < n)
            {
                cout << "\nInfome o valor de a: ";
                cin >> a;

                mnr.setInput(d0, iterMax);
                mnr.setError(ERROR);
                mnr.calculateRoot(getFunction, getDerivative, getDerivativeOfDerivative);
                cout << "\n";

                nr.setInput(d0, iterMax, ERROR);
                nr.calculateRoot(getFunction, getDerivative);
                cout << "\n";

                secant.setInput(d0, d1, iterMax, ERROR);
                secant.calculateRoot(getFunction);
                cout << "\n";

                system("clear||cls");

                cout << "========= QUADRO COMPARATIVO =========\n";

                cout << "\n=== Newton Raphson ===\n"
                     << setprecision(10)
                     << "Raiz = " << nr.raiz
                     << "\t| Iterações = " << nr.qtdInter << '\n'
                     << "F(x) = " << getFunction(nr.raiz)
                     << "\t| E(R) = " << ERROR / nr.raiz << '\n'
                     << "Erro = " << ERROR
                     << "\t| D0 = " << d0
                     << endl;

                cout << "\n === Newton Raphson Modificado ===\n"
                     << setprecision(10)
                     << "Raiz = " << mnr.raiz
                     << "\t| Iterações = " << mnr.qtdInter << '\n'
                     << "F(x) = " << getFunction(mnr.raiz)
                     << "\t| E(R) = " << ERROR / mnr.raiz << '\n'
                     << "Erro = " << ERROR
                     << "\t| D0 = " << d0
                     << endl;

                cout << "\n=== Secante ===\n"
                     << setprecision(10)
                     << "Raiz = " << secant.raiz
                     << "\t| Iterações  = " << secant.qtdInter << '\n'
                     << "F(x) = " << getFunction(secant.raiz)
                     << "\t| E(R) = " << ERROR / secant.raiz << '\n'
                     << "Erro = " << ERROR
                     << "\t| D0 = " << d0
                     << endl;

                i++;
            }
        }

        cout << "\nDeseja continuar?\n 1 - continuar    0 - sair" << endl;
        cin >> option;

    } while (option != 0);

    return 0;
}

float getA()
{
    return a;
}

// Funções a serem utilizadas pelos métodos

float getFunction(float d)
{
    float a = getA();
    return (a * pow(euler, d)) - (4 * pow(d, 2));
}

float getDerivative(float x)
{
    return (pow(euler, x) - 8 * x);
}

float getDerivativeOfDerivative(float x)
{
    return (pow(euler, x) - 8);
}
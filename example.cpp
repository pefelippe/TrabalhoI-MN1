#include <stdio.h>
#include "Methods/Secant.cpp"



#define ERROR 0.0005
#define DECIMAL_PRECISION 4

float getFunction(float x);
float getFunction2(float x);
float getDerivative(float x);

int main()
{
    float x0 = 0;
    float x1 = 1;
    int iterMax = 10;

    int option = 0;

    do {
        system("clear||cls");
        cout << "\n******** MÉTODOS NUMÉRICOS ********\n";
        cout << "\n";

        cout << "\t1. Newton-Raphson\n";
        cout << "\t2. Newton Modificado\n";
        cout << "\t3. Secante\n";
        cout << "\t4. Todos os metodos\n";
        cout << "\t5. Quadro comparativo\n";
        cout << "\t0. Sair\n";

        cout << "\nEscolha uma opcao: "; cin >> option;
        cout << "\n";
        
        Secant secant;

        switch (option) {
            case 3:
                secant.setInput(x0, x1, iterMax);
                secant.setError(ERROR);
                secant.calculateRoot(getFunction2);
                break;
            default:
                break;
        }

        cout << "\nDeseja continuar? 1 - continuar    0 - sair" << endl;
        cin >> option;
        
    } while(option != 0);

    return 0;
}

float getFunction(float x)
{
    return (2 * cos(x) - (pow(euler, x) / 2));
}

float getFunction2(float x)
{
    return (pow(x, 3) - (9 * x) + 3);
}

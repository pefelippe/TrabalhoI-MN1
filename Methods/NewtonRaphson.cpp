#include "../Headers/NewtonRaphson.hpp"

void NewtonRaphson::setInput(float x, int iter, float newError)
{
    x0 = x;
    intermax = iter;
    error = newError;
}

void NewtonRaphson::calculateRoot(const function<float(float)> &f, const function<float(float)> &g)
{
    cout << "============ METODO NEWTON =============\n";

    if (abs(f(x0)) < error)
    {
        raiz = x0;
        cout << "Raíz: " << x0 << endl;
        return;
    }

    int k = 1;
    while (true)
    {

        x1 = x0 - (f(x0) / g(x0));

        cout << "Iteration " << k
             << "\t| x = " << x1
             << "\t| f(x) = " << f(x1) << endl;

        if ((abs(f(x1) < error) || abs(x1 - x0) < error) || k >= intermax)
        {
            raiz = x1;
            qtdInter = k;
            cout << "Root: " << x1 << endl;
            return;
        }

        x0 = x1;
        k++;
    }
}
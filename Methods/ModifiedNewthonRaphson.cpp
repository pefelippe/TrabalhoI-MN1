#include "../Headers/ModifiedNewthonRaphson.hpp"

void ModifiedNewtonRaphson::setError(float newError)
{
    error = newError;
}

void ModifiedNewtonRaphson::setInput(float a, int iter)
{
    x0 = a;
    iterMax = iter;
}

void ModifiedNewtonRaphson::calculateRoot(const function<float(float)> &f, const function<float(float)> &g, const function<float(float)> &h)
{
    double u, v;
    cout << "============ METODO NEWTON MODIFICADO =============\n";

    if (abs(f(x0) < error))
    {
        raiz = x0;
        cout << "| Raíz: " << x0 << endl;
        return;
    }

    int k = 1;
    while (true)
    {
        u = f(x0) / g(x0);
        v = pow(g(x0), 2) - f(x0) * h(x0);

        x1 = x0 - u / v;

        cout << "| k: " << k
             << " | x1 = " << setprecision(15) << x1
             << " | f(x1) = " << f(x1) << endl;

        if (abs(f(x1)) < error || abs(x1 - x0) < error || k >= iterMax)
        {
            raiz = x1;
            qtdInter = k;
            cout << "| Raíz: " << setprecision(15) << x1 << endl;
            return;
        }

        x0 = x1;
        k++;
    }
}

#include "../Headers/Secant.hpp"

void Secant::setError(float newError)
{
    e1 = newError;
    e2 = newError;
}

void Secant::setInput(float a, float b, int iter)
{
    x0 = a;
    x1 = b;
    iterMax = iter;
}

void Secant::calculateRoot(const function<float(float)> &f)
{
    cout << "============ METODO DA SECANTE =============\n";

    if (fabs(f(x0)) < e1)
    {
        cout << "| Raíz: " << x0 << endl;
        return;
    }

    if (fabs(f(x1)) < e1 || fabs(x1 - x0) < e2)
    {
        cout << "| Raíz: " << x1 << endl;
        return;
    }

    int k = 1;

    while (true)
    {
        x2 = x1 - f(x1) / (f(x1) - f(x0)) * (x1 - x0);

        cout << "| k: " << k << " | x2: " << x2 << " | f(x2): " << f(x2) << " |\n";

        if (fabs(f(x2)) < e1 || fabs(x2 - x1) < e2 || k >= iterMax)
        {
            cout << "| Raíz: " << x2 << endl;
            return;
        }

        x0 = x1;
        x1 = x2;
        k = k + 1;
    }
}
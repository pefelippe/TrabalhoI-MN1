#include "../Headers/NewtonRaphson.hpp"

void NewtonRaphson::setError(float newError)
{
    error = newError;
}

void NewtonRaphson::calculateRoot(const function<float(float)> &f, const function<float(float)> &g)
{
    int interMax;

    cout << "X0: ";
    cin >> x0;
    cout << "Intermax: ";
    cin >> interMax;

    if (abs(f(x0) < error))
    {
        cout << "Root: " << x0 << endl;
        return;
    }

    int k = 1;

    do
    {
        x1 = x0 - f0 / g0;

        cout << "Iteration " << k
             << "\t| x = " << x1
             << "\t| f(x) = " << f(x1) << endl;

        if (abs(f(x1)) < error || abs(x1 - x0) < error || k > interMax)
        {
            cout << "Root: " << x1 << endl;
            return;
        }

        x0 = x1;
        k++;

    } while (true);
}

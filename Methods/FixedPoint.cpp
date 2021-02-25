#include "../Headers/FixedPoint.hpp"

void FixedPoint::setError(float newError)
{
    e = newError;
}

void FixedPoint::calculateRoot(const function<float(float)> &f, const function<float(float)> &g)
{
    int k = 1, interMax;

    cout << "X0: ";
    cin >> x0;

    cout << "InterMax: ";
    cin >> interMax;

    do
    {
        x1 = g(x0);
        cout << "Interaction: " << k
             << "\t| x1 = " << x1
             << "\t| x0 = " << x0
             << "\t| f(x1) = " << f(x1) << endl;

        k++;

        if (k > interMax)
        {
            cout << "Error.";
            return;
        }

        x0 = x1;

    } while (fabs(f(x1)) > e);

    cout << "Root: " << x1 << endl;

    return;
}

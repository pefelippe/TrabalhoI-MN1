#include "../Headers/FalsePosition.hpp"

void FalsePosition::setError(float newError)
{
    error = newError;
}

void FalsePosition::calculateRoot(const function<float(float)> &f)
{
    int i = 1;

    cout << "x0: ";
    cin >> x0;
    cout << "x1: ";
    cin >> x1;
    cout << "Error: " << error << endl;
    cout << "\n";

    f0 = f(x0);
    f1 = f(x1);

    // checkGuesses(f0,f1)
    if (f0 * f1 > 0.0)
    {
        printf("ERROR.\n");
        return;
    }

    do
    {
        x2 = x0 - (x0 - x1) * f0 / (f0 - f1);
        f2 = f(x2);

        cout << "| Iteration " << i << ":\t| x0 = " << x0 << ":\t| x1 = " << x1 << ":\t| x2 = " << x1 << x2 << " | f(x2) = " << f(x2) << " |" << endl;

        if (f0 * f2 < 0)
        {
            x1 = x2;
            f1 = f2;
        }
        else
        {
            x0 = x2;
            f0 = f2;
        }

        i++;

    } while (fabs(f2) > error);

    cout << "\n Root :" << x2 << endl;

    return;
}

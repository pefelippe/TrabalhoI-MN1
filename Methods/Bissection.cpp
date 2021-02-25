#include "../Headers/Bissection.hpp"

void Bissection::setError(float newError)
{
    error = newError;
}

void Bissection::calculateRoot(const function<float(float)> &f)
{
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
        cout << "ERROR." << endl;
        return;
    }

    int i = 1;
    do
    {
        x = (x0 + x1) / 2;

        cout << "| Iteration " << i << ":\t| x = " << x << " | f(x) = " << f(x) << " |" << endl;
        (f0 * f(x) < 0) ? x1 = x : x0 = x;

        i = i + 1;

    } while (fabs(f(x)) > error);

    cout << "\n Root : " << x << endl;
}

#include "../Common/Definitions.hpp"

class ModifiedNewtonRaphson
{
    // x0: d0
    // x1: raíz aproximada
    // x1, f1, g0, h0: utilizado internamente

public:
    float x0, x1, error, relativeError, iterMax, raiz, qtdInter = 0;
    void setError(float newError);
    void setInput(float a, int iterMax);
    void calculateRoot(const function<float(float)> &f, const function<float(float)> &g, const function<float(float)> &h);
};
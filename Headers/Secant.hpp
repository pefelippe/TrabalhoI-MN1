#include "../Common/Definitions.hpp"

class Secant
{

public:
    float x0, x1, x2, f0, f1, f2, e1, e2, iterMax, n, a, raiz, qtdInter = 0;
    bool input = true;
    void setError(float newError);
    void setInput(float x0, float b, int iterMax, float newError);
    void calculateRoot(const function<float(float)> &func);
};
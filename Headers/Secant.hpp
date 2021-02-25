#include "../Common/Definitions.hpp"

class Secant
{
    float x0, x1, x2, f0, f1, f2, e1, e2, iterMax;
    bool input = true;

public:
    void setError(float newError);
    void setInput(float a, float b, int iterMax);
    void calculateRoot(const function<float(float)> &func);
};
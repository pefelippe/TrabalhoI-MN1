#include "../Common/Definitions.hpp"

class NewtonRaphson
{

public:
    float x0, x1, error, intermax, raiz, qtdInter = 0;
    void setInput(float x, int iter, float newError);
    void calculateRoot(const function<float(float)> &f, const function<float(float)> &g);
};
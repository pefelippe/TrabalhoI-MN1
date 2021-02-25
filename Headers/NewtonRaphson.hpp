#include "../Common/Definitions.hpp"

class NewtonRaphson
{
    float x0, x1, f0, f1, g0, error;

public:
    void setError(float newError);
    void calculateRoot(const function<float(float)> &f, const function<float(float)> &g);
};
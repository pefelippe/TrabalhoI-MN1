#include "../Common/Definitions.hpp"

class FixedPoint
{
    float x0, x1, e;

public:
    void setError(float newError);
    void calculateRoot(const function<float(float)> &f, const function<float(float)> &g);
};
#include "../Common/Definitions.hpp"

class FalsePosition
{
    float x0, x1, x2, f0, f1, f2, error;

public:
    void setError(float newError);
    void calculateRoot(const function<float(float)> &func);
};
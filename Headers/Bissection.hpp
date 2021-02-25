#include "../Common/Definitions.hpp"

class Bissection
{
    float x0, x1, x, f0, f1, error, f;

public:
    void setError(float newError);
    void calculateRoot(const function<float(float)> &f);
};
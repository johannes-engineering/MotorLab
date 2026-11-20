#include "integration.hpp"

namespace motorlab::maths
{
    double integrate(double step_size, double previous_integral, double derivative) {
        return previous_integral + step_size * derivative;
    }
}
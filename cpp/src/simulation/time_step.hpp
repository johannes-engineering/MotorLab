#pragma once

#include <cmath>
#include <stdexcept>

namespace motorlab::simulation
{
    inline void validateTimeStep(double dt_s)
    {
        if (!std::isfinite(dt_s) || dt_s <= 0.0)
        {
            throw std::invalid_argument{"dt_s must be finite and positive"};
        }
    }
}

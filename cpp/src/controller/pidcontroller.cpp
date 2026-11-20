#include <algorithm>
#include "pidcontroller.hpp"

namespace motorlab
{
    double PIDController::step(double dt_s, double error)
    {
        double integral_old{ integral };

        integral = integral_old + dt_s * error;
        double derivative{ (error - previous_error) / dt_s };

        previous_error = error;

        return std::clamp(
            k_p * error + k_i * integral + k_d * derivative,
            min_output,
            max_output
            );
    }
}
#include "PIDController.hpp"
#include "time_step.hpp"

#include <algorithm>
#include <stdexcept>

namespace motorlab
{
    PIDController::PIDController(
        double k_p, double k_i, double k_d,double min_output, double max_output
        )
        : k_p{ k_p }
        , k_i{ k_i }
        , k_d{ k_d }
        , min_output { min_output }
        , max_output{ max_output }
    {
        if (min_output > max_output)
        {
            throw std::invalid_argument{"min_output must be smaller than max_output"};
        }
    }

    double PIDController::step(double dt_s, double error)
    {
        simulation::validateTimeStep(dt_s);

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

#pragma once

namespace motorlab
{
    /**
     * Discrete PID controller with configurable output limits.
     * Computes the control output from the error (setpoint minus measured value)
     * using proportional, integral, and derivative terms.
     *
     * @note Output limits do not prevent integral windup.
     */
    class PIDController
    {
    public:
        const double k_p;        ///< Proportional gain
        const double k_i;        ///< Integral gain
        const double k_d;        ///< Derivative gain
        const double min_output; ///< Lower control output limit
        const double max_output; ///< Upper control output limit

        /**
         * Creates a PID controller with zero initial integral and previous error.
         *
         * @param k_p Proportional gain.
         * @param k_i Integral gain.
         * @param k_d Derivative gain.
         * @param min_output Lower control output limit.
         * @param max_output Upper control output limit.
         * @pre min_output <= max_output.
         */
        explicit PIDController(double k_p, double k_i, double k_d, double min_output, double max_output)
            : k_p{ k_p }, k_i{ k_i }, k_d{ k_d }, min_output { min_output }, max_output{ max_output } {}

        /**
         * Computes the limited control output and updates the integral state.
         *
         * @param dt_s Positive time elapsed since the previous step, in seconds.
         * @param error Current setpoint minus measured value.
         * @return Control output clamped to [min_output, max_output].
         * @pre dt_s > 0.
         */
        double step(double dt_s, double error);

    private:
        double previous_error{}; ///< Error from the previous step
        double integral{};       ///< Accumulated error integral
    };
}

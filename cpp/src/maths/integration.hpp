#pragma once

namespace motorlab::maths
{
    /**
     * Performs one explicit Euler integration step.
     *
     * @param step_size Integration step, e.g. elapsed time in seconds.
     * @param previous_integral Integral value at the start of the step.
     * @param derivative Derivative at the start of the step.
     * @return Updated integral value.
     */
    double integrate(double step_size, double previous_integral, double derivative);
}

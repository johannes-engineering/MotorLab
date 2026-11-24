#include "DCMotor.hpp"
#include "Load.hpp"
#include "integration.hpp"
#include "time_step.hpp"

namespace motorlab
{
    void DCMotor::step(double dt_s, double input_voltage_V, Load load)
    {
        simulation::validateTimeStep(dt_s);

        // copy and store previous values so they can be safely overwritten
        double armature_current_old_A{ armature_current_A };
        double velocity_old_rad_s{ velocity_rad_s };
        double position_old_rad{ position_rad };

        // calculate acceleration from torque balance
        acceleration_rad_s2 =
            (params.torque_constant_Nm_A * armature_current_old_A -
            load.torque_Nm -
            params.viscous_friction_coefficient_Nms_rad * velocity_old_rad_s) /
            (load.inertia_kgm2 + params.inertia_kgm2);

        // calculate velocity
        velocity_rad_s = motorlab::maths::integrate(
            dt_s,
            velocity_old_rad_s,
            acceleration_rad_s2
            );

        // calculate position
        position_rad = motorlab::maths::integrate(
            dt_s,
            position_old_rad,
            velocity_old_rad_s
            );

        // calculate current from Kirchhoff's voltage law
        armature_current_A = motorlab::maths::integrate(
            dt_s,
            armature_current_old_A,
            (input_voltage_V -
            params.armature_resistance_Ohm * armature_current_old_A -
            params.back_emf_constant_Vs_rad * velocity_old_rad_s) /
            params.armature_inductance_H
            );
    }
}

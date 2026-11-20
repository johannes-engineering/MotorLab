#include "DCMotor.hpp"
#include "Load.hpp"
#include "pidcontroller.hpp"

#include <iostream>
#include <format>

/**
 * Runs a temporary manual playground simulation of PID motor speed control.
 */
void initial_test();

int main()
{
	initial_test();
	
	return 0;
}

void initial_test()
{
	// Initialize a DC motor using example parameters
	motorlab::DCMotorParameters params {
		.inertia_kgm2 { 1.0e-4 },
		.armature_resistance_Ohm { 2.0 },
		.armature_inductance_H { 2.0e-3 },
		.torque_constant_Nm_A { 0.05 },
		.back_emf_constant_Vs_rad { 0.05 },
		.viscous_friction_coefficient_Nms_rad { 1.0e-5 },
		.nominal_voltage_V { 12.0 }
	};
	motorlab::DCMotor dcMotor { params };
	motorlab::Motor& motor { dcMotor };

	// Initialize an example PID controller
	motorlab::PIDController pidController {
		10, 0.5, 0,
		-params.nominal_voltage_V, params.nominal_voltage_V
	};
	const double setpoint{ 50 };

	// Initialize a load without any impact for completeness
	motorlab::Load load { 0, 0 };

	// Run the simulation in a loop using a fixed step size
	double dt_s{ 0.001 };
	for (int i { 0 }; i < 2000; ++i)
	{
		motor.step(dt_s,
			pidController.step(dt_s, setpoint - motor.getVelocity_rad_s()), load);
		std::cout << "T: " << std::format(
			      "Time: {:8.3f},\tAcc: {:8.3f},\tVel: {:8.3f},\tPos: {:8.3f}\n",
			      dt_s * (i + 1),
			      motor.getAcceleration_rad_s2(),
			      motor.getVelocity_rad_s(),
			      motor.getPosition_rad()
			      );
	}

	std::cin.get();
}

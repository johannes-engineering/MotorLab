#pragma once

namespace motorlab
{
	/**
	 * Electrical and mechanical parameters of a DC motor.
	 */
	struct DCMotorParameters
	{
		double inertia_kgm2 {}; ///< Rotor moment of inertia in kg*m^2
		double armature_resistance_Ohm {}; ///< Armature resistance in ohms
		double armature_inductance_H {}; ///< Armature inductance in henries
		double torque_constant_Nm_A {}; ///< Torque per armature current in N*m/A
		double back_emf_constant_Vs_rad {}; ///< Back EMF per angular velocity in V*s/rad
		double viscous_friction_coefficient_Nms_rad {}; ///< Viscous friction coefficient in N*m*s/rad
		double nominal_voltage_V {}; ///< Rated armature voltage in volts
	};
}

#pragma once

namespace motorlab
{
	/**
	 * External mechanical load referred to the motor shaft.
	 */
	struct Load
	{
		double inertia_kgm2 {}; ///< Load moment of inertia in kg*m^2
		double torque_Nm {};    ///< Load torque in N*m, subtracted from motor torque
	};
}

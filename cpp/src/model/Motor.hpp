#pragma once
#include "Load.hpp"

namespace motorlab
{
	/**
	 * Base interface for motor models with rotational state.
	 */
	class Motor
	{
	public:
		virtual ~Motor() = default;

		/**
		 * Advances the motor state by one simulation step.
		 *
		 * @param dt_s Positive simulation time step in seconds.
		 * @param input_voltage_V Applied motor voltage in volts.
		 * @param load External mechanical load referred to the motor shaft.
		 * @pre dt_s > 0.
		 */
		virtual void step(double dt_s, double input_voltage_V, Load load) = 0;

		auto getAcceleration_rad_s2() const { return acceleration_rad_s2; }
		auto getVelocity_rad_s() const { return velocity_rad_s; }
		auto getPosition_rad() const { return position_rad; }

	protected:

		double acceleration_rad_s2{}; ///< Angular acceleration in rad/s^2
		double velocity_rad_s{};      ///< Angular velocity in rad/s
		double position_rad{};        ///< Angular position in radians
	};
}

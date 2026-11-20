#pragma once
#include "Motor.hpp"
#include "DCMotorParameters.hpp"
#include "Load.hpp"

namespace motorlab {

	/**
	 * DC motor model with electrical and rotational dynamics.
	 * Advances armature current, angular velocity, and angular position.
	 */
	class DCMotor : public Motor
	{
	public:
		/**
		 * Creates a DC motor with zero initial current and mechanical state.
		 *
		 * @param params Electrical and mechanical motor parameters.
		 */
		explicit DCMotor(DCMotorParameters params) : params(params) {}

		/**
		 * Advances the electrical and mechanical state by one simulation step.
		 *
		 * @param dt_s Positive simulation time step in seconds.
		 * @param input_voltage_V Applied armature voltage in volts.
		 * @param load External load inertia and resisting torque.
		 * @pre dt_s > 0.
		 * @pre params.armature_inductance_H > 0.
		 * @pre params.inertia_kgm2 + load.inertia_kgm2 > 0.
		 */
		void step(double dt_s, double input_voltage_V, Load load) override;

	private:
		const DCMotorParameters params; ///< Motor parameters
		double armature_current_A{}; ///< Armature current in amperes
	};
}

#include "DCMotor.hpp"
#include "DCMotorParameters.hpp"

#include <gtest/gtest.h>
#include <stdexcept>

class DCMotorTest : public testing::Test
{
protected:
    DCMotorTest()
        : dcMotor{motorlab::DCMotorParameters{
            .inertia_kgm2 = 1.0e-4,
            .armature_resistance_Ohm = 2.0,
            .armature_inductance_H = 2.0e-3,
            .torque_constant_Nm_A = 0.05,
            .back_emf_constant_Vs_rad = 0.05,
            .viscous_friction_coefficient_Nms_rad = 1.0e-5,
            .nominal_voltage_V = 12.0
        }}
    {}

    motorlab::DCMotor dcMotor;
};

TEST_F(DCMotorTest, InputZeroNoMovement)
{
    constexpr motorlab::Load load { 0.0, 0.0 };

    dcMotor.step(1.0, 0.0, load);

    EXPECT_DOUBLE_EQ(0.0, dcMotor.getAcceleration_rad_s2());
    EXPECT_DOUBLE_EQ(0.0, dcMotor.getVelocity_rad_s());
    EXPECT_DOUBLE_EQ(0.0, dcMotor.getPosition_rad());
}

TEST_F(DCMotorTest, InvalidStepSizeLeavesMotorStateUnchanged)
{
    constexpr motorlab::Load load { 0.0, 0.0 };
    for (int step = 0; step < 3; ++step)
    {
        dcMotor.step(0.001, 12.0, load);
    }

    const double acceleration = dcMotor.getAcceleration_rad_s2();
    const double velocity = dcMotor.getVelocity_rad_s();
    const double position = dcMotor.getPosition_rad();

    EXPECT_THROW(dcMotor.step(0.0, 12.0, load), std::invalid_argument);
    EXPECT_DOUBLE_EQ(acceleration, dcMotor.getAcceleration_rad_s2());
    EXPECT_DOUBLE_EQ(velocity, dcMotor.getVelocity_rad_s());
    EXPECT_DOUBLE_EQ(position, dcMotor.getPosition_rad());
}

TEST_F(DCMotorTest, LoadTorqueAcceleratesCombinedInertia)
{
    constexpr motorlab::Load load { .inertia_kgm2 = 1.0e-4, .torque_Nm = 0.02 };

    dcMotor.step(0.001, 0.0, load);

    EXPECT_DOUBLE_EQ(-100.0, dcMotor.getAcceleration_rad_s2());
}

TEST_F(DCMotorTest, UnloadedStartupAtNominalVoltage)
{
    constexpr motorlab::Load load { 0.0, 0.0 };

    dcMotor.step(0.001, 12.0, load);
    EXPECT_DOUBLE_EQ(0.0, dcMotor.getVelocity_rad_s());

    dcMotor.step(0.001, 12.0, load);
    EXPECT_DOUBLE_EQ(3000.0, dcMotor.getAcceleration_rad_s2());
    EXPECT_DOUBLE_EQ(3.0, dcMotor.getVelocity_rad_s());
}

TEST_F(DCMotorTest, MoveForward)
{
    constexpr motorlab::Load load { 0.0, 0.0 };

    for (int step = 0; step < 3; ++step)
    {
        dcMotor.step(0.001, 12.0, load);
    }

    EXPECT_GT(dcMotor.getAcceleration_rad_s2(), 0.0);
    EXPECT_GT(dcMotor.getVelocity_rad_s(), 0.0);
    EXPECT_GT(dcMotor.getPosition_rad(), 0.0);
}

TEST_F(DCMotorTest, MoveBackward)
{
    constexpr motorlab::Load load { 0.0, 0.0 };

    for (int step = 0; step < 3; ++step)
    {
        dcMotor.step(0.001, -12.0, load);
    }

    EXPECT_LT(dcMotor.getAcceleration_rad_s2(), 0.0);
    EXPECT_LT(dcMotor.getVelocity_rad_s(), 0.0);
    EXPECT_LT(dcMotor.getPosition_rad(), 0.0);
}

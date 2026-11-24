#include "PIDController.hpp"

#include <stdexcept>
#include <limits>
#include <gtest/gtest.h>

TEST(PIDControllerTest, MinOutputGreaterMaxOutputThrowsError)
{
    EXPECT_THROW((
        motorlab::PIDController{1.0, 1.0, 1.0, 100.0, -100.0}
        ), std::invalid_argument);
}

TEST(PIDControllerTest, MinOutputEqualsMaxOutput)
{
    motorlab::PIDController pid {
        2.0, 0.0, 0.0, 5.0, 5.0
    };

    EXPECT_DOUBLE_EQ(5.0, pid.step(0.001, 3.0));
    EXPECT_DOUBLE_EQ(5.0, pid.step(0.001, -3.0));
}

TEST(PIDControllerTest, OnlyProportionalGain)
{
    motorlab::PIDController pid {
        2.0, 0.0, 0.0, -100.0, 100.0
    };

    EXPECT_DOUBLE_EQ(4.0, pid.step(0.001, 2.0));
}

TEST(PIDControllerTest, OnlyIntegralGain)
{
    motorlab::PIDController pid {
        0.0, 1.0, 0.0, -100.0, 100.0
    };

    EXPECT_DOUBLE_EQ(1.0, pid.step(0.5, 2.0));
    EXPECT_DOUBLE_EQ(2.0, pid.step(0.5, 2.0));
}

TEST(PIDControllerTest, OnlyDerivativeGain)
{
    motorlab::PIDController pid {
        0.0, 0.0, 1.0, -100.0, 100.0
    };

    EXPECT_DOUBLE_EQ(4.0, pid.step(0.5, 2.0));
    EXPECT_DOUBLE_EQ(0.0, pid.step(0.5, 2.0));
}

TEST(PIDControllerTest, AllGains)
{
    motorlab::PIDController pid {
        1.0, 2.0, 3.0, -100.0, 100.0
    };

    EXPECT_DOUBLE_EQ(16.0, pid.step(0.5, 2.0));
    EXPECT_DOUBLE_EQ(14.0, pid.step(0.5, 3.0));
}

TEST(PIDControllerTest, OutputLimitation)
{
    motorlab::PIDController pid {
        100.0, 0.0, 0.0, -100.0, 150.0
    };

    EXPECT_DOUBLE_EQ(150.0, pid.step(0.5, 2.0));
    EXPECT_DOUBLE_EQ(-100.0, pid.step(0.5, -2.0));
}

TEST(PIDControllerTest, InvalidStepSizeThrowsError)
{
    motorlab::PIDController pid {
        1.0, 1.0, 1.0, -100.0, 100.0
    };

    EXPECT_THROW(pid.step(0.0, 1.0), std::invalid_argument);
    EXPECT_THROW(pid.step(-1.0, 1.0), std::invalid_argument);
    EXPECT_THROW(pid.step(std::numeric_limits<double>::quiet_NaN(), 1.0),
                 std::invalid_argument);
    EXPECT_THROW(pid.step(std::numeric_limits<double>::infinity(), 1.0),
                 std::invalid_argument);
}
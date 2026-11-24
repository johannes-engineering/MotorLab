find_package(GTest CONFIG REQUIRED)
include(GoogleTest)

add_executable(MotorLabTest)

target_sources(MotorLabTest
    PRIVATE
        controller/PIDController_test.cpp
        model/DCMotor_test.cpp
)

target_link_libraries(MotorLabTest
    PRIVATE
        Controller
        ModelLib
        GTest::gtest_main
)

gtest_discover_tests(MotorLabTest)

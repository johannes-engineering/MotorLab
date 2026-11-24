add_library(ModelLib)

target_sources(ModelLib
    PRIVATE
        DCMotor.cpp
        
    PUBLIC
        FILE_SET HEADERS
        FILES
            Motor.hpp
            DCMotor.hpp
			DCMotorParameters.hpp
            Load.hpp
)

target_link_libraries(ModelLib
		PRIVATE
		    Maths
		    Simulation
)

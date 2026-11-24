add_library(Controller)

target_sources(Controller
    PRIVATE
        PIDController.cpp

    PUBLIC
        FILE_SET HEADERS
        FILES
            PIDController.hpp
)

target_link_libraries(Controller PRIVATE Simulation)

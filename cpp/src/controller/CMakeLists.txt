add_library(Controller)

target_sources(Controller
    PRIVATE
        pidcontroller.cpp

    PUBLIC
        FILE_SET HEADERS
        FILES
            pidcontroller.hpp
)

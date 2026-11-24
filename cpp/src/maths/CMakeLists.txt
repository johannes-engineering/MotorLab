add_library(Maths)

target_sources(Maths
    PRIVATE
        integration.cpp
        
    PUBLIC
        FILE_SET HEADERS
        FILES
		    integration.hpp
)

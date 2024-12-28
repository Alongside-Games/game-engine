#=======================================================================================================================
target_include_directories(${PROJECT_NAME} PUBLIC ..)
 target_precompile_headers(${PROJECT_NAME} PUBLIC headers.hpp)
#=======================================================================================================================
target_sources(${PROJECT_NAME} PRIVATE platform.cpp window_manager.cpp window_size.cpp input_manager.cpp input_states.cpp)
#=======================================================================================================================
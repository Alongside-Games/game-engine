#=======================================================================================================================
target_compile_definitions(${PROJECT_NAME} PRIVATE WIN32_LEAN_AND_MEAN VC_EXTRALEAN)
 target_precompile_headers(${PROJECT_NAME} PRIVATE headers.hpp)
     target_link_libraries(${PROJECT_NAME} PRIVATE user32 gdi32)
            target_sources(${PROJECT_NAME} PRIVATE window.cpp window_events.cpp context.cpp context_functions.cpp factory.cpp input.cpp)
#=======================================================================================================================
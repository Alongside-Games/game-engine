#include "graphics.hpp"

namespace core
{
    auto Graphics::init() -> void
    {
        init_opengl_state();
    }

    auto Graphics::init_opengl_state() -> void
    {
        opengl::FunctionsLoader::init_core();
        opengl::FunctionsLoader::init_extensions();
    }
}
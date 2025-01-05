#include "commands.hpp"

namespace opengl
{
    auto Commands::viewport(const int32_t x, const int32_t y, const int32_t width, const int32_t height) -> void
    {
        glViewport(x, y, width, height);
    }

    auto Commands::clear(const float r, const float g, const float b, const float a) -> void
    {
        glClearColor(r, g, b, a);
    }

    auto Commands::clear(const uint32_t flags) -> void
    {
        glClear(flags);
    }
}
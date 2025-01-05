#pragma once

namespace opengl
{
    class Commands
    {
    public:
        static auto viewport(int32_t x, int32_t y, int32_t width, int32_t height) -> void;

        static auto clear(float r, float g, float b, float a = 1.0f) -> void;
        static auto clear(uint32_t flags)                            -> void;

        Commands() = delete;
    };
}
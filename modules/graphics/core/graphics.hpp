#pragma once

namespace core
{
    class Graphics
    {
    public:
        static auto init()              -> void;
        static auto init_opengl_state() -> void;
    };
}
#pragma once

namespace opengl
{
    class FunctionsLoader
    {
    public:
        static auto init_core()       -> void;
        static auto init_extensions() -> void;
    };
}
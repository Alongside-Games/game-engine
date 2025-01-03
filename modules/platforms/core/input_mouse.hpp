#pragma once

namespace core
{
    class InputMouse
    {
    public:
        std::function<void(int32_t)> on_scroll { };

        int32_t cursor_x { };
        int32_t cursor_y { };
    };
}
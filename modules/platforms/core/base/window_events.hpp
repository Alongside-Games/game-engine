#pragma once

namespace core::base
{
    class WindowEvents
    {
    public:
        std::function<void(int32_t, int32_t)> on_size;
        std::function<void()>                 on_close;

        virtual auto update() const -> void = 0;
    };
}
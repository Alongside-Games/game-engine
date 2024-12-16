#pragma once

#include "core/base/window_events.hpp"

namespace windows
{
    class WindowEvents final : public core::base::WindowEvents
    {
    public:
        static auto update(HWND hwnd, uint32_t msg, WPARAM wparam, LPARAM lparam) -> LRESULT;
               auto update()    const -> void override;
    };
}
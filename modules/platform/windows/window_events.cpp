#include "window_events.hpp"

namespace windows
{
    auto WindowEvents::update(const HWND hwnd, const uint32_t msg, const WPARAM wparam, const LPARAM lparam) -> LRESULT
    {
        return DefWindowProc(hwnd, msg, wparam, lparam);
    }

    auto WindowEvents::update() const -> void
    {
    }
}
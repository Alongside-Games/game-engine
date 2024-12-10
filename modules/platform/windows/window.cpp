#include "window.hpp"
#include "window_events.hpp"

namespace windows
{
    auto Window::init(const core::configuration::window& config) -> void
    {
        #pragma region preparation

        MONITORINFO monitor_info
        {
            .cbSize = sizeof(MONITORINFO)
        };

        GetMonitorInfo(MonitorFromWindow(hwnd, MONITOR_DEFAULTTOPRIMARY), &monitor_info);

        auto frame_x = 0;
        auto frame_y = 0;
        auto frame_w = monitor_info.rcMonitor.right  - monitor_info.rcMonitor.left;
        auto frame_h = monitor_info.rcMonitor.bottom - monitor_info.rcMonitor.top;

        register_id(config.title);

        #pragma region style

        styles |= config.flag & core::window_mode ? WS_OVERLAPPEDWINDOW : WS_POPUP;

        #pragma endregion
        #pragma region position and size

        if (config.flag & core::window_mode)
        {
            RECT window_frame
            {
                .right  = config.size.width(),
                .bottom = config.size.height()
            };

            AdjustWindowRectEx(&window_frame, styles, false, extras);

            const auto window_w = window_frame.right  - window_frame.left;
            const auto window_h = window_frame.bottom - window_frame.top;

            #pragma region align in the middle of the screen

            if (config.flag & core::window_centered)
            {
                frame_x = (frame_w - window_w) / 2;
                frame_y = (frame_h - window_h) / 2;
            }

            #pragma endregion

            frame_w = window_w;
            frame_h = window_h;
        }

        #pragma endregion
        #pragma endregion

        hwnd = CreateWindowEx(extras, MAKEINTATOM(id), config.title.c_str(), styles, frame_x, frame_y, frame_w, frame_h, nullptr, nullptr, GetModuleHandle(nullptr), nullptr);
    }

    auto Window::release() const -> void
    {
        DestroyWindow(hwnd);

        unregister_id();
    }

    auto Window::show() const -> void
    {
        ShowWindow(hwnd, SW_SHOW);
    }

    auto Window::handle() const -> std::any
    {
        return hwnd;
    }

    auto Window::register_id(const std::string& title) -> void
    {
        const WNDCLASSEX classex
        {
            .cbSize        = sizeof(WNDCLASSEX),
            .style         = CS_HREDRAW | CS_VREDRAW | CS_OWNDC,
            .lpfnWndProc   = WindowEvents::update,
            .hInstance     = GetModuleHandle(nullptr),
            .hCursor       = LoadCursor(nullptr, IDC_ARROW),
            .lpszClassName = title.c_str()
        };

        id = RegisterClassEx(&classex);
    }

    auto Window::unregister_id() const -> void
    {
        UnregisterClass(MAKEINTATOM(id), GetModuleHandle(nullptr));
    }
}
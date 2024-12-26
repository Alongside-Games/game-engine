#include "window.hpp"
#include "window_events.hpp"

namespace windows
{
    auto Window::init(const core::configuration::window& config) -> void
    {
        #pragma region preparation

        #pragma region monitor

        MONITORINFO monitor_info
        {
            .cbSize = sizeof(MONITORINFO)
        };

        GetMonitorInfo(MonitorFromWindow(hwnd, MONITOR_DEFAULTTOPRIMARY), &monitor_info);

        auto frame_x = 0;
        auto frame_y = 0;
        auto frame_w = monitor_info.rcMonitor.right  - monitor_info.rcMonitor.left;
        auto frame_h = monitor_info.rcMonitor.bottom - monitor_info.rcMonitor.top;

        #pragma endregion
        #pragma region instance and id

        instance = GetModuleHandle(nullptr);

        const WNDCLASSEX classex
        {
            .cbSize        = sizeof(WNDCLASSEX),
            .style         = CS_HREDRAW | CS_VREDRAW | CS_OWNDC,
            .lpfnWndProc   = WindowEvents::update,
            .hInstance     = instance,
            .hCursor       = LoadCursor(nullptr, IDC_ARROW),
            .lpszClassName = config.title.c_str()
        };

        id = RegisterClassEx(&classex);

        #pragma endregion
        #pragma region position and size

  style |=  config.flag & core::window_mode ? WS_OVERLAPPEDWINDOW : WS_POPUP;
        if (config.flag & core::window_mode)
        {
            RECT window_frame
            {
                .right  = config.size.width(),
                .bottom = config.size.height()
            };

            AdjustWindowRectEx(&window_frame, style, false, extra);

            frame_w = window_frame.right  - window_frame.left;
            frame_h = window_frame.bottom - window_frame.top;

            #pragma region center of the screen

            if (config.flag & core::window_centered)
            {
                frame_x = (monitor_info.rcMonitor.right  - monitor_info.rcMonitor.left - frame_w) / 2;
                frame_y = (monitor_info.rcMonitor.bottom - monitor_info.rcMonitor.top  - frame_h) / 2;
            }

            #pragma endregion
        }

        #pragma endregion

        #pragma endregion

        hwnd = CreateWindowEx(extra, MAKEINTATOM(id), config.title.c_str(), style, frame_x, frame_y, frame_w, frame_h, nullptr, nullptr, instance, nullptr);
    }

    auto Window::release() const -> void
    {
        DestroyWindow(hwnd);

        UnregisterClass(MAKEINTATOM(id), instance);
    }

    auto Window::title(const std::string& title) -> void
    {
        SetWindowText(hwnd, title.c_str());
    }

    auto Window::show() const -> void
    {
        ShowWindow(hwnd, SW_SHOW);
    }

    auto Window::handle() const -> std::any
    {
        return hwnd;
    }
}
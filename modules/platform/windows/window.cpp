#include "window.hpp"
#include "window_events.hpp"

namespace windows
{
    auto Window::create(const core::configuration::window& config) -> void
    {
        #pragma region preparation

        register_id(config.title);

        #pragma endregion

        hwnd = CreateWindowEx(extras, MAKEINTATOM(id), config.title.c_str(), styles, 0, 0, config.size.width(), config.size.height(), nullptr, nullptr, GetModuleHandle(nullptr), nullptr);
    }

    auto Window::destroy() const -> void
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
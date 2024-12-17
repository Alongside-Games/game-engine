#include "window_events.hpp"

#include "core/window_manager.hpp"

namespace windows
{
    auto WindowEvents::update(const HWND hwnd, const uint32_t msg, const WPARAM wparam, const LPARAM lparam) -> LRESULT
    {
        const auto& window_manager = core::WindowManager::instance();

        switch (msg)
        {
            case WM_CLOSE:
            {
                window_manager.window_events().on_close();
                return 0;
            }
            case WM_SIZE:
            {
                const auto width  = LOWORD(lparam);
                const auto height = HIWORD(lparam);

                if (window_manager.window_events().on_size)
                    window_manager.window_events().on_size(width, height);

                return 0;
            }
            #pragma region default
            case WM_SYSCOMMAND:
            {
                switch (wparam)
                {
                    case SC_SCREENSAVE:
                    case SC_MONITORPOWER:
                    {
                        return 0;
                    }
                    default: break;
                }
            }
            case WM_ERASEBKGND:
            {
                return 1;
            }
            default: return DefWindowProc(hwnd, msg, wparam, lparam);
            #pragma  endregion
        }
    }

    auto WindowEvents::update() const -> void
    {
        MSG msg;

        while (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
        {
            if (msg.message == WM_QUIT)
            {
                break;
            }

            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }
}
#include "window_events.hpp"

#include "core/input_manager.hpp"
#include "core/window_manager.hpp"

namespace windows
{
    auto WindowEvents::update(const HWND hwnd, const uint32_t msg, const WPARAM wparam, const LPARAM lparam) -> LRESULT
    {
        #pragma region references

        const auto& events = core::WindowManager::instance().events();
        const auto&  input = core::InputManager::instance();

        #pragma endregion

        switch (msg)
        {
            case WM_CLOSE:
            {
                events.on_close();
                return 0;
            }
            case WM_SIZE:
            {
                const auto width  = LOWORD(lparam);
                const auto height = HIWORD(lparam);

                if (events.on_size)
                    events.on_size(width, height);

                return 0;
            }
            case WM_KEYUP:
            case WM_KEYDOWN:

            case WM_SYSKEYUP:
            case WM_SYSKEYDOWN:
            {
                const auto key   =        wparam;
                const auto state = HIWORD(lparam) & KF_UP ? false : true;

                input.update(key, state);

                break;
            }

            case WM_LBUTTONUP:   { input.update(VK_LBUTTON, false); break; }
            case WM_MBUTTONUP:   { input.update(VK_MBUTTON, false); break; }
            case WM_RBUTTONUP:   { input.update(VK_RBUTTON, false); break; }

            case WM_LBUTTONDOWN: { input.update(VK_LBUTTON,  true); break; }
            case WM_MBUTTONDOWN: { input.update(VK_MBUTTON,  true); break; }
            case WM_RBUTTONDOWN: { input.update(VK_RBUTTON,  true); break; }

            case WM_MOUSEWHEEL:
            {
                const auto delta = GET_WHEEL_DELTA_WPARAM(wparam) / WHEEL_DELTA;

                input.scroll(delta);
            }

            case WM_MOUSEMOVE:
            {
                input.mouse().cursor_x = LOWORD(lparam);
                input.mouse().cursor_y = HIWORD(lparam);
            }

            #pragma region default
            case WM_ERASEBKGND:
            {
                return 1;
            }
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
                break;
            }
            default: break;
            #pragma  endregion
        }

        return DefWindowProc(hwnd, msg, wparam, lparam);
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
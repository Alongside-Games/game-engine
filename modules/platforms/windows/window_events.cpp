#include "window_events.hpp"

#include "core/input_manager.hpp"
#include "core/window_manager.hpp"

namespace windows
{
    auto WindowEvents::update(const HWND hwnd, const uint32_t msg, const WPARAM wparam, const LPARAM lparam) -> LRESULT
    {
        #pragma region references

        const auto& events = core::WindowManager::instance().events();

              auto&  input = core::InputManager::instance().input();
              auto& states = core::InputManager::instance().states();

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
            case WM_KEYDOWN: // TODO merge this
            case WM_SYSKEYDOWN:
            {
                if (input.codes.contains(wparam))
                {
                    states.update(input.codes[wparam], true);
                }
                break;
            }
            case WM_KEYUP:
            case WM_SYSKEYUP:
            {
                if (input.codes.contains(wparam))
                {
                    states.update(input.codes[wparam], false);
                }
                break;
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
#include "context.hpp"

namespace windows
{
    auto Context::init(const std::any& handle, const core::configuration::context& config) -> void
    {
    }

    auto Context::init(const std::any& handle) -> void
    {
        constexpr PIXELFORMATDESCRIPTOR pfd
        {
            .nSize   = sizeof(PIXELFORMATDESCRIPTOR),
            .dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER
        };
                            hdc  = GetDC(std::any_cast<HWND>(handle));
        if (!SetPixelFormat(hdc, ChoosePixelFormat(hdc, &pfd), &pfd))
        {
            std::exit(EXIT_FAILURE);
        }

        hrc = wglCreateContext(hdc);
                wglMakeCurrent(hdc, hrc);
    }

    auto Context::release() -> void
    {
          wglMakeCurrent(hdc, nullptr);
        wglDeleteContext(hrc);
    }

    auto Context::present() -> void
    {
        SwapBuffers(hdc);
    }
}
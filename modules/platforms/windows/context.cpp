#include "context.hpp"
#include "context_functions.hpp"
#include "context_macros.hpp"

namespace windows
{
    auto Context::init(const core::configuration::context& config, const std::any& handle) -> void
    {
        #pragma region pixel

        const int32_t pixel_attributes[]
        {
            pixel::draw_to_window, 1,
            pixel::support_opengl, 1,
            pixel::double_buffer,  1,
            pixel::acceleration,   pixel::full_acceleration,
            pixel::type,           pixel::rgba,
            pixel::color_bits,     32,
            pixel::depth_bits,     24,
            pixel::stencil_bits,   8,
            pixel::srgb_buffer,    1,
            pixel::samples_buffer, config.samples > 0 ? 1 : 0,
            pixel::samples_buffer, config.samples,  0
        };
             int32_t format;                        hdc = GetDC(std::any_cast<HWND>(handle));
        if (uint32_t formats; !wglChoosePixelFormat(hdc,  pixel_attributes, nullptr, 1, &format, &formats) || !formats)
        {
            std::exit(EXIT_FAILURE);
        }
                                                     PIXELFORMATDESCRIPTOR    pfd;
        if (!DescribePixelFormat(hdc, format, sizeof(PIXELFORMATDESCRIPTOR), &pfd))
        {
            std::exit(EXIT_FAILURE);
        }

        if (!SetPixelFormat(hdc, format, &pfd))
        {
            std::exit(EXIT_FAILURE);
        }

        #pragma endregion
        #pragma region context

        const int32_t context_attributes[]
        {
            context::major_version, config.major_version,
            context::minor_version, config.minor_version,
            context::profile,       context::core_profile,
            context::flags,         context::no_error, 0
        };

        hrc = wglCreateContextAttribs(hdc, nullptr, context_attributes);
                       wglMakeCurrent(hdc, hrc);

        #pragma endregion
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
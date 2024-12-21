#pragma once

namespace windows
{
    namespace pixel
    {
        constexpr auto draw_to_window    = 0x2001;
        constexpr auto support_opengl    = 0x2010;
        constexpr auto double_buffer     = 0x2011;
        constexpr auto acceleration      = 0x2003;
        constexpr auto full_acceleration = 0x2027;
        constexpr auto type              = 0x2013;
        constexpr auto rgba              = 0x202b;
        constexpr auto color_bits        = 0x2014;
        constexpr auto depth_bits        = 0x2022;
        constexpr auto stencil_bits      = 0x2023;
        constexpr auto samples_buffer    = 0x2041;
        constexpr auto samples_per_pixel = 0x2042;
        constexpr auto srgb_buffer       = 0x20a9;
    }

    namespace context
    {
        constexpr auto major_version = 0x2091;
        constexpr auto minor_version = 0x2092;
        constexpr auto profile       = 0x9126;
        constexpr auto flags         = 0x2094;
        constexpr auto core_profile  = 0x00000001;
        constexpr auto no_error      = 0x00000008;
    }
}
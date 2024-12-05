#pragma once

#include "core/window_flags.hpp"
#include "core/window_size.hpp"

namespace core::configuration
{
    struct window
    {
        static constexpr auto default_title { "Game Engine" };

        std::string title   { default_title };
        window_size size    { };
        uint32_t    flags   { window_mode | window_centered };
    };
}
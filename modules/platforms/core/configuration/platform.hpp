#pragma once

#include "context.hpp"
#include "window.hpp"

namespace core::configuration
{
    struct platform
    {
        window  window  { };
        context context { };
    };
}
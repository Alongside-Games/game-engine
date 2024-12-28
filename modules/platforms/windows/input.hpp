#pragma once

#include "core/base/input.hpp"

namespace windows
{
    class Input final : public core::base::Input
    {
    public:
        auto init() -> void override;
    };
}
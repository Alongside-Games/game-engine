#pragma once

#include "core/base/context_functions.hpp"

namespace windows
{
    class ContextFunctions final : public core::base::ContextFunctions
    {
    public:
        auto init() -> void override;
    };
}
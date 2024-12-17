#pragma once

#include "core/configuration/context.hpp"

namespace core::base
{
    class Context
    {
    public:
        virtual auto init(const std::any& handle, const configuration::context& config) -> void = 0;
        virtual auto init(const std::any& handle)                                       -> void = 0;

        virtual auto release() -> void = 0;
        virtual auto present() -> void = 0;
    };
}
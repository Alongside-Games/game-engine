#pragma once

#include "base/factory.hpp"

namespace core
{
    class Platform
    {
    public:
        static auto init()                   -> void;
        static auto init_context_functions() -> void;

        static auto create_factory() -> std::unique_ptr<base::Factory>;
    };
}